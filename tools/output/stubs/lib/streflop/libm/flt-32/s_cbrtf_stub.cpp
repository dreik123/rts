#include <iostream>
/* See the import.pl script for potential modifications */
/* Compute cubic root of Simple value.
   Copyright (C) 1997 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Dirk Alboth <dirka@uni-paderborn.de> and
   Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1f of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include "SMath.h"
#include "math_private.h"

#define CBRT2 1.2599210498948731648f     /* 2^(1/3) */
#define SQR_CBRT2 1.5874010519681994748f /* 2^(2/3) */

static const Simple factor[5] = { 1.0f / SQR_CBRT2,
                                  1.0f / CBRT2,
                                  1.0f,
                                  CBRT2,
                                  SQR_CBRT2 };

namespace streflop_libm {
Simple
__cbrtf(Simple x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias(__cbrtf, cbrtf)
}
