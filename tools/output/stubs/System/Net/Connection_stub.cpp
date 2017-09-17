#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Connection.h"

namespace netcode {

CConnection::CConnection()
	: dataSent(0)
	, dataRecv(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace netcode
