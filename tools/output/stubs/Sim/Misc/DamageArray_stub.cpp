#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include "DamageArray.h"
#include "DamageArrayHandler.h"

#include "System/float3.h"

#include <cassert>

CR_BIND(DamageArray, )

CR_REG_METADATA(DamageArray, (
	CR_MEMBER(paralyzeDamageTime),
	CR_MEMBER(impulseFactor),
	CR_MEMBER(impulseBoost),
	CR_MEMBER(craterMult),
	CR_MEMBER(craterBoost),
	CR_MEMBER(damages)
))

DamageArray::DamageArray(float damage)
	: paralyzeDamageTime(0)
	, impulseFactor(1.0f)
	, impulseBoost(0.0f)
	, craterMult(1.0f)
	, craterBoost(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


DamageArray DamageArray::operator * (float damageMult) const {
	DamageArray da(*this);

	for (unsigned int a = 0; a < damages.size(); ++a)
		da.damages[a] *= damageMult;

	return da;
}


void DamageArray::SetDefaultDamage(float damage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CR_BIND_DERIVED(DynDamageArray, DamageArray, )

CR_REG_METADATA(DynDamageArray, (
	CR_MEMBER(dynDamageExp),
	CR_MEMBER(dynDamageMin),
	CR_MEMBER(dynDamageRange),
	CR_MEMBER(dynDamageInverted),
	CR_MEMBER(craterAreaOfEffect),
	CR_MEMBER(damageAreaOfEffect),
	CR_MEMBER(edgeEffectiveness),
	CR_MEMBER(explosionSpeed),
	CR_MEMBER(refCount),
	CR_MEMBER(fromDef),

	CR_POSTLOAD(PostLoad)
))

DynDamageArray::DynDamageArray(float damage)
	: DamageArray(damage)
	, dynDamageExp(0.0f)
	, dynDamageMin(0.0f)
	, dynDamageRange(0.0f)
	, dynDamageInverted(false)
	, craterAreaOfEffect(4.0f)
	, damageAreaOfEffect(4.0f)
	, edgeEffectiveness(0.0f)
	, explosionSpeed(1.0f) // always overwritten
	, refCount(1)
	, fromDef(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void DynDamageArray::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

DamageArray DynDamageArray::GetDynamicDamages(const float3& startPos, const float3& curPos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const DynDamageArray* DynDamageArray::IncRef(const DynDamageArray* dda)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void DynDamageArray::DecRef(const DynDamageArray* dda)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

DynDamageArray* DynDamageArray::GetMutable(const DynDamageArray*& dda)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
