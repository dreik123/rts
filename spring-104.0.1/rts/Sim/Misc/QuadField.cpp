/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>

#include "QuadField.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/TeamHandler.h"

#ifndef UNIT_TEST
	#include "Sim/Features/Feature.h"
	#include "Sim/Projectiles/Projectile.h"
	#include "Sim/Units/Unit.h"
	#include "Sim/Weapons/PlasmaRepulser.h"
#endif

CR_BIND(CQuadField, (int2(1,1), 1))
CR_REG_METADATA(CQuadField, (
	CR_MEMBER(baseQuads),
	CR_MEMBER(numQuadsX),
	CR_MEMBER(numQuadsZ),
	CR_MEMBER(quadSizeX),
	CR_MEMBER(quadSizeZ),

	CR_IGNORED(tempUnits),
	CR_IGNORED(tempFeatures),
	CR_IGNORED(tempProjectiles),
	CR_IGNORED(tempSolids),
	CR_IGNORED(tempQuads)
))

CR_BIND(CQuadField::Quad, )
CR_REG_METADATA_SUB(CQuadField, Quad, (
	CR_MEMBER(units),
	CR_IGNORED(teamUnits),
	CR_MEMBER(features),
	CR_MEMBER(projectiles),
	CR_MEMBER(repulsers),

	CR_POSTLOAD(PostLoad)
))

CQuadField* quadField = NULL;


#ifndef UNIT_TEST
/*
void CQuadField::Resize(int quad_size)
{
	CQuadField* oldQuadField = quadField;
	CQuadField* newQuadField = new CQuadField(int2(mapDims.mapx, mapDims.mapy), quad_size);

	quadField = NULL;

	for (int zq = 0; zq < oldQuadField->GetNumQuadsZ(); zq++) {
		for (int xq = 0; xq < oldQuadField->GetNumQuadsX(); xq++) {
			const CQuadField::Quad& quad = oldQuadField->GetQuadAt(xq, zq);

			// COPY the object lists because the Remove* functions modify them
			// NOTE:
			//   teamUnits is updated internally by RemoveUnit and MovedUnit
			//
			//   if a unit exists in multiple quads in the old field, it will
			//   be removed from all of them and there is no danger of double
			//   re-insertion (important if new grid has higher resolution)
			const std::vector<CUnit*      > units       = quad.units;
			const std::vector<CFeature*   > features    = quad.features;
			const std::vector<CProjectile*> projectiles = quad.projectiles;

			for (auto it = units.cbegin(); it != units.cend(); ++it) {
				oldQuadField->RemoveUnit(*it);
				newQuadField->MovedUnit(*it); // handles addition
			}

			for (auto it = features.cbegin(); it != features.cend(); ++it) {
				oldQuadField->RemoveFeature(*it);
				newQuadField->AddFeature(*it);
			}

			for (auto it = projectiles.cbegin(); it != projectiles.cend(); ++it) {
				oldQuadField->RemoveProjectile(*it);
				newQuadField->AddProjectile(*it);
			}
		}
	}

	quadField = newQuadField;

	// do this last so pointer is never dangling
	delete oldQuadField;
}
*/
#endif


CQuadField::Quad::Quad()
{
#ifndef UNIT_TEST
	teamUnits.resize(teamHandler->ActiveAllyTeams());
	assert(teamUnits.capacity() == teamHandler->ActiveAllyTeams());
#endif
}

void CQuadField::Quad::PostLoad()
{
#ifndef UNIT_TEST
	for (CUnit* unit: units) {
		spring::VectorInsertUnique(teamUnits[unit->allyteam], unit, false);
	}
#endif
}

CQuadField::CQuadField(int2 mapDims, int quad_size)
{
	quadSizeX = quad_size;
	quadSizeZ = quad_size;
	numQuadsX = (mapDims.x * SQUARE_SIZE) / quad_size;
	numQuadsZ = (mapDims.y * SQUARE_SIZE) / quad_size;

	assert(numQuadsX >= 1);
	assert(numQuadsZ >= 1);
	assert((mapDims.x * SQUARE_SIZE) % quad_size == 0);
	assert((mapDims.y * SQUARE_SIZE) % quad_size == 0);

	baseQuads.resize(numQuadsX * numQuadsZ);
}


CQuadField::~CQuadField()
{
}


int2 CQuadField::WorldPosToQuadField(const float3 p) const
{
	return int2(
		Clamp(int(p.x / quadSizeX), 0, numQuadsX - 1),
		Clamp(int(p.z / quadSizeZ), 0, numQuadsZ - 1)
	);
}


int CQuadField::WorldPosToQuadFieldIdx(const float3 p) const
{
	return Clamp(int(p.z / quadSizeZ), 0, numQuadsZ - 1) * numQuadsX + Clamp(int(p.x / quadSizeX), 0, numQuadsX - 1);
}


#ifndef UNIT_TEST
void CQuadField::GetQuads(QuadFieldQuery& qfq, float3 pos, float radius)
{
	pos.AssertNaNs();
	pos.ClampInBounds();
	qfq.quads = tempQuads.GetVector();

	const int2 min = WorldPosToQuadField(pos - radius);
	const int2 max = WorldPosToQuadField(pos + radius);

	if (max.y < min.y || max.x < min.x)
		return;

	// qsx and qsz are always equal
	const float maxSqLength = (radius + quadSizeX * 0.72f) * (radius + quadSizeZ * 0.72f);

	for (int z = min.y; z <= max.y; ++z) {
		for (int x = min.x; x <= max.x; ++x) {
			assert(x < numQuadsX);
			assert(z < numQuadsZ);
			const float3 quadPos = float3(x * quadSizeX + quadSizeX * 0.5f, 0, z * quadSizeZ + quadSizeZ * 0.5f);
			if (pos.SqDistance2D(quadPos) < maxSqLength) {
				qfq.quads->push_back(z * numQuadsX + x);
			}
		}
	}

	return;
}


void CQuadField::GetQuadsRectangle(QuadFieldQuery& qfq, const float3& mins, const float3& maxs)
{
	mins.AssertNaNs();
	maxs.AssertNaNs();
	qfq.quads = tempQuads.GetVector();

	const int2 min = WorldPosToQuadField(mins);
	const int2 max = WorldPosToQuadField(maxs);

	if (max.y < min.y || max.x < min.x)
		return;

	for (int z = min.y; z <= max.y; ++z) {
		for (int x = min.x; x <= max.x; ++x) {
			assert(x < numQuadsX);
			assert(z < numQuadsZ);
			qfq.quads->push_back(z * numQuadsX + x);
		}
	}

	return;
}
#endif // UNIT_TEST


/// note: this function got an UnitTest, check the tests/ folder!
void CQuadField::GetQuadsOnRay(QuadFieldQuery& qfq, const float3& start, const float3& dir, float length)
{
	dir.AssertNaNs();
	start.AssertNaNs();
	qfq.quads = tempQuads.GetVector();

	const float3 to = start + (dir * length);
	const float3 invQuadSize = float3(1.0f / quadSizeX, 1.0f, 1.0f / quadSizeZ);

	const bool noXdir = (math::floor(start.x * invQuadSize.x) == math::floor(to.x * invQuadSize.x));
	const bool noZdir = (math::floor(start.z * invQuadSize.z) == math::floor(to.z * invQuadSize.z));

	// often happened special case
	if (noXdir && noZdir) {
		qfq.quads->push_back(WorldPosToQuadFieldIdx(start));
		assert(unsigned(qfq.quads->back()) < baseQuads.size());
		return;
	}

	// to prevent Div0
	if (noZdir) {
		int startX = Clamp<int>(start.x * invQuadSize.x, 0, numQuadsX - 1);
		int finalX = Clamp<int>(   to.x * invQuadSize.x, 0, numQuadsX - 1);
		if (finalX < startX) std::swap(startX, finalX);
		assert(finalX < numQuadsX);

		const int row = Clamp<int>(start.z * invQuadSize.z, 0, numQuadsZ - 1) * numQuadsX;

		for (unsigned x = startX; x <= finalX; x++) {
			qfq.quads->push_back(row + x);
			assert(unsigned(qfq.quads->back()) < baseQuads.size());
		}

		return;
	}

	// all other
	// hint at code: we iterate the affected z-range and then for each z we compute what xs are touched
	float startZuc = start.z * invQuadSize.z;
	float finalZuc =    to.z * invQuadSize.z;
	if (finalZuc < startZuc) std::swap(startZuc, finalZuc);
	int startZ = Clamp<int>(startZuc, 0, numQuadsZ - 1);
	int finalZ = Clamp<int>(finalZuc, 0, numQuadsZ - 1);
	assert(finalZ < quadSizeZ);
	const float invDirZ = 1.0f / dir.z;

	for (int z = startZ; z <= finalZ; z++) {
		float t0 = ((z    ) * quadSizeZ - start.z) * invDirZ;
		float t1 = ((z + 1) * quadSizeZ - start.z) * invDirZ;
		if ((startZuc < 0 && z == 0) || (startZuc >= numQuadsZ && z == finalZ)) {
			t0 = ((startZuc    ) * quadSizeZ - start.z) * invDirZ;
		}
		if ((finalZuc < 0 && z == 0) || (finalZuc >= numQuadsZ && z == finalZ)) {
			t1 = ((finalZuc + 1) * quadSizeZ - start.z) * invDirZ;
		}
		t0 = Clamp(t0, 0.f, length);
		t1 = Clamp(t1, 0.f, length);

		unsigned startX = Clamp<int>((dir.x * t0 + start.x) * invQuadSize.x, 0, numQuadsX - 1);
		unsigned finalX = Clamp<int>((dir.x * t1 + start.x) * invQuadSize.x, 0, numQuadsX - 1);
		if (finalX < startX) std::swap(startX, finalX);
		assert(finalX < numQuadsX);

		const int row = Clamp(z, 0, numQuadsZ - 1) * numQuadsX;

		for (unsigned x = startX; x <= finalX; x++) {
			qfq.quads->push_back(row + x);
			assert(unsigned(qfq.quads->back()) < baseQuads.size());
		}
	}

	return;
}


#ifndef UNIT_TEST
void CQuadField::MovedUnit(CUnit* unit)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, unit->pos, unit->radius);

	// compare if the quads have changed, if not stop here
	if (qfQuery.quads->size() == unit->quads.size()) {
		if (std::equal(qfQuery.quads->begin(), qfQuery.quads->end(), unit->quads.begin())) {
			return;
		}
	}

	for (const int qi: unit->quads) {
		spring::VectorErase(baseQuads[qi].units, unit);
		spring::VectorErase(baseQuads[qi].teamUnits[unit->allyteam], unit);
	}

	for (const int qi: *qfQuery.quads) {
		spring::VectorInsertUnique(baseQuads[qi].units, unit, false);
		spring::VectorInsertUnique(baseQuads[qi].teamUnits[unit->allyteam], unit, false);
	}

	unit->quads = std::move(*qfQuery.quads);
}

void CQuadField::RemoveUnit(CUnit* unit)
{
	for (const int qi: unit->quads) {
		spring::VectorErase(baseQuads[qi].units, unit);
		spring::VectorErase(baseQuads[qi].teamUnits[unit->allyteam], unit);
	}

	unit->quads.clear();

	#ifdef DEBUG_QUADFIELD
	for (const Quad& q: baseQuads) {
		for (auto& teamUnits: q.teamUnits) {
			for (CUnit* u: teamUnits) {
				assert(u != unit);
			}
		}
	}
	#endif
}


void CQuadField::MovedRepulser(CPlasmaRepulser* repulser)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, repulser->weaponMuzzlePos, repulser->GetRadius());

	// compare if the quads have changed, if not stop here
	if (qfQuery.quads->size() == repulser->quads.size()) {
		if (std::equal(qfQuery.quads->begin(), qfQuery.quads->end(), repulser->quads.begin())) {
			return;
		}
	}

	for (const int qi: repulser->quads) {
		spring::VectorErase(baseQuads[qi].repulsers, repulser);
	}

	for (const int qi: *qfQuery.quads) {
		spring::VectorInsertUnique(baseQuads[qi].repulsers, repulser, false);
	}

	repulser->quads = std::move(*qfQuery.quads);
}

void CQuadField::RemoveRepulser(CPlasmaRepulser* repulser)
{
	for (const int qi: repulser->quads) {
		spring::VectorErase(baseQuads[qi].repulsers, repulser);
	}

	repulser->quads.clear();

	#ifdef DEBUG_QUADFIELD
	for (const Quad& q: baseQuads) {
		for (CPlasmaRepulser* r: q.repulsers) {
			assert(r != repulser);
		}
	}
	#endif
}


void CQuadField::AddFeature(CFeature* feature)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, feature->pos, feature->radius);

	for (const int qi: *qfQuery.quads) {
		spring::VectorInsertUnique(baseQuads[qi].features, feature, false);
	}
}

void CQuadField::RemoveFeature(CFeature* feature)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, feature->pos, feature->radius);

	for (const int qi: *qfQuery.quads) {
		spring::VectorErase(baseQuads[qi].features, feature);
	}

	#ifdef DEBUG_QUADFIELD
	for (const Quad& q: baseQuads) {
		for (CFeature* f: q.features) {
			assert(f != feature);
		}
	}
	#endif
}



void CQuadField::MovedProjectile(CProjectile* p)
{
	if (!p->synced)
		return;
	// hit-scan projectiles do NOT move!
	if (p->hitscan)
		return;

	const int newQuad = WorldPosToQuadFieldIdx(p->pos);
	if (newQuad != p->quads.back()) {
		RemoveProjectile(p);
		AddProjectile(p);
	}
}

void CQuadField::AddProjectile(CProjectile* p)
{
	assert(p->synced);

	if (p->hitscan) {
		QuadFieldQuery qfQuery;
		GetQuadsOnRay(qfQuery, p->pos, p->dir, p->speed.w);

		for (const int qi: *qfQuery.quads) {
			spring::VectorInsertUnique(baseQuads[qi].projectiles, p, false);
		}

		p->quads = std::move(*qfQuery.quads);
	} else {
		int newQuad = WorldPosToQuadFieldIdx(p->pos);
		spring::VectorInsertUnique(baseQuads[newQuad].projectiles, p, false);
		p->quads.clear();
		p->quads.push_back(newQuad);
	}
}

void CQuadField::RemoveProjectile(CProjectile* p)
{
	assert(p->synced);

	for (const int qi: p->quads) {
		spring::VectorErase(baseQuads[qi].projectiles, p);
	}

	p->quads.clear();
}





void CQuadField::GetUnits(QuadFieldQuery& qfq, const float3& pos, float radius)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	const int tempNum = gs->GetTempNum();
	qfq.units = tempUnits.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CUnit* u: baseQuads[qi].units) {
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;
			qfq.units->push_back(u);
		}
	}

	return;
}

void CQuadField::GetUnitsExact(QuadFieldQuery& qfq, const float3& pos, float radius, bool spherical)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	const int tempNum = gs->GetTempNum();
	qfq.units = tempUnits.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CUnit* u: baseQuads[qi].units) {
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			const float totRad       = radius + u->radius;
			const float totRadSq     = totRad * totRad;
			const float posUnitDstSq = spherical?
				pos.SqDistance(u->pos):
				pos.SqDistance2D(u->pos);

			if (posUnitDstSq >= totRadSq)
				continue;

			qfq.units->push_back(u);
		}
	}

	return;
}

void CQuadField::GetUnitsExact(QuadFieldQuery& qfq, const float3& mins, const float3& maxs)
{
	QuadFieldQuery qfQuery;
	GetQuadsRectangle(qfQuery, mins, maxs);
	const int tempNum = gs->GetTempNum();
	qfq.units = tempUnits.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CUnit* unit: baseQuads[qi].units) {

			if (unit->tempNum == tempNum)
				continue;

			unit->tempNum = tempNum;

			const float3& pos = unit->pos;
			if (pos.x < mins.x || pos.x > maxs.x)
				continue;
			if (pos.z < mins.z || pos.z > maxs.z)
				continue;

			qfq.units->push_back(unit);
		}
	}

	return;
}


void CQuadField::GetFeaturesExact(QuadFieldQuery& qfq, const float3& pos, float radius, bool spherical)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	const int tempNum = gs->GetTempNum();
	qfq.features = tempFeatures.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CFeature* f: baseQuads[qi].features) {
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			const float totRad       = radius + f->radius;
			const float totRadSq     = totRad * totRad;
			const float posDstSq = spherical?
				pos.SqDistance(f->pos):
				pos.SqDistance2D(f->pos);

			if (posDstSq >= totRadSq)
				continue;

			qfq.features->push_back(f);
		}
	}

	return;
}

void CQuadField::GetFeaturesExact(QuadFieldQuery& qfq, const float3& mins, const float3& maxs)
{
	QuadFieldQuery qfQuery;
	GetQuadsRectangle(qfQuery, mins, maxs);
	const int tempNum = gs->GetTempNum();
	qfq.features = tempFeatures.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CFeature* feature: baseQuads[qi].features) {
			if (feature->tempNum == tempNum)
				continue;

			feature->tempNum = tempNum;

			const float3& pos = feature->pos;
			if (pos.x < mins.x || pos.x > maxs.x)
				continue;
			if (pos.z < mins.z || pos.z > maxs.z)
				continue;

			qfq.features->push_back(feature);
		}
	}

	return;
}



void CQuadField::GetProjectilesExact(QuadFieldQuery& qfq, const float3& pos, float radius)
{
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	const int tempNum = gs->GetTempNum();
	qfq.projectiles = tempProjectiles.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CProjectile* p: baseQuads[qi].projectiles) {
			if (p->tempNum == tempNum)
				continue;

			p->tempNum = tempNum;

			if (pos.SqDistance(p->pos) >= Square(radius + p->radius))
				continue;

			qfq.projectiles->push_back(p);
		}
	}

	return;
}

void CQuadField::GetProjectilesExact(QuadFieldQuery& qfq, const float3& mins, const float3& maxs)
{
	QuadFieldQuery qfQuery;
	GetQuadsRectangle(qfQuery, mins, maxs);
	const int tempNum = gs->GetTempNum();
	qfq.projectiles = tempProjectiles.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CProjectile* p: baseQuads[qi].projectiles) {
			if (p->tempNum == tempNum)
				continue;

			p->tempNum = tempNum;

			const float3& pos = p->pos;
			if (pos.x < mins.x || pos.x > maxs.x)
				continue;
			if (pos.z < mins.z || pos.z > maxs.z)
				continue;

			qfq.projectiles->push_back(p);
		}
	}

	return;
}



void CQuadField::GetSolidsExact(
	QuadFieldQuery& qfq,
	const float3& pos,
	const float radius,
	const unsigned int physicalStateBits,
	const unsigned int collisionStateBits
) {
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	const int tempNum = gs->GetTempNum();
	qfq.solids = tempSolids.GetVector();

	for (const int qi: *qfQuery.quads) {
		for (CUnit* u: baseQuads[qi].units) {
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			if (!u->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!u->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - u->pos).SqLength() >= Square(radius + u->radius))
				continue;

			qfq.solids->push_back(u);
		}

		for (CFeature* f: baseQuads[qi].features) {
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			if (!f->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!f->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - f->pos).SqLength() >= Square(radius + f->radius))
				continue;

			qfq.solids->push_back(f);
		}
	}

	return;
}


bool CQuadField::NoSolidsExact(
	const float3& pos,
	const float radius,
	const unsigned int physicalStateBits,
	const unsigned int collisionStateBits
) {
	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	const int tempNum = gs->GetTempNum();

	for (const int qi: *qfQuery.quads) {
		for (CUnit* u: baseQuads[qi].units) {
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			if (!u->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!u->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - u->pos).SqLength() >= Square(radius + u->radius))
				continue;

			return false;
		}

		for (CFeature* f: baseQuads[qi].features) {
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			if (!f->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!f->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - f->pos).SqLength() >= Square(radius + f->radius))
				continue;

			return false;
		}
	}

	return true;
}


// optimization specifically for projectile collisions
void CQuadField::GetUnitsAndFeaturesColVol(
	const float3& pos,
	const float radius,
	std::vector<CUnit*>& units,
	std::vector<CFeature*>& features,
	std::vector<CPlasmaRepulser*>* repulsers
) {
	const int tempNum = gs->GetTempNum();

	QuadFieldQuery qfQuery;
	GetQuads(qfQuery, pos, radius);
	// start counting from the previous object-cache sizes

	for (const int qi: *qfQuery.quads) {
		const Quad& quad = baseQuads[qi];

		for (CUnit* u: quad.units) {
			// prevent double adding
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			const auto* colvol = &u->collisionVolume;
			const float totRad = radius + colvol->GetBoundingRadius();

			if (pos.SqDistance(colvol->GetWorldSpacePos(u)) >= (totRad * totRad))
				continue;

			units.push_back(u);
		}

		for (CFeature* f: quad.features) {
			// prevent double adding
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			const auto* colvol = &f->collisionVolume;
			const float totRad = radius + colvol->GetBoundingRadius();

			if (pos.SqDistance(colvol->GetWorldSpacePos(f)) >= (totRad * totRad))
				continue;

			features.push_back(f);
		}
		if (repulsers != nullptr) {
			for (CPlasmaRepulser* r: quad.repulsers) {
				// prevent double adding
				if (r->tempNum == tempNum)
					continue;

				r->tempNum = tempNum;

				const auto* colvol = &r->collisionVolume;
				const float totRad = radius + colvol->GetBoundingRadius();

				if (pos.SqDistance(r->weaponMuzzlePos) >= (totRad * totRad))
					continue;

				repulsers->push_back(r);
			}
		}
	}
}
#endif // UNIT_TEST