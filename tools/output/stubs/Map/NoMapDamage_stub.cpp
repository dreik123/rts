#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "NoMapDamage.h"
#include "MapDamage.h"

/* Do no deformation. (Maybe I should've left all this in the header?) */

CNoMapDamage::CNoMapDamage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CNoMapDamage::~CNoMapDamage() {}

void
CNoMapDamage::Explosion(const float3& pos, float strength, float radius)
{}

void
CNoMapDamage::RecalcArea(int x1, int x2, int y1, int y2)
{}

void
CNoMapDamage::Update()
{}
