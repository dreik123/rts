#include <iostream>
/*
** $Id: linit.c,v 1.14.1.1 2007/12/27 13:02:25 roberto Exp $
** Initialization of libraries for lua.c
** See Copyright Notice in lua.h
*/

#define linit_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

static const luaL_Reg lualibs[] = { { "", luaopen_base },
                                    { LUA_LOADLIBNAME, luaopen_package },
                                    { LUA_TABLIBNAME, luaopen_table },
                                    { LUA_IOLIBNAME, luaopen_io },
                                    { LUA_OSLIBNAME, luaopen_os },
                                    { LUA_STRLIBNAME, luaopen_string },
                                    { LUA_MATHLIBNAME, luaopen_math },
                                    { LUA_DBLIBNAME, luaopen_debug },
                                    { NULL, NULL } };

LUALIB_API void
luaL_openlibs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}