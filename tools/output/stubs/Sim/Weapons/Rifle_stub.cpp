#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rifle.h"
#include "Game/GameHelper.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/Classes/HeatCloudProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Rendering/Env/Particles/Classes/TracerProjectile.h"
#include "Sim/Features/Feature.h"
#include "Sim/Units/Unit.h"
#include "System/Sync/SyncTracer.h"
#include "System/myMath.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CRifle, CWeapon, (NULL, NULL))
CR_REG_METADATA(CRifle, )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRifle::CRifle(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRifle::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
