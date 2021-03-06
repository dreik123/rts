#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "StartScriptGen.h"

#include "AIScriptHandler.h"
#include "FileSystem/ArchiveNameResolver.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/TdfParser.h"

CONFIG(bool, NoHelperAIs).defaultValue(false);

namespace StartScriptGen {

//////////////////////////////////////////////////////////////////////////////
//
//  Interface
//

std::string
CreateMinimalSetup(const std::string& game, const std::string& map)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CreateDefaultSetup(const std::string& map,
                   const std::string& game,
                   const std::string& ai,
                   const std::string& playername)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace StartScriptGen
