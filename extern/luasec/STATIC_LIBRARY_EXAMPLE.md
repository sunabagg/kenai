# Example: Using LuaSec Static Library

This example shows how to link against the LuaSec static library in a C application.

## CMakeLists.txt for your project:

```cmake
cmake_minimum_required(VERSION 3.16)
project(luasec_example)

# Find LuaSec
find_package(luasec REQUIRED)
find_package(Lua REQUIRED)

# Create executable
add_executable(example main.c)

# Link libraries
target_link_libraries(example 
    luasec::ssl
    ${LUA_LIBRARIES}
)

target_include_directories(example PRIVATE 
    ${LUA_INCLUDE_DIR}
)
```

## main.c example:

```c
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

// LuaSec functions (when using static library, you need to declare these)
int luaopen_ssl_core(lua_State *L);

int main() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    // Register LuaSec module
    luaL_requiref(L, "ssl.core", luaopen_ssl_core, 1);
    lua_pop(L, 1);
    
    // Your Lua code here
    luaL_dostring(L, "print('LuaSec loaded successfully')");
    
    lua_close(L);
    return 0;
}
```

## Building:

```bash
mkdir build
cd build
cmake ..
make
```

Note: When using the static library, you may need to manually register the LuaSec module in your Lua state, as shown in the example above.
