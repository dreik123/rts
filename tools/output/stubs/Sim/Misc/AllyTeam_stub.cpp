#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AllyTeam.h"

#include "System/creg/STL_Map.h"
#include <cstdlib>

CR_BIND(AllyTeam, )

CR_REG_METADATA(AllyTeam,
                (CR_MEMBER(startRectTop),
                 CR_MEMBER(startRectBottom),
                 CR_MEMBER(startRectLeft),
                 CR_MEMBER(startRectRight),
                 CR_MEMBER(allies),
                 CR_MEMBER(customValues)))

AllyTeam::AllyTeam()
  : startRectTop(0)
  , startRectBottom(1)
  , startRectLeft(0)
  , startRectRight(1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
