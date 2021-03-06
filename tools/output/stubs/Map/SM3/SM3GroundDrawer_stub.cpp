#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SM3GroundDrawer.h"
#include "SM3Map.h"
#include "terrain/TerrainNode.h"

#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ProjectileDrawer.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

#include <SDL_keysym.h>

CONFIG(int, SM3TerrainDetail).defaultValue(200);

CSM3GroundDrawer::CSM3GroundDrawer(CSM3ReadMap* m)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSM3GroundDrawer::~CSM3GroundDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
SpringCamToTerrainCam(CCamera& sc, terrain::Camera& tc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3GroundDrawer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3GroundDrawer::Draw(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3GroundDrawer::DrawShadowPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3GroundDrawer::DrawObjects(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const int maxQuadDepth = 4;

void
CSM3GroundDrawer::IncreaseDetail()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3GroundDrawer::DecreaseDetail()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3GroundDrawer::SetDetail(int newGroundDetail)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CSM3GroundDrawer::GetGroundDetail(const DrawPass::e& drawPass) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
