/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FlameThrower.h"

#include "WeaponDef.h"
#include "WeaponMemPool.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "System/myMath.h"

CR_BIND_DERIVED_POOL(CFlameThrower, CWeapon, , weaponMemPool.alloc, weaponMemPool.free)

CR_REG_METADATA(CFlameThrower,(
	CR_MEMBER(color),
	CR_MEMBER(color2)
))


void CFlameThrower::FireImpl(const bool scriptCall)
{
	float3 dir = currentTargetPos - weaponMuzzlePos;

	const float dist = dir.LengthNormalize();
	const float3 spread =
		(gsRNG.NextVector() * SprayAngleExperience() + SalvoErrorExperience()) -
		(dir * 0.001f);

	ProjectileParams params = GetProjectileParams();
	params.pos = weaponMuzzlePos;
	params.speed = dir * projectileSpeed;
	params.spread = spread;
	params.ttl = math::ceil(std::max(dist, range) / projectileSpeed * weaponDef->duration);

	WeaponProjectileFactory::LoadProjectile(params);
}

