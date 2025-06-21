#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>

// External declarations for luasocket modules
extern int luaopen_socket_core(lua_State *L);
extern int luaopen_mime_core(lua_State *L);

int main() {
    printf("Testing LuaSocket as a CMake subdirectory...\n");
    
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    // Register luasocket modules (Lua 5.1 compatible)
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    
    lua_pushcfunction(L, luaopen_socket_core);
    lua_setfield(L, -2, "socket.core");
    
    lua_pushcfunction(L, luaopen_mime_core);
    lua_setfield(L, -2, "mime.core");
    
    lua_pop(L, 2);
    
    // Test basic functionality
    const char* test_code = 
        "local socket_core = require('socket.core')\n"
        "local mime_core = require('mime.core')\n"
        "print('✓ LuaSocket core module loaded via subdirectory!')\n"
        "print('✓ Socket module type: ' .. type(socket_core))\n"
        "print('✓ MIME module type: ' .. type(mime_core))\n";
    
    int result = luaL_dostring(L, test_code);
    if (result != 0) {
        fprintf(stderr, "✗ Lua error: %s\n", lua_tostring(L, -1));
        lua_close(L);
        return 1;
    }
    
    lua_close(L);
    printf("✓ LuaSocket subdirectory integration test completed successfully!\n");
    return 0;
}
