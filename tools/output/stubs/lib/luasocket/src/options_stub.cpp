#include <iostream>
/*=========================================================================*\
* Common option interface
* LuaSocket toolkit
*
* RCS ID: $Id: options.c,v 1.6 2005/11/20 07:20:23 diego Exp $
\*=========================================================================*/
#include <string.h>

#include "lauxlib.h"

#include "auxiliar.h"
#include "inet.h"
#include "options.h"

/*=========================================================================*\
* Internal functions prototypes
\*=========================================================================*/
static int
opt_setmembership(lua_State* L, p_socket ps, int level, int name);
static int
opt_setboolean(lua_State* L, p_socket ps, int level, int name);
static int
opt_set(lua_State* L, p_socket ps, int level, int name, void* val, int len);

/*=========================================================================*\
* Exported functions
\*=========================================================================*/
/*-------------------------------------------------------------------------*\
* Calls appropriate option handler
\*-------------------------------------------------------------------------*/
int
opt_meth_setoption(lua_State* L, p_opt opt, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* enables reuse of local address */
int
opt_reuseaddr(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* disables the Naggle algorithm */
int
opt_tcp_nodelay(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_keepalive(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_dontroute(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_broadcast(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_ip_multicast_loop(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_linger(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_ip_multicast_ttl(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_ip_add_membership(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
opt_ip_drop_membersip(lua_State* L, p_socket ps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*=========================================================================*\
* Auxiliar functions
\*=========================================================================*/
static int
opt_setmembership(lua_State* L, p_socket ps, int level, int name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
opt_set(lua_State* L, p_socket ps, int level, int name, void* val, int len)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
opt_setboolean(lua_State* L, p_socket ps, int level, int name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
