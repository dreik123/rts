#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "ITreeDrawer.h"
#include "BasicTreeDrawer.h"
#include "AdvTreeDrawer.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"

CONFIG(int, TreeRadius)
	.defaultValue((int) (5.5f * 256))
	.headlessValue(0)
	.minimumValue(0);

CONFIG(bool, 3DTrees).defaultValue(true).headlessValue(false).safemodeValue(false).description("Defines whether or not the trees generated by the engine (Default trees) will be shown as 3d or as cross sectioned ( + ) flat sides.");

ITreeDrawer* treeDrawer = NULL;


ITreeDrawer::ITreeDrawer()
	: CEventClient("[ITreeDrawer]", 314444, false), drawTrees(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ITreeDrawer::~ITreeDrawer() {
	eventHandler.RemoveClient(this);
	configHandler->Set("TreeRadius", (unsigned int) (baseTreeDistance * 256));
}



void ITreeDrawer::AddTrees()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void ITreeDrawer::AddTree(int treeID, int treeType, const float3& pos, float size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void ITreeDrawer::DeleteTree(int treeID, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void ITreeDrawer::ResetPos(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ITreeDrawer* ITreeDrawer::GetTreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void ITreeDrawer::DrawShadowPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void ITreeDrawer::Draw(bool drawReflection)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void ITreeDrawer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void ITreeDrawer::RenderFeatureCreated(const CFeature* feature) {
	// support /give'ing tree objects
	if (feature->def->drawType >= DRAWTYPE_TREE) {
		AddTree(feature->id, feature->def->drawType - 1, feature->pos, 1.0f);
	}
}

void ITreeDrawer::FeatureMoved(const CFeature* feature, const float3& oldpos) {
	if (feature->def->drawType >= DRAWTYPE_TREE) {
		DeleteTree(feature->id, oldpos);
		AddTree(feature->id, feature->def->drawType - 1, feature->pos, 1.0f);
	}
}

void ITreeDrawer::RenderFeatureDestroyed(const CFeature* feature) {
	if (feature->def->drawType >= DRAWTYPE_TREE) {
		DeleteTree(feature->id, feature->pos);

		if (feature->speed.SqLength2D() > 0.25f) {
			AddFallingTree(feature->id, feature->def->drawType - 1, feature->pos, feature->speed * XZVector);
		}
	}
}

