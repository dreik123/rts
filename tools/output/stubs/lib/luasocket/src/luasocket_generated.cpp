#include <iostream>
/*=========================================================================*\
* LuaSocket toolkit
* Networking support for the Lua language
* Diego Nehab
* 26/11/1999
*
* This library is part of an  effort to progressively increase the network
* connectivity  of  the Lua  language.  The  Lua interface  to  networking
* functions follows the Sockets API  closely, trying to simplify all tasks
* involved in setting up both  client and server connections. The provided
* IO routines, however, follow the Lua  style, being very similar  to the
* standard Lua read and write functions.
*
* RCS ID: $Id: luasocket.c,v 1.53 2005/10/07 04:40:59 diego Exp $
\*=========================================================================*/

/*=========================================================================*\
* Standard include files
\*=========================================================================*/
#include "lauxlib.h"
#include "lua.h"

#if !defined(LUA_VERSION_NUM) || (LUA_VERSION_NUM < 501)
#include "compat-5.1.h"
#endif

/*=========================================================================*\
* LuaSocket includes
\*=========================================================================*/
#include "auxiliar.h"
#include "buffer.h"
#include "except.h"
#include "inet.h"
#include "luasocket.h"
#include "select.h"
#include "tcp.h"
#include "timeout.h"
#include "udp.h"

/*-------------------------------------------------------------------------*\
* Internal function prototypes
\*-------------------------------------------------------------------------*/
static int
global_skip(lua_State* L);
static int
global_unload(lua_State* L);
static int
base_open(lua_State* L);

/*-------------------------------------------------------------------------*\
* Modules and functions
\*-------------------------------------------------------------------------*/
static const luaL_reg mod[] = { { "auxiliar", auxiliar_open },
                                { "except", except_open },
                                { "timeout", timeout_open },
                                { "buffer", buffer_open },
                                { "inet", inet_open },
                                { "tcp", tcp_open },
                                { "udp", udp_open },
                                { "select", select_open },
                                { NULL, NULL } };

static luaL_reg func[] = { { "skip", global_skip },
                           { "__unload", global_unload },
                           { NULL, NULL } };

/*-------------------------------------------------------------------------*\
* Skip a few arguments
\*-------------------------------------------------------------------------*/
static int
global_skip(lua_State* L)
{
    int amount = luaL_checkint(L, 1);
    int ret = lua_gettop(L) - amount - 1;
    return ret >= 0 ? ret : 0;
}

/*-------------------------------------------------------------------------*\
* Unloads the library
\*-------------------------------------------------------------------------*/
static int
global_unload(lua_State* L)
{
    (void)L;
    socket_close();
    return 0;
}

/*-------------------------------------------------------------------------*\
* Setup basic stuff.
\*-------------------------------------------------------------------------*/
static int
base_open(lua_State* L)
{
    if (socket_open()) {
        /* export functions (and leave namespace table on top of stack) */
        luaI_openlib(L, "socket", func, 0);
#ifdef LUASOCKET_DEBUG
        lua_pushstring(L, "_DEBUG");
        lua_pushboolean(L, 1);
        lua_rawset(L, -3);
#endif
        /* make version string available to scripts */
        lua_pushstring(L, "_VERSION");
        lua_pushstring(L, LUASOCKET_VERSION);
        lua_rawset(L, -3);
        return 1;
    } else {
        lua_pushstring(L, "unable to initialize library");
        lua_error(L);
        return 0;
    }
}

/*-------------------------------------------------------------------------*\
* Initializes all library modules.
\*-------------------------------------------------------------------------*/
LUASOCKET_API int
luaopen_socket_core(lua_State* L)
{
    int i;
    base_open(L);
    for (i = 0; mod[i].name; i++)
        mod[i].func(L);
    return 1;
}
