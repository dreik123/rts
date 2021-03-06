#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ExternalAI/AICallback.h"

#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Camera.h"
#include "Game/Camera/CameraController.h"
#include "Game/CameraHandler.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/InMapDraw.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/TraceRay.h"
#include "Game/UI/Groups/Group.h"
#include "Game/UI/Groups/GroupHandler.h"
#include "Game/UI/MiniMap.h"
#include "Lua/LuaRules.h"
#include "Lua/LuaUI.h"
#include "Map/MapInfo.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/DebugDrawerAI.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/Models/3DModel.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GlobalConstants.h" // needed for MAX_UNITS
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/CommandQueue.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/EventHandler.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"

#include <map>
#include <string>
#include <vector>

// Cast id to unsigned to catch negative ids in the same operations,
// cast MAX_* to unsigned to suppress GCC comparison between signed/unsigned
// warning.
#define CHECK_UNITID(id) ((unsigned)(id) < (unsigned)unitHandler->MaxUnits())
#define CHECK_GROUPID(id) ((unsigned)(id) < (unsigned)gh->groups.size())
// With some hacking you can raise an abort (assert) instead of ignoring the id,
//#define CHECK_UNITID(id) (assert(id > 0 && id < unitHandler->MaxUnits()),
//true)
// ...or disable the check altogether for release.
//#define CHECK_UNITID(id) true

CUnit*
CAICallback::GetUnit(int unitId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CAICallback::GetMyTeamUnit(int unitId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CAICallback::GetInSensorRangeUnit(int unitId, unsigned short losFlags) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
CUnit*
CAICallback::GetInLosUnit(int unitId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
CUnit*
CAICallback::GetInLosAndRadarUnit(int unitId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAICallback::CAICallback(int teamId)
  : team(teamId)
  , noMessages(false)
  , gh(grouphandlers[teamId])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::SendTextMsg(const char* text, int zone)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::SetLastMsgPos(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::AddNotification(const float3& pos,
                             const float3& color,
                             float alpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::SendResources(float mAmount, float eAmount, int receivingTeamId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::SendUnits(const std::vector<int>& unitIds, int receivingTeamId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::PosInCamera(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// see if the AI hasn't modified any parts of this callback
// (still completely insecure ofcourse, but it filters out the easiest way of
// cheating)
void
CAICallback::verify()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetCurrentFrame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetMyTeam()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetMyAllyTeam()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetPlayerTeam(int playerId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
CAICallback::GetTeamSide(int teamId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void*
CAICallback::CreateSharedMemArea(char* name, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::ReleasedSharedMemArea(char* name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::CreateGroup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::EraseGroup(int groupId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::AddUnitToGroup(int unitId, int groupId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::RemoveUnitFromGroup(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetUnitGroup(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<const SCommandDescription*>*
CAICallback::GetGroupCommands(int groupId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GiveGroupOrder(int groupId, Command* c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GiveOrder(int unitId, Command* c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<const SCommandDescription*>*
CAICallback::GetUnitCommands(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CCommandQueue*
CAICallback::GetCurrentUnitCommands(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetUnitAiHint(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetUnitTeam(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetUnitAllyTeam(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitHealth(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitMaxHealth(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitSpeed(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitPower(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitExperience(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitMaxRange(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const UnitDef*
CAICallback::GetUnitDef(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const UnitDef*
CAICallback::GetUnitDef(const char* unitName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const UnitDef*
CAICallback::GetUnitDefById(int unitDefId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAICallback::GetUnitPos(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAICallback::GetUnitVelocity(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetBuildingFacing(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::IsUnitCloaked(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::IsUnitParalyzed(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::IsUnitNeutral(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::InitPath(const float3& start,
                      const float3& end,
                      int pathType,
                      float goalRadius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAICallback::GetNextWaypoint(int pathId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::FreePath(int pathId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetPathLength(float3 start,
                           float3 end,
                           int pathType,
                           float goalRadius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::SetPathNodeCost(unsigned int x, unsigned int z, float cost)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetPathNodeCost(unsigned int x, unsigned int z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
FilterUnitsVector(const std::vector<CUnit*>& units,
                  int* unitIds,
                  int unitIds_max,
                  bool (*includeUnit)(const CUnit*) = NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
unit_IsNeutral(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int myAllyTeamId = -1;

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsEnemy(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsFriendly(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsInLos(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsInRadar(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsEnemyAndInLos(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsEnemyAndInLosOrRadar(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// You have to set myAllyTeamId before calling this function. NOT thread safe!
static inline bool
unit_IsNeutralAndInLos(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetEnemyUnits(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetEnemyUnitsInRadarAndLos(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetEnemyUnits(int* unitIds,
                           const float3& pos,
                           float radius,
                           int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetFriendlyUnits(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetFriendlyUnits(int* unitIds,
                              const float3& pos,
                              float radius,
                              int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetNeutralUnits(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetNeutralUnits(int* unitIds,
                             const float3& pos,
                             float radius,
                             int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetMapWidth()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetMapHeight()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMaxMetal() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetExtractorRadius() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMinWind() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMaxWind() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetCurWind() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetTidalStrength() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetGravity() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const float*
CAICallback::GetHeightMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const float*
CAICallback::GetCornersHeightMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMinHeight()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
float
CAICallback::GetMaxHeight()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const float*
CAICallback::GetSlopeMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const unsigned short*
CAICallback::GetLosMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const unsigned short*
CAICallback::GetRadarMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const unsigned short*
CAICallback::GetJammerMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const unsigned char*
CAICallback::GetMetalMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetElevation(float x, float z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerStartPath(const float3& pos, const float* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerFinishPath()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerDrawLine(const float3& endPos, const float* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerDrawLineAndIcon(int commandId,
                                       const float3& endPos,
                                       const float* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerDrawIconAtLastPos(int commandId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerBreak(const float3& endPos, const float* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerRestart()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::LineDrawerRestartSameColor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::CreateSplineFigure(const float3& pos1,
                                const float3& pos2,
                                const float3& pos3,
                                const float3& pos4,
                                float width,
                                int arrow,
                                int lifetime,
                                int group)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::CreateLineFigure(const float3& pos1,
                              const float3& pos2,
                              float width,
                              int arrow,
                              int lifetime,
                              int group)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::SetFigureColor(int group,
                            float red,
                            float green,
                            float blue,
                            float alpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::DeleteFigureGroup(int group)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::DrawUnit(const char* unitName,
                      const float3& pos,
                      float rotation,
                      int lifetime,
                      int teamId,
                      bool transparent,
                      bool drawBorder,
                      int facing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::CanBuildAt(const UnitDef* unitDef, const float3& pos, int facing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAICallback::ClosestBuildSite(const UnitDef* unitDef,
                              const float3& pos,
                              float searchRadius,
                              int minDist,
                              int facing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMetal()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMetalIncome()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMetalUsage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetMetalStorage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetEnergy()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetEnergyIncome()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetEnergyUsage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetEnergyStorage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::GetUnitResourceInfo(int unitId, UnitResourceInfo* unitResInf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::IsUnitActivated(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::UnitBeingBuilt(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetFeatures(int* featureIds, int featureIds_sizeMax)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetFeatures(int* featureIds,
                         int featureIds_sizeMax,
                         const float3& pos,
                         float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const FeatureDef*
CAICallback::GetFeatureDef(int featureId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const FeatureDef*
CAICallback::GetFeatureDefById(int featureDefId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetFeatureHealth(int featureId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetFeatureReclaimLeft(int featureId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAICallback::GetFeaturePos(int featureId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::GetValue(int id, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::HandleCommand(int commandId, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::IsDebugDrawerEnabled() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetNumUnitDefs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::GetUnitDefList(const UnitDef** list)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitDefRadius(int def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CAICallback::GetUnitDefHeight(int def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::GetProperty(int unitId, int property, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetFileSize(const char* filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAICallback::GetFileSize(const char* filename, const char* modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::ReadFile(const char* filename, void* buffer, int bufferLength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::ReadFile(const char* filename,
                      const char* modes,
                      void* buffer,
                      int bufferLength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Additions to the interface by Alik
int
CAICallback::GetSelectedUnits(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CAICallback::GetMousePos()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::GetMapPoints(std::vector<PointMarker>& pm,
                          int pm_sizeMax,
                          bool includeAllies)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAICallback::GetMapLines(std::vector<LineMarker>& lm,
                         int lm_sizeMax,
                         bool includeAllies)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const WeaponDef*
CAICallback::GetWeapon(const char* weaponName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const WeaponDef*
CAICallback::GetWeaponDefById(int weaponDefId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CAICallback::CanBuildUnit(int unitDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const float3*
CAICallback::GetStartPos()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define AICALLBACK_CALL_LUA(HandleName)                                        \
    const char* CAICallback::CallLua##HandleName(const char* inData,           \
                                                 int inSize)                   \
    {                                                                          \
        if (lua##HandleName == NULL) {                                         \
            return NULL;                                                       \
        }                                                                      \
        return lua##HandleName->RecvSkirmishAIMessage(team, inData, inSize);   \
    }

AICALLBACK_CALL_LUA(Rules)
AICALLBACK_CALL_LUA(UI)

#undef AICALLBACK_CALL_LUA
