/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MeleeWeapon.h"
#include "WeaponDef.h"
#include "WeaponMemPool.h"
#include "Sim/Units/Unit.h"

CR_BIND_DERIVED_POOL(CMeleeWeapon, CWeapon, , weaponMemPool.alloc, weaponMemPool.free)
CR_REG_METADATA(CMeleeWeapon, )

void CMeleeWeapon::FireImpl(const bool scriptCall)
{
	if (currentTarget.type != Target_Unit)
		return;

	// the heavier the unit, the more impulse it does
	currentTarget.unit->DoDamage(*damages, wantedDir * owner->mass * damages->impulseFactor, owner, weaponDef->id, -1);
}
