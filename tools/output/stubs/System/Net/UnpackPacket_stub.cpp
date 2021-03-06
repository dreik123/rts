#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnpackPacket.h"

#include <boost/shared_ptr.hpp>

namespace netcode {

UnpackPacket::UnpackPacket(boost::shared_ptr<const RawPacket> packet,
                           size_t skipBytes)
  : pckt(packet)
  , pos(skipBytes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
