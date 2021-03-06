#include <iostream>
/*
** $Id: lundump.c,v 2.7.1.4 2008/04/04 19:51:41 roberto Exp $
** load precompiled Lua chunks
** See Copyright Notice in lua.h
*/

#include <string.h>

#define lundump_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstring.h"
#include "lundump.h"
#include "lzio.h"

typedef struct
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

#define LoadMem(S, b, n, size) LoadBlock(S, b, (n) * (size))
#define LoadByte(S) (lu_byte) LoadChar(S)
#define LoadVar(S, x) LoadMem(S, &x, 1, sizeof(x))
#define LoadVector(S, b, n, size) LoadMem(S, b, n, size)

static void
LoadBlock(LoadState* S, void* b, size_t size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
LoadChar(LoadState* S)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
LoadInt(LoadState* S)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static lua_Number
LoadNumber(LoadState* S)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static TString*
LoadString(LoadState* S)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
LoadCode(LoadState* S, Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static Proto*
LoadFunction(LoadState* S, TString* p);

static void
LoadConstants(LoadState* S, Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
LoadDebug(LoadState* S, Proto* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static Proto*
LoadFunction(LoadState* S, TString* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
LoadHeader(LoadState* S)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
** load precompiled chunk
*/
Proto*
luaU_undump(lua_State* L, ZIO* Z, Mbuffer* buff, const char* name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
 * make header
 */
void
luaU_header(char* h)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
