#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstring>
#include <ostream>
#include <deque>

#include "PathFinder.h"
#include "PathFinderDef.h"
#include "PathFlowMap.hpp"
#include "PathHeatMap.hpp"
#include "PathLog.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/GeometricObjects.h"


#define PATHDEBUG 0

using namespace Bitwise;



const CMoveMath::BlockType squareMobileBlockBits = (CMoveMath::BLOCK_MOBILE | CMoveMath::BLOCK_MOVING | CMoveMath::BLOCK_MOBILE_BUSY);

// indexed by PATHOPT* bitmasks
static float3 PF_DIRECTION_VECTORS_3D[PATH_DIRECTIONS << 1];
static  float PF_DIRECTION_COSTS[PATH_DIRECTIONS << 1];



CPathFinder::CPathFinder()
	: IPathFinder(1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathFinder::InitDirectionVectorsTable() {
	for (int i = 0; i < (PATH_DIRECTIONS << 1); ++i) {
		PF_DIRECTION_VECTORS_3D[i].x = PF_DIRECTION_VECTORS_2D[i].x;
		PF_DIRECTION_VECTORS_3D[i].z = PF_DIRECTION_VECTORS_2D[i].y;
		PF_DIRECTION_VECTORS_3D[i].Normalize();
	}
}

void CPathFinder::InitDirectionCostsTable() {
	// note: PATH_NODE_SPACING should not affect these
	PF_DIRECTION_COSTS[PATHOPT_LEFT                ] =    1.0f;
	PF_DIRECTION_COSTS[PATHOPT_RIGHT               ] =    1.0f;
	PF_DIRECTION_COSTS[PATHOPT_UP                  ] =    1.0f;
	PF_DIRECTION_COSTS[PATHOPT_DOWN                ] =    1.0f;
	PF_DIRECTION_COSTS[PATHOPT_LEFT  | PATHOPT_UP  ] = 1.4142f;
	PF_DIRECTION_COSTS[PATHOPT_RIGHT | PATHOPT_UP  ] = 1.4142f;
	PF_DIRECTION_COSTS[PATHOPT_RIGHT | PATHOPT_DOWN] = 1.4142f;
	PF_DIRECTION_COSTS[PATHOPT_LEFT  | PATHOPT_DOWN] = 1.4142f;
}

const   int2* CPathFinder::GetDirectionVectorsTable2D() { return (&PF_DIRECTION_VECTORS_2D[0]); }
const float3* CPathFinder::GetDirectionVectorsTable3D() { return (&PF_DIRECTION_VECTORS_3D[0]); }



IPath::SearchResult CPathFinder::DoSearch(
	const MoveDef& moveDef,
	const CPathFinderDef& pfDef,
	const CSolidObject* owner
) {
	bool foundGoal = false;

	while (!openBlocks.empty() && (openBlockBuffer.GetSize() < maxBlocksToBeSearched)) {
		// Get the open square with lowest expected path-cost.
		PathNode* openSquare = const_cast<PathNode*>(openBlocks.top());
		openBlocks.pop();

		// check if this PathNode has become obsolete
		if (blockStates.fCost[openSquare->nodeNum] != openSquare->fCost)
			continue;

		// Check if the goal is reached.
		if (pfDef.IsGoal(openSquare->nodePos.x, openSquare->nodePos.y)) {
			mGoalBlockIdx = openSquare->nodeNum;
			mGoalHeuristic = 0.0f;
			foundGoal = true;
			break;
		}

		TestNeighborSquares(moveDef, pfDef, openSquare, owner);
	}

	if (foundGoal)
		return IPath::Ok;

	// could not reach goal within <maxBlocksToBeSearched> exploration limit
	if (openBlockBuffer.GetSize() >= maxBlocksToBeSearched)
		return IPath::GoalOutOfRange;

	// could not reach goal from this starting position if nothing to left to explore
	if (openBlocks.empty())
		return IPath::GoalOutOfRange;

	// should be unreachable
	return IPath::Error;
}

void CPathFinder::TestNeighborSquares(
	const MoveDef& moveDef,
	const CPathFinderDef& pfDef,
	const PathNode* square,
	const CSolidObject* owner
) {
	// early out
	if (!pfDef.WithinConstraints(square->nodePos.x, square->nodePos.y)) {
		blockStates.nodeMask[square->nodeNum] |= PATHOPT_CLOSED;
		dirtyBlocks.push_back(square->nodeNum);
		return;
	}

	struct SqState {
		SqState() : blockedState(CMoveMath::BLOCK_NONE), speedMod(0.0f), inSearch(false) {}
		CMoveMath::BlockType blockedState;
		float speedMod;
		bool inSearch;
	};

	SqState ngbStates[PATH_DIRECTIONS];

	// precompute structure-blocked for all neighbors
	for (unsigned int dir = 0; dir < PATH_DIRECTIONS; dir++) {
		const int2 ngbSquareCoors = square->nodePos + PF_DIRECTION_VECTORS_2D[ PathDir2PathOpt(dir) ];
		const int ngbSquareIdx = BlockPosToIdx(ngbSquareCoors);

		if ((unsigned)ngbSquareCoors.x >= nbrOfBlocks.x || (unsigned)ngbSquareCoors.y >= nbrOfBlocks.y)
			continue;

		if (blockStates.nodeMask[ngbSquareIdx] & (PATHOPT_CLOSED | PATHOPT_BLOCKED)) //FIXME
			continue;

		// very time expensive call
		SqState& sqState = ngbStates[dir];
		sqState.blockedState = CMoveMath::IsBlockedNoSpeedModCheck(moveDef, ngbSquareCoors.x, ngbSquareCoors.y, owner);

		if (sqState.blockedState & CMoveMath::BLOCK_STRUCTURE) {
			blockStates.nodeMask[ngbSquareIdx] |= PATHOPT_CLOSED;
			dirtyBlocks.push_back(ngbSquareIdx);
			continue; // early-out (20% chance)
		}

		// hint: use posSpeedMod for PE! cause it assumes path costs are bidirectional and so it only saves one `cost` for left & right movement
		// hint2: not worth to put in front of the above code, it only has a ~2% chance (heavily depending on the map) to early-out
		if (!pfDef.dirIndependent) {
			sqState.speedMod = CMoveMath::GetPosSpeedMod(moveDef, ngbSquareCoors.x, ngbSquareCoors.y, PF_DIRECTION_VECTORS_3D[ PathDir2PathOpt(dir) ]);
		} else {
			sqState.speedMod = CMoveMath::GetPosSpeedMod(moveDef, ngbSquareCoors.x, ngbSquareCoors.y);
			// only close node if we're dirIndependent
			// otherwise, it's possible we'll be able to enter it from another direction.
			if (sqState.speedMod == 0.0f) {
				blockStates.nodeMask[ngbSquareIdx] |= PATHOPT_CLOSED;
				dirtyBlocks.push_back(ngbSquareIdx);
			}
		}
		if (sqState.speedMod != 0.0f) {
			sqState.inSearch = pfDef.WithinConstraints(ngbSquareCoors.x, ngbSquareCoors.y);
		}
	}

	const auto CAN_TEST_SQUARE_SM = [&](const int dir) { return (ngbStates[dir].speedMod != 0.0f); };
	const auto CAN_TEST_SQUARE_IS = [&](const int dir) { return (ngbStates[dir].inSearch); };

	// first test squares along the cardinal directions
	for (unsigned int dir: PATHDIR_CARDINALS) {
		if (!CAN_TEST_SQUARE_SM(dir))
			continue;

		const SqState& sqState = ngbStates[dir];
		const unsigned int opt = PathDir2PathOpt(dir);
		TestBlock(moveDef, pfDef, square, owner, opt, sqState.blockedState, sqState.speedMod);
	}

	// next test the diagonal squares
	//
	// don't search diagonally if there is a blocking object
	// (or blocking terrain!) in one of the two side squares
	// e.g. do not consider the edge (p, q) passable if X is
	// impassable in this situation:
	//   +---+---+
	//   | X | q |
	//   +---+---+
	//   | p | X |
	//   +---+---+
	//
	// *** IMPORTANT ***
	//
	// if either side-square is merely outside the constrained
	// area but the diagonal square is not, we do consider the
	// edge passable since we still need to be able to jump to
	// diagonally adjacent PE-blocks!
	//
	const auto TEST_DIAG_SQUARE = [&](const int BASE_DIR_X, const int BASE_DIR_Y, const int BASE_DIR_XY) {
		if (CAN_TEST_SQUARE_SM(BASE_DIR_XY) && (CAN_TEST_SQUARE_SM(BASE_DIR_X) && CAN_TEST_SQUARE_SM(BASE_DIR_Y))) {
			if (CAN_TEST_SQUARE_IS(BASE_DIR_XY) || (CAN_TEST_SQUARE_IS(BASE_DIR_X) && CAN_TEST_SQUARE_IS(BASE_DIR_Y))) {
				const unsigned int ngbOpt = PathDir2PathOpt(BASE_DIR_XY);
				const SqState& sqState = ngbStates[BASE_DIR_XY];
				TestBlock(moveDef, pfDef, square, owner, ngbOpt, sqState.blockedState, sqState.speedMod);
			}
		}
	};

	TEST_DIAG_SQUARE(PATHDIR_LEFT,  PATHDIR_UP,   PATHDIR_LEFT_UP   );
	TEST_DIAG_SQUARE(PATHDIR_RIGHT, PATHDIR_UP,   PATHDIR_RIGHT_UP  );
	TEST_DIAG_SQUARE(PATHDIR_LEFT,  PATHDIR_DOWN, PATHDIR_LEFT_DOWN );
	TEST_DIAG_SQUARE(PATHDIR_RIGHT, PATHDIR_DOWN, PATHDIR_RIGHT_DOWN);

	// mark this square as closed
	blockStates.nodeMask[square->nodeNum] |= PATHOPT_CLOSED;
	dirtyBlocks.push_back(square->nodeNum);
}

bool CPathFinder::TestBlock(
	const MoveDef& moveDef,
	const CPathFinderDef& pfDef,
	const PathNode* parentSquare,
	const CSolidObject* owner,
	const unsigned int pathOptDir,
	const unsigned int blockStatus,
	float speedMod
) {
	testedBlocks++;

	// initial calculations of the new block
	const int2 square = parentSquare->nodePos + PF_DIRECTION_VECTORS_2D[pathOptDir];
	const unsigned int sqrIdx = BlockPosToIdx(square);

	// bounds-check
	assert((unsigned)square.x < nbrOfBlocks.x);
	assert((unsigned)square.y < nbrOfBlocks.y);
	assert((blockStates.nodeMask[sqrIdx] & (PATHOPT_CLOSED | PATHOPT_BLOCKED)) == 0);
	assert((blockStatus & CMoveMath::BLOCK_STRUCTURE) == 0);
	assert(speedMod != 0.0f);

	if (pfDef.testMobile && moveDef.avoidMobilesOnPath && (blockStatus & squareMobileBlockBits)) {
		if (blockStatus & CMoveMath::BLOCK_MOBILE_BUSY) {
			speedMod *= moveDef.speedModMults[MoveDef::SPEEDMOD_MOBILE_BUSY_MULT];
		} else if (blockStatus & CMoveMath::BLOCK_MOBILE) {
			speedMod *= moveDef.speedModMults[MoveDef::SPEEDMOD_MOBILE_IDLE_MULT];
		} else { // (blockStatus & CMoveMath::BLOCK_MOVING)
			speedMod *= moveDef.speedModMults[MoveDef::SPEEDMOD_MOBILE_MOVE_MULT];
		}
	}

	const float heatCost  = (pfDef.testMobile) ? (PathHeatMap::GetInstance())->GetHeatCost(square.x, square.y, moveDef, ((owner != NULL)? owner->id: -1U)) : 0.0f;
	//const float flowCost  = (pfDef.testMobile) ? (PathFlowMap::GetInstance())->GetFlowCost(square.x, square.y, moveDef, pathOptDir) : 0.0f;
	const float extraCost = blockStates.GetNodeExtraCost(square.x, square.y, pfDef.synced);

	const float dirMoveCost = (1.0f + heatCost) * PF_DIRECTION_COSTS[pathOptDir];
	const float nodeCost = (dirMoveCost / speedMod) + extraCost;

	const float gCost = parentSquare->gCost + nodeCost;      // g
	const float hCost = pfDef.Heuristic(square.x, square.y); // h
	const float fCost = gCost + hCost;                       // f

	if (blockStates.nodeMask[sqrIdx] & PATHOPT_OPEN) {
		// already in the open set, look for a cost-improvement
		if (blockStates.fCost[sqrIdx] <= fCost)
			return true;

		blockStates.nodeMask[sqrIdx] &= ~PATHOPT_CARDINALS;
	}

	// if heuristic says this node is closer to goal than previous h-estimate, keep it
	if (!pfDef.exactPath && hCost < mGoalHeuristic) {
		mGoalBlockIdx = sqrIdx;
		mGoalHeuristic = hCost;
	}

	// store and mark this square as open (expanded, but not yet pulled from pqueue)
	openBlockBuffer.SetSize(openBlockBuffer.GetSize() + 1);
	assert(openBlockBuffer.GetSize() < MAX_SEARCHED_NODES_PF);

	PathNode* os = openBlockBuffer.GetNode(openBlockBuffer.GetSize());
		os->fCost   = fCost;
		os->gCost   = gCost;
		os->nodePos = square;
		os->nodeNum = sqrIdx;
	openBlocks.push(os);

	blockStates.SetMaxCost(NODE_COST_F, std::max(blockStates.GetMaxCost(NODE_COST_F), fCost));
	blockStates.SetMaxCost(NODE_COST_G, std::max(blockStates.GetMaxCost(NODE_COST_G), gCost));

	blockStates.fCost[sqrIdx] = os->fCost;
	blockStates.gCost[sqrIdx] = os->gCost;
	blockStates.nodeMask[sqrIdx] |= (PATHOPT_OPEN | pathOptDir);

	dirtyBlocks.push_back(sqrIdx);
	return true;
}


IPath::SearchResult CPathFinder::FinishSearch(const MoveDef& moveDef, const CPathFinderDef& pfDef, IPath::Path& foundPath) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** Helper function for AdjustFoundPath */
static inline void FixupPath3Pts(const MoveDef& moveDef, const float3 p1, float3& p2, const float3 p3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathFinder::SmoothMidWaypoint(const int2 testsqr, const int2 prevsqr, const MoveDef& moveDef, IPath::Path& foundPath, const float3 nextPoint) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/*
 * This function takes the current & the last 2 waypoints and detects when they form
 * a "soft" curve. And if so, it takes the mid waypoint of those 3 and smooths it
 * between the one before and the current waypoint (so the soft curve gets even smoother).
 * Hint: hard curves (e.g. `move North then West`) can't and will not smoothed. Only soft ones
 *  like `move North then North-West` can.
 */
void CPathFinder::AdjustFoundPath(const MoveDef& moveDef, IPath::Path& foundPath, const float3 nextPoint,
	std::deque<int2>& previous, int2 curquare) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
