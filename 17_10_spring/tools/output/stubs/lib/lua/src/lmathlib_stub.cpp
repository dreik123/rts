#include <iostream>
/*
** $Id: lmathlib.c,v 1.67.1.1 2007/12/27 13:02:25 roberto Exp $
** Standard mathematical library
** See Copyright Notice in lua.h
*/

#include <stdlib.h>
// SPRING#include <math.h>
#include "System/FastMath.h"
#include "streflop_cond.h"

#define lmathlib_c
#define LUA_LIB

#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

#undef PI
#define PI (3.14159265358979323846)
#define RADIANS_PER_DEGREE (PI / 180.0)

static int
math_abs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_sin(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_sinh(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_cos(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_cosh(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_tan(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_tanh(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_asin(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_acos(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_atan(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_atan2(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_ceil(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_floor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_fmod(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_modf(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_sqrt(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_pow(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_log(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_log10(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_exp(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_deg(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_rad(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_frexp(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_ldexp(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_min(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_max(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_random(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
math_randomseed(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const luaL_Reg mathlib[] = { { "abs", math_abs },
                                    { "acos", math_acos },
                                    { "asin", math_asin },
                                    { "atan2", math_atan2 },
                                    { "atan", math_atan },
                                    { "ceil", math_ceil },
                                    { "cosh", math_cosh },
                                    { "cos", math_cos },
                                    { "deg", math_deg },
                                    { "exp", math_exp },
                                    { "floor", math_floor },
                                    { "fmod", math_fmod },
                                    { "frexp", math_frexp },
                                    { "ldexp", math_ldexp },
                                    { "log10", math_log10 },
                                    { "log", math_log },
                                    { "max", math_max },
                                    { "min", math_min },
                                    { "modf", math_modf },
                                    { "pow", math_pow },
                                    { "rad", math_rad },
                                    { "random", math_random },
                                    { "randomseed", math_randomseed },
                                    { "sinh", math_sinh },
                                    { "sin", math_sin },
                                    { "sqrt", math_sqrt },
                                    { "tanh", math_tanh },
                                    { "tan", math_tan },
                                    { NULL, NULL } };

/*
** Open math library
*/
LUALIB_API int
luaopen_math(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
