# LuaSocket CMake Build System

This CMake build system provides a modern way to build LuaSocket with support for static and shared libraries. It can be used in three different ways:

1. **Standalone build** - Build and install LuaSocket independently
2. **Subdirectory integration** - Include LuaSocket as part of a larger CMake project
3. **Package consumption** - Use installed LuaSocket via find_package()

## Build Options

- `LUASOCKET_BUILD_SHARED` (default: OFF) - Build shared libraries
- `LUASOCKET_BUILD_STATIC` (default: ON) - Build static libraries  
- `LUASOCKET_BUILD_UNIX` (default: ON) - Build Unix domain sockets support (Unix-like systems only)
- `LUASOCKET_BUILD_SERIAL` (default: ON) - Build serial support
- `LUASOCKET_INSTALL` (default: ON for standalone, OFF for subdirectory) - Install LuaSocket
- `LUASOCKET_FORCE_INSTALL` (default: OFF) - Force install even when used as subdirectory
- `LUASOCKET_DEBUG` (default: OFF) - Enable debug mode

## Building

### 1. Standalone Build

#### Static Library (default)

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

#### Shared Library

```bash
mkdir build && cd build
cmake -DLUASOCKET_BUILD_SHARED=ON -DLUASOCKET_BUILD_STATIC=OFF ..
cmake --build .
```

#### Both Static and Shared

```bash
mkdir build && cd build
cmake -DLUASOCKET_BUILD_SHARED=ON -DLUASOCKET_BUILD_STATIC=ON ..
cmake --build .
```

### 2. As a Subdirectory (Recommended for embedding)

This is the easiest way to integrate LuaSocket into your existing CMake project:

```cmake
# In your CMakeLists.txt
add_subdirectory(extern/luasocket)

# Link against LuaSocket (chooses the most appropriate target)
target_link_libraries(your_target PRIVATE luasocket::static)

# Or use the simple alias
target_link_libraries(your_target PRIVATE luasocket)
```

When used as a subdirectory:
- Installation is disabled by default (can be enabled with `LUASOCKET_FORCE_INSTALL=ON`)
- Static libraries are built by default
- All include paths are automatically configured
- No need to call `find_package()`

## Installation

```bash
cmake --install .
```

## Using in Your CMake Project

### Method 1: As a Subdirectory (Recommended)

See the subdirectory integration section above for detailed usage.

### Method 2: Using find_package() (after installation)

After installation, you can use LuaSocket in your CMake project:

### Find Package

```cmake
find_package(luasocket REQUIRED)
```

### Link Against Static Libraries

```cmake
target_link_libraries(your_target PRIVATE luasocket::static)
```

### Link Against Shared Libraries

```cmake
target_link_libraries(your_target PRIVATE luasocket::shared)
```

### Link Against Individual Components

```cmake
target_link_libraries(your_target PRIVATE 
    luasocket_socket_core_static
    luasocket_mime_core_static
)
```

## Library Components

The build system creates several library targets:

### Static Libraries
- `luasocket_socket_core_static` - Core socket functionality
- `luasocket_mime_core_static` - MIME functionality
- `luasocket_unix_static` - Unix domain sockets (Unix-like systems only)
- `luasocket_serial_static` - Serial port support
- `luasocket_static` - Convenience target linking all static components

### Shared Libraries
- `luasocket_socket_core_shared` - Core socket functionality
- `luasocket_mime_core_shared` - MIME functionality  
- `luasocket_unix_shared` - Unix domain sockets (Unix-like systems only)
- `luasocket_serial_shared` - Serial port support
- `luasocket_shared` - Convenience target linking all shared components

## Testing

Run tests with:

```bash
ctest
```

Or manually:

```bash
lua test/hello.lua
```

## Cross-Platform Support

The CMake build system automatically handles platform-specific differences:

- **Windows**: Uses `wsocket.c` and links with `ws2_32`
- **Unix-like**: Uses `usocket.c` 
- **macOS/FreeBSD**: Adds `UNIX_HAS_SUN_LEN` definition
- **Solaris**: Links with `nsl`, `socket`, and `resolv` libraries

### Integration with Kenai Project

To integrate with the main Kenai project, you can add this to your main `CMakeLists.txt`:

```cmake
# Add LuaSocket as a subdirectory
add_subdirectory(extern/luasocket)

# In your target that needs socket functionality:
target_link_libraries(your_kenai_target 
    PRIVATE 
        luasocket::static
        # ... other dependencies
)
```

## Integration with Existing Projects

If you're using LuaSocket as part of a larger CMake project, you can add it as a subdirectory:

```cmake
add_subdirectory(extern/luasocket)
target_link_libraries(your_target PRIVATE luasocket::static)
```

## Example Usage in C/C++

For C/C++ applications that embed Lua and need socket functionality, you can link against the static libraries. See the `example/` directory for a complete working example:

```c
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

// External declarations for luasocket modules
extern int luaopen_socket_core(lua_State *L);
extern int luaopen_mime_core(lua_State *L);

int main() {
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
    
    // Now you can use luasocket from Lua code
    luaL_dostring(L, "local socket = require('socket.core')");
    
    lua_close(L);
    return 0;
}
```

Build with:
```cmake
target_link_libraries(your_app 
    PRIVATE 
        ${LUA_LIBRARIES}
        luasocket_socket_core_static
        luasocket_mime_core_static
)
```
