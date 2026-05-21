/**
 *  Copyright (C) 2021 Masatoshi Fukunaga
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 *  deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 *
 */
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

static int isfile_lua(lua_State *L)
{
    int rc = 0;

    // idx value is wrapped by metatable
    if (lua_isuserdata(L, 1) && lua_getmetatable(L, 1)) {
        // get metatable from registry
        lua_pushstring(L, LUA_FILEHANDLE);
        lua_rawget(L, LUA_REGISTRYINDEX);
        // compare
        rc = lua_rawequal(L, -1, -2);
        lua_pop(L, 2);
    }
    lua_pushboolean(L, rc);
    return 1;
}

LUALIB_API int luaopen_io_isfile(lua_State *L)
{
    lua_pushcfunction(L, isfile_lua);
    return 1;
}
