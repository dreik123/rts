#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Combiner.h"
#include "Game/GlobalUnsynced.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

CONFIG(bool, HighResInfoTexture).defaultValue(true);

CInfoTextureCombiner::CInfoTextureCombiner()
  : CPboInfoTexture("info")
  , disabled(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureCombiner::SwitchMode(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CInfoTextureCombiner::CreateShader(const std::string& filename,
                                   const bool clear,
                                   const float4 clearColor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureCombiner::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
