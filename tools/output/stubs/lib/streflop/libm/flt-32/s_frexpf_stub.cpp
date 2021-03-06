#include <iostream>
/* See the import.pl script for potential modifications */
/* s_frexpf.c -- Simple version of s_frexp.c.
 * Conversion to Simple by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#if defined(LIBM_SCCS) && !defined(lint)
static char rcsid[] =
  "$NetBSD: s_frexpf.c,v 1.5f 1995/05/10 20:47:26 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  two25 = 3.3554432000e+07f; /* 0x4c000000 */

#ifdef __STDC__
Simple
__frexpf(Simple x, int* eptr)
#else
Simple __frexpf(x, eptr) Simple x;
int* eptr;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias(__frexpf, frexpf)
}
