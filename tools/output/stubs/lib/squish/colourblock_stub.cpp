#include <iostream>
/* -----------------------------------------------------------------------------

        Copyright (c) 2006 Simon Brown                          si@sjbrown.co.uk

        Permission is hereby granted, free of charge, to any person obtaining
        a copy of this software and associated documentation files (the
        "Software"), to	deal in the Software without restriction, including
        without limitation the rights to use, copy, modify, merge, publish,
        distribute, sublicense, and/or sell copies of the Software, and to
        permit persons to whom the Software is furnished to do so, subject to
        the following conditions:

        The above copyright notice and this permission notice shall be included
        in all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
        OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
        MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
        IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
        CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
        TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
        SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

   -------------------------------------------------------------------------- */

#include "colourblock.h"

namespace squish {

static int
FloatToInt(float a, int limit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
FloatTo565(Vec3::Arg colour)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
WriteColourBlock(int a, int b, u8* indices, void* block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
WriteColourBlock3(Vec3::Arg start,
                  Vec3::Arg end,
                  u8 const* indices,
                  void* block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
WriteColourBlock4(Vec3::Arg start,
                  Vec3::Arg end,
                  u8 const* indices,
                  void* block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
Unpack565(u8 const* packed, u8* colour)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DecompressColour(u8* rgba, void const* block, bool isDxt1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace squish
