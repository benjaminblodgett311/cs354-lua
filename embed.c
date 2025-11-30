#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int c_add(lua_State *L) {
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
}

int main(void) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dostring(L, "print('Hello from Lua!')");

    luaL_dostring(L,
        "function add(x, y)\n"
        "    return x + y\n"
        "end"
    );

    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 32);
    lua_call(L, 2, 1);
    printf("Lua result: %.0f\n", lua_tonumber(L, -1));
    lua_pop(L, 1);

    lua_pushcfunction(L, c_add);
    lua_setglobal(L, "c_add");

    luaL_dostring(L,
        "print('C add result:', c_add(5, 7))"
    );

    lua_close(L);
    return 0;
}

