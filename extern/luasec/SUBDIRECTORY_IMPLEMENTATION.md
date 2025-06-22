# LuaSec CMake Subdirectory Support - Implementation Summary

## What Was Added

Successfully implemented CMake subdirectory support for LuaSec, allowing it to be easily embedded in other CMake projects without requiring separate installation.

### ✅ Key Features Implemented

1. **Automatic Subdirectory Detection**
   - Uses `get_directory_property(PARENT_DIRECTORY)` to detect subdirectory usage
   - Applies different default configurations when used as subdirectory

2. **Smart Default Options**
   - When standalone: `BUILD_SHARED=ON`, `BUILD_STATIC=ON`, `INSTALL=ON`
   - When subdirectory: `BUILD_SHARED=OFF`, `BUILD_STATIC=ON`, `INSTALL=OFF`

3. **Conditional Installation**
   - Installation rules only apply when not a subdirectory OR when `LUASEC_INSTALL=ON`
   - Prevents unwanted installation when embedded in other projects

4. **Proper Target Exports**
   - `luasec::ssl` alias target always available for easy linking
   - Package configuration only generated when appropriate

### ✅ Configuration Options for Subdirectory Usage

```cmake
# All options can be overridden before add_subdirectory():
set(LUASEC_BUILD_SHARED ON/OFF)    # Build shared library (.so/.dylib)
set(LUASEC_BUILD_STATIC ON/OFF)    # Build static library (.a)
set(LUASEC_WITH_LUASOCKET ON/OFF)  # Use internal LuaSocket
set(LUASEC_INSTALL ON/OFF)         # Enable installation even as subdirectory
add_subdirectory(path/to/luasec)
```

### ✅ Usage Examples

**Basic Usage:**
```cmake
add_subdirectory(extern/luasec)
target_link_libraries(my_app luasec::ssl)
```

**Custom Configuration:**
```cmake
set(LUASEC_BUILD_SHARED ON)  # Enable Lua module
set(LUASEC_INSTALL ON)       # Install files
add_subdirectory(extern/luasec)
```

### ✅ File Changes Made

1. **Main CMakeLists.txt**
   - Added subdirectory detection logic
   - Conditional project() declaration
   - Smart default options based on usage context
   - Conditional installation and package config generation

2. **src/CMakeLists.txt**
   - Conditional installation rules
   - Proper target export handling

3. **src/luasocket/CMakeLists.txt**
   - Conditional installation for luasocket library

4. **Documentation**
   - `SUBDIRECTORY_USAGE.md` - Comprehensive usage guide
   - Updated `CMAKE_README.md` with subdirectory info

### ✅ Testing Verification

- ✅ Builds successfully as subdirectory with default options
- ✅ Targets are properly created and linkable (`luasec::ssl`)
- ✅ Custom options work correctly (tested with shared library enabled)
- ✅ No installation rules triggered by default when used as subdirectory
- ✅ Static library linking works correctly in test application

### ✅ Benefits

1. **Easy Integration**: Single `add_subdirectory()` call to include LuaSec
2. **No Installation Required**: Everything builds in-place
3. **Version Control**: LuaSec version locked to your project
4. **Custom Configuration**: Easy to customize per project needs
5. **Static Linking**: Reduces runtime dependencies
6. **Clean Builds**: No interference with parent project installation

### ✅ Backward Compatibility

- All existing standalone build functionality preserved
- Original CMake usage patterns still work
- No breaking changes to public API
- Package configuration still generated for standalone builds

### 🎯 Target Availability

When used as subdirectory, these targets are available:

- `luasec::ssl` - ✅ Recommended alias (points to static library by default)
- `ssl_static` - ✅ Static library directly  
- `ssl_shared` - ✅ Shared library (if `LUASEC_BUILD_SHARED=ON`)
- `luasocket_static` - ✅ Internal LuaSocket helper library

## Summary

The LuaSec CMake build system now supports both standalone and subdirectory usage patterns:

- **Standalone**: Full installation, package config, both static and shared libraries
- **Subdirectory**: Static-focused, no installation by default, clean integration

This makes LuaSec much easier to embed in C/C++ projects that need SSL functionality without requiring system-wide installation or complex dependency management.
