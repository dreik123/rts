#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IPathFinder.h"
#include "PathFinderDef.h"
#include "PathLog.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Objects/SolidObject.h"
#include "System/Log/ILog.h"


// these give the changes in (x, z) coors
// when moving one step in given direction
//
// NOTE: the choices of +1 for LEFT and UP are *not* arbitrary
// (they are related to GetBlockVertexOffset) and also need to
// be consistent with the PATHOPT_* flags (for PathDir2PathOpt)
int2 IPathFinder::PE_DIRECTION_VECTORS[PATH_DIRECTIONS] = {
	int2(+1,  0), // PATHDIR_LEFT
	int2(+1, +1), // PATHDIR_LEFT_UP
	int2( 0, +1), // PATHDIR_UP
	int2(-1, +1), // PATHDIR_RIGHT_UP
	int2(-1,  0), // PATHDIR_RIGHT
	int2(-1, -1), // PATHDIR_RIGHT_DOWN
	int2( 0, -1), // PATHDIR_DOWN
	int2(+1, -1), // PATHDIR_LEFT_DOWN
};

//FIXME why not use PATHDIR_* consts and merge code with top one
int2 IPathFinder::PF_DIRECTION_VECTORS_2D[PATH_DIRECTIONS << 1] = {
	int2(0, 0),
	int2(+1 * PATH_NODE_SPACING,  0 * PATH_NODE_SPACING), // PATHOPT_LEFT
	int2(-1 * PATH_NODE_SPACING,  0 * PATH_NODE_SPACING), // PATHOPT_RIGHT
	int2(0, 0),                                           // PATHOPT_LEFT | PATHOPT_RIGHT
	int2( 0 * PATH_NODE_SPACING, +1 * PATH_NODE_SPACING), // PATHOPT_UP
	int2(+1 * PATH_NODE_SPACING, +1 * PATH_NODE_SPACING), // PATHOPT_LEFT | PATHOPT_UP
	int2(-1 * PATH_NODE_SPACING, +1 * PATH_NODE_SPACING), // PATHOPT_RIGHT | PATHOPT_UP
	int2(0, 0),                                           // PATHOPT_LEFT | PATHOPT_RIGHT | PATHOPT_UP
	int2( 0 * PATH_NODE_SPACING, -1 * PATH_NODE_SPACING), // PATHOPT_DOWN
	int2(+1 * PATH_NODE_SPACING, -1 * PATH_NODE_SPACING), // PATHOPT_LEFT | PATHOPT_DOWN
	int2(-1 * PATH_NODE_SPACING, -1 * PATH_NODE_SPACING), // PATHOPT_RIGHT | PATHOPT_DOWN
	int2(0, 0),
	int2(0, 0),
	int2(0, 0),
	int2(0, 0),
	int2(0, 0),
};



IPathFinder::IPathFinder(unsigned int _BLOCK_SIZE)
	: BLOCK_SIZE(_BLOCK_SIZE)
	, BLOCK_PIXEL_SIZE(BLOCK_SIZE * SQUARE_SIZE)
	, isEstimator(BLOCK_SIZE != 1)
	, mStartBlockIdx(0)
	, mGoalBlockIdx(0)
	, mGoalHeuristic(0.0f)
	, maxBlocksToBeSearched(0)
	, testedBlocks(0)
	, nbrOfBlocks(mapDims.mapx / BLOCK_SIZE, mapDims.mapy / BLOCK_SIZE)
	, blockStates(nbrOfBlocks, int2(mapDims.mapx, mapDims.mapy))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


IPathFinder::~IPathFinder()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void IPathFinder::ResetSearch()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


IPath::SearchResult IPathFinder::GetPath(
	const MoveDef& moveDef,
	const CPathFinderDef& pfDef,
	const CSolidObject* owner,
	float3 startPos,
	IPath::Path& path,
	const unsigned int maxNodes
) {
	startPos.ClampInBounds();

	// Clear the path
	path.path.clear();
	path.squares.clear();
	path.pathCost = PATHCOST_INFINITY;

	// initial calculations
	if (isEstimator) {
		maxBlocksToBeSearched = std::min(MAX_SEARCHED_NODES_PE - 8U, maxNodes);
	} else {
		maxBlocksToBeSearched = std::min(MAX_SEARCHED_NODES_PF - 8U, maxNodes);
	}
	mStartBlock.x  = startPos.x / BLOCK_PIXEL_SIZE;
	mStartBlock.y  = startPos.z / BLOCK_PIXEL_SIZE;
	mStartBlockIdx = BlockPosToIdx(mStartBlock);
	assert((unsigned)mStartBlock.x < nbrOfBlocks.x && (unsigned)mStartBlock.y < nbrOfBlocks.y);

	// Check cache (when there is one)
	int2 goalBlock;
	goalBlock.x = pfDef.goalSquareX / BLOCK_SIZE;
	goalBlock.y = pfDef.goalSquareZ / BLOCK_SIZE;
	const CPathCache::CacheItem* ci = GetCache(mStartBlock, goalBlock, pfDef.sqGoalRadius, moveDef.pathType, pfDef.synced);
	if (ci != nullptr) {
		path = ci->path;
		return ci->result;
	}

	// Start up a new search
	IPath::SearchResult result = InitSearch(moveDef, pfDef, owner);

	// If search was successful, generate new path
	if (result == IPath::Ok || result == IPath::GoalOutOfRange) {
		FinishSearch(moveDef, pfDef, path);

		// Save to cache
		AddCache(&path, result, mStartBlock, goalBlock, pfDef.sqGoalRadius, moveDef.pathType, pfDef.synced);

		if (LOG_IS_ENABLED(L_DEBUG)) {
			LOG_L(L_DEBUG, "==== %s: Search completed ====", (isEstimator) ? "PE" : "PF");
			LOG_L(L_DEBUG, "Tested blocks: %u", testedBlocks);
			LOG_L(L_DEBUG, "Open blocks: %u", openBlockBuffer.GetSize());
			LOG_L(L_DEBUG, "Path length: " _STPF_, path.path.size());
			LOG_L(L_DEBUG, "Path cost: %f", path.pathCost);
			LOG_L(L_DEBUG, "==============================");
		}
	} else {
		if (LOG_IS_ENABLED(L_DEBUG)) {
			LOG_L(L_DEBUG, "==== %s: Search failed! ====", (isEstimator) ? "PE" : "PF");
			LOG_L(L_DEBUG, "Tested blocks: %u", testedBlocks);
			LOG_L(L_DEBUG, "Open blocks: %u", openBlockBuffer.GetSize());
			LOG_L(L_DEBUG, "============================");
		}
	}

	return result;
}


// set up the starting point of the search
IPath::SearchResult IPathFinder::InitSearch(const MoveDef& moveDef, const CPathFinderDef& pfDef, const CSolidObject* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
