# Using LuaSec as a CMake Subdirectory

This guide shows how to use LuaSec as a subdirectory in your CMake project, which is useful for embedding LuaSec directly into your application without requiring separate installation.

## Basic Usage

### 1. Add LuaSec as a Subdirectory

```cmake
cmake_minimum_required(VERSION 3.16)
project(my_project)

# Add LuaSec as a subdirectory
add_subdirectory(extern/luasec)

# Create your executable
add_executable(my_app main.c)

# Link against LuaSec static library
target_link_libraries(my_app 
    luasec::ssl      # This will link the static library when built as subdirectory
    ${LUA_LIBRARIES} # Add Lua if needed
)
```

### 2. Directory Structure

```
my_project/
├── CMakeLists.txt
├── main.c
└── extern/
    └── luasec/          # This repository
        ├── CMakeLists.txt
        ├── src/
        └── ...
```

## Configuration Options

When LuaSec is built as a subdirectory, the default options are optimized for embedded usage:

```cmake
# Default values when built as subdirectory:
# LUASEC_BUILD_SHARED=OFF    # Don't build .so/.dylib by default
# LUASEC_BUILD_STATIC=ON     # Build static library for linking
# LUASEC_WITH_LUASOCKET=ON   # Include internal LuaSocket
# LUASEC_INSTALL=OFF         # Don't install files by default

# You can override these before add_subdirectory():
set(LUASEC_BUILD_SHARED ON)    # Enable shared library if needed
set(LUASEC_INSTALL ON)         # Enable installation if needed
add_subdirectory(extern/luasec)
```

## Advanced Examples

### Example 1: Static Linking with Custom Options

```cmake
cmake_minimum_required(VERSION 3.16)
project(secure_app)

find_package(Lua REQUIRED)

# Configure LuaSec for static linking only
set(LUASEC_BUILD_SHARED OFF)
set(LUASEC_BUILD_STATIC ON)
set(LUASEC_WITH_LUASOCKET ON)
add_subdirectory(extern/luasec)

add_executable(secure_app 
    main.c
    app_ssl.c
)

target_link_libraries(secure_app
    luasec::ssl
    ${LUA_LIBRARIES}
)

target_include_directories(secure_app PRIVATE
    ${LUA_INCLUDE_DIR}
)
```

### Example 2: With Installation Support

```cmake
cmake_minimum_required(VERSION 3.16)
project(lua_server)

# Enable installation for LuaSec
set(LUASEC_INSTALL ON)
set(LUASEC_BUILD_SHARED ON)  # Build Lua module for runtime
set(LUASEC_BUILD_STATIC ON)  # Also build static for direct linking
add_subdirectory(extern/luasec)

# Your main executable using static linking
add_executable(lua_server server.c)
target_link_libraries(lua_server luasec::ssl)

# Installation
install(TARGETS lua_server DESTINATION bin)
# LuaSec files will be installed automatically due to LUASEC_INSTALL=ON
```

### Example 3: Multiple Lua Projects

```cmake
cmake_minimum_required(VERSION 3.16)
project(lua_suite)

# Configure LuaSec once for all subprojects
set(LUASEC_BUILD_STATIC ON)
set(LUASEC_BUILD_SHARED ON)
add_subdirectory(extern/luasec)

# First project - uses static linking
add_executable(ssl_client client/main.c)
target_link_libraries(ssl_client luasec::ssl)

# Second project - uses Lua module
add_executable(lua_interpreter interpreter/main.c)
target_link_libraries(lua_interpreter ${LUA_LIBRARIES})
# This would load ssl.so/.dylib at runtime via require("ssl")
```

## Target Names

When used as a subdirectory, LuaSec provides these targets:

- `luasec::ssl` - Alias that points to the static library (preferred)
- `ssl_static` - Static library target directly
- `ssl_shared` - Shared library target (if `LUASEC_BUILD_SHARED=ON`)
- `luasocket_static` - Internal LuaSocket static library

## C Code Example

```c
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

// When linking statically, you need to manually register the module
extern int luaopen_ssl_core(lua_State *L);

int main() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    // Register LuaSec module when using static linking
    luaL_requiref(L, "ssl.core", luaopen_ssl_core, 1);
    lua_pop(L, 1);
    
    // Now you can use SSL in Lua
    int result = luaL_dostring(L, 
        "local ssl = require('ssl')\n"
        "print('LuaSec version:', ssl._VERSION)\n"
    );
    
    if (result != LUA_OK) {
        fprintf(stderr, "Error: %s\n", lua_tostring(L, -1));
    }
    
    lua_close(L);
    return result;
}
```

## Benefits of Subdirectory Usage

1. **No Installation Required** - Everything is built and linked directly
2. **Version Control** - LuaSec version is locked to your project
3. **Simplified Distribution** - Single build produces everything needed
4. **Custom Configuration** - Easy to customize build options per project
5. **Static Linking** - Reduces runtime dependencies

## Notes

- When built as a subdirectory, installation is disabled by default to avoid conflicts
- The static library is preferred for embedded usage
- Lua modules (`.lua` files) are only installed when `LUASEC_INSTALL=ON`
- OpenSSL is still required as an external dependency
