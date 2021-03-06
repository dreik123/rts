#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GlobalSynced.h"

#include <assert.h>
#include <cstring>

#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/GameSetup.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/Log/FramePrefixer.h"
#include "System/Util.h"

/**
 * @brief global synced
 *
 * Global instance of CGlobalSynced
 */
CGlobalSynced* gs = NULL;
CGlobalSynced::SyncedRNG CGlobalSynced::rng;

CR_BIND(CGlobalSynced, )

CR_REG_METADATA(CGlobalSynced,
                (CR_MEMBER(frameNum),
                 CR_MEMBER(tempNum),

                 CR_MEMBER(speedFactor),
                 CR_MEMBER(wantedSpeedFactor),

                 CR_MEMBER(paused),
                 CR_MEMBER(godMode),
                 CR_MEMBER(cheatEnabled),
                 CR_MEMBER(noHelperAIs),
                 CR_MEMBER(editDefsEnabled),
                 CR_MEMBER(useLuaGaia),

                 CR_MEMBER(randSeed),
                 CR_MEMBER(initRandSeed)))

/**
 * Initializes variables in CGlobalSynced
 */
CGlobalSynced::CGlobalSynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGlobalSynced::~CGlobalSynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGlobalSynced::ResetState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGlobalSynced::LoadFromSetup(const CGameSetup* setup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return synced random integer
 *
 * returns a synced random integer
 */
int
CGlobalSynced::randInt()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return synced random float
 *
 * returns a synced random float
 */
float
CGlobalSynced::randFloat()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return synced random vector
 *
 * returns a synced random vector
 */
float3
CGlobalSynced::randVector()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
