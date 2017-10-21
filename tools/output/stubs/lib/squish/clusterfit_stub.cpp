#include <iostream>
/* -----------------------------------------------------------------------------

        Copyright (c) 2006 Simon Brown                          si@sjbrown.co.uk
        Copyright (c) 2007 Ignacio Castano                   icastano@nvidia.com

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

#include "clusterfit.h"
#include "colourblock.h"
#include "colourset.h"
#include <cfloat>

namespace squish {

ClusterFit::ClusterFit(ColourSet const* colours, int flags)
  : ColourFit(colours, flags)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ClusterFit::ConstructOrdering(Vec3 const& axis, int iteration)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ClusterFit::Compress3(void* block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ClusterFit::Compress4(void* block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace squish