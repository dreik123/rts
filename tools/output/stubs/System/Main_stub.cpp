#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
        \mainpage
        This is the documentation of the Spring RTS Engine.
        https://springrts.com/
*/

#include "System/SpringApp.h"

#include "System/Exceptions.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Platform/Misc.h"
#include "System/Platform/Threading.h"
#include "System/Platform/errorhandler.h"

#ifdef WIN32
#include "lib/SOP/SOP.hpp" // NvOptimus

#include <stdlib.h>
#include <process.h>
#define setenv(k, v, o) SetEnvironmentVariable(k, v)
#endif

int
Run(int argc, char* argv[])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Always run on dedicated GPU
 * @return true when restart is required with new env vars
 */
static bool
SetNvOptimusProfile(const std::string& processFileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief main
 * @return exit code
 * @param argc argument count
 * @param argv array of argument strings
 *
 * Main entry point function
 */
int
main(int argc, char* argv[])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef WIN32
int WINAPI
WinMain(HINSTANCE hInstanceIn,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif
