# LuaSec CMake Build System

This directory contains a CMake-based build system for LuaSec that replaces the original Makefile-based build.

## Features

- Support for both static and shared library builds
- Cross-platform compatibility (Linux, macOS, BSD)
- Configurable LuaSocket integration
- Modern CMake practices with exported targets
- Easy integration with other CMake projects

## Build Options

- `LUASEC_BUILD_SHARED` (default: ON) - Build shared library (.so/.dylib/.dll)
- `LUASEC_BUILD_STATIC` (default: ON) - Build static library (.a/.lib)
- `LUASEC_WITH_LUASOCKET` (default: ON) - Use internal LuaSocket helper library

## Dependencies

- OpenSSL (libssl and libcrypto)
- Lua 5.1 or compatible
- CMake 3.16 or later

## Building

### Basic build:
```bash
mkdir build
cd build
cmake ..
make
```

### Custom configuration:
```bash
mkdir build
cd build
cmake .. \
  -DLUASEC_BUILD_SHARED=ON \
  -DLUASEC_BUILD_STATIC=ON \
  -DLUASEC_WITH_LUASOCKET=ON \
  -DLUAPATH=/usr/local/share/lua/5.1 \
  -DLUACPATH=/usr/local/lib/lua/5.1
make
```

### Installing:
```bash
make install
```

## Using in Other CMake Projects

### As an Installed Package
After installation, you can use LuaSec in other CMake projects:

```cmake
find_package(luasec REQUIRED)
target_link_libraries(your_target luasec::ssl)
```

### As a Subdirectory
You can also include LuaSec directly in your project:

```cmake
# Add LuaSec as subdirectory (defaults to static library, no installation)
add_subdirectory(extern/luasec)

# Link against the static library
target_link_libraries(your_target luasec::ssl)
```

For detailed subdirectory usage, see `SUBDIRECTORY_USAGE.md`.

## Platform-Specific Notes

### macOS
The build system automatically handles macOS-specific linking requirements (bundle format, undefined dynamic lookup).

### Linux/BSD
Standard shared library linking is used.

## Migration from Makefile

The CMake build system provides equivalent functionality to the original Makefile:

- `make linux` → `cmake .. && make` (on Linux)
- `make macosx` → `cmake .. && make` (on macOS) 
- `make bsd` → `cmake .. && make` (on BSD)
- `make install` → `make install`
- `make clean` → `make clean` or `rm -rf build/`

## Targets

- `ssl_shared` - Shared library (ssl.so/ssl.dylib)
- `ssl_static` - Static library (libssl.a)
- `luasocket_static` - Internal LuaSocket static library
- `luasec::ssl` - Alias target (points to static if available, otherwise shared)
