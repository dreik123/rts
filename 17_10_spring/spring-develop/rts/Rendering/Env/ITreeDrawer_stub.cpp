#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ITreeDrawer.h"
#include "AdvTreeDrawer.h"
#include "BasicTreeDrawer.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"

CONFIG(int, TreeRadius)
  .defaultValue((int)(5.5f * 256))
  .headlessValue(0)
  .minimumValue(0);

CONFIG(bool, 3DTrees)
  .defaultValue(true)
  .headlessValue(false)
  .safemodeValue(false)
  .description("Defines whether or not the trees generated by the engine "
               "(Default trees) will be shown as 3d or as cross sectioned ( + "
               ") flat sides.");

ITreeDrawer* treeDrawer = NULL;

ITreeDrawer::ITreeDrawer()
  : CEventClient("[ITreeDrawer]", 314444, false)
  , drawTrees(true)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ITreeDrawer::~ITreeDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::AddTrees()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::AddTree(int treeID, int treeType, const float3& pos, float size)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::DeleteTree(int treeID, const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::ResetPos(const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ITreeDrawer*
ITreeDrawer::GetTreeDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::DrawShadowPass()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::RenderFeatureCreated(const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::FeatureMoved(const CFeature* feature, const float3& oldpos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ITreeDrawer::RenderFeatureDestroyed(const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
