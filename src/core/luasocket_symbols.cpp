//
// LuaSocket symbol export helper
// This file ensures luasocket symbols are properly exported from the shared library
//

#ifdef USE_LUASOCKET

#include <lua.h>

// External function declarations from luasocket
extern "C" {
    int luaopen_socket_core(lua_State *L);
    int luaopen_mime_core(lua_State *L);
#ifndef _WIN32
    int luaopen_socket_unix(lua_State *L);
    int luaopen_socket_serial(lua_State *L);
#endif
}

// Dummy function to ensure symbols are linked
void lucidware_ensure_luasocket_symbols() {
    // These pointers ensure the symbols are referenced and linked
    volatile void* ptr1 = (void*)luaopen_socket_core;
    volatile void* ptr2 = (void*)luaopen_mime_core;
#ifndef _WIN32
    volatile void* ptr3 = (void*)luaopen_socket_unix;
    volatile void* ptr4 = (void*)luaopen_socket_serial;
#endif

    // Prevent compiler from optimizing away
    (void)ptr1;
    (void)ptr2;
#ifndef _WIN32
    (void)ptr3;
    (void)ptr4;
#endif
}

#endif // USE_LUASOCKET
