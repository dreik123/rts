#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief Globally accessible stuff
 * Contains implementation of synced and unsynced global stuff.
 */

#include "GlobalUnsynced.h"

#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Sim/Misc/GlobalConstants.h" // for RANDINT_MAX
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h" // required by CREG
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Misc/SpringTime.h"
#include "System/Sync/SyncTracer.h"
#include "System/Util.h"
#include "System/creg/creg_cond.h"

#include <time.h>

/**
 * @brief global unsynced
 *
 * Global instance of CGlobalUnsynced
 */
CGlobalUnsynced* gu;

const float CGlobalUnsynced::reconnectSimDrawBalance = 0.15f;
UnsyncedRNG CGlobalUnsynced::rng;

CR_BIND(CGlobalUnsynced, )

CR_REG_METADATA(CGlobalUnsynced,
                (CR_IGNORED(simFPS),
                 CR_IGNORED(avgSimFrameTime),
                 CR_IGNORED(avgDrawFrameTime),
                 CR_IGNORED(avgFrameTime),
                 CR_MEMBER(modGameTime),
                 CR_MEMBER(gameTime),
                 CR_MEMBER(startTime),
                 CR_MEMBER(myPlayerNum),
                 CR_MEMBER(myTeam),
                 CR_MEMBER(myAllyTeam),
                 CR_MEMBER(myPlayingTeam),
                 CR_MEMBER(myPlayingAllyTeam),
                 CR_MEMBER(spectating),
                 CR_MEMBER(spectatingFullView),
                 CR_MEMBER(spectatingFullSelect),
                 CR_IGNORED(fpsMode),
                 CR_IGNORED(globalQuit),
                 CR_IGNORED(globalReload)))

CGlobalUnsynced::CGlobalUnsynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGlobalUnsynced::~CGlobalUnsynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGlobalUnsynced::ResetState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGlobalUnsynced::LoadFromSetup(const CGameSetup* setup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGlobalUnsynced::SetMyPlayer(const int myNumber)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CPlayer*
CGlobalUnsynced::GetMyPlayer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
