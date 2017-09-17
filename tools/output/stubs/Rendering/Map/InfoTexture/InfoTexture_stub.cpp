#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InfoTexture.h"


CInfoTexture::CInfoTexture()
: texture(0)
, name()
, texSize(0, 0)
, texChannels(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CInfoTexture::CInfoTexture(const std::string& _name, GLuint _texture, int2 _texSize)
: texture(_texture)
, name(_name)
, texSize(_texSize)
, texChannels(4)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
