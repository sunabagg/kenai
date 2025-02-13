# SPDX-License-Identifier: Unlicense

cmake_minimum_required( VERSION 3.22 )

message( STATUS "Using CMake ${CMAKE_VERSION}" )

# Require out-of-source builds
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )

if ( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in the source directory. Please use a build subdirectory." )
endif()

# Add paths to modules
list( APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/" )

# Turn on link time optimization for everything
set( CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON )

# Output compile commands to compile_commands.json (for debugging CMake issues)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# Build universal lib on macOS
# Note that CMAKE_OSX_ARCHITECTURES must be set before project().
if ( APPLE )
    set( CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "" )
endif()

# Main project information
project( Newhaven
    LANGUAGES
        CXX
    VERSION
        0.1.0
)

# Create our library
add_library( ${PROJECT_NAME} SHARED
        src/core/base_object.cpp
        src/core/base_object.h
        src/app.cpp
        src/app.h
        src/core/scene_system.h
        src/core/lua_bind.h
        src/core/lua_bind.cpp
        src/core/lua_function_wrapper.h)

target_compile_features( ${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

# LIB_ARCH is the architecture being built. It is set to the build system's architecture.
# For macOS, we build a universal library (both arm64 and x86_64).
set( LIB_ARCH ${CMAKE_SYSTEM_PROCESSOR} )
if ( APPLE )
    set( LIB_ARCH "universal" )
endif()

# LIB_DIR is where the actual library ends up. This is used in both the build directory and the
# install directory and needs to be consistent with the paths in the gdextension file.
#   e.g. linux.release.x86_64 = "lib/Linux-x86_64/libGDExtensionTemplate.so"
set( LIB_DIR "lib/${CMAKE_SYSTEM_NAME}-${LIB_ARCH}" )

message( STATUS "Building ${PROJECT_NAME} for ${LIB_ARCH} on ${CMAKE_SYSTEM_NAME}")

# BUILD_OUTPUT_DIR is where we put the resulting library (in the build directory)
set( BUILD_OUTPUT_DIR "${PROJECT_BINARY_DIR}/${PROJECT_NAME}/" )

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN true
        RUNTIME_OUTPUT_DIRECTORY "${BUILD_OUTPUT_DIR}/${LIB_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${BUILD_OUTPUT_DIR}/${LIB_DIR}"
)

if( NOT DEFINED CMAKE_DEBUG_POSTFIX )
    set_target_properties( ${PROJECT_NAME}
        PROPERTIES
            DEBUG_POSTFIX "-d"
    )
endif()

# Copy over additional files from the support_files directory
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/support_files"
            ${BUILD_OUTPUT_DIR}
)

# Warnings
include( CompilerWarnings )

# Create and include version info file from git
include( GitVersionInfo )

add_subdirectory( src )

# Install library, extension file, and support files in ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
set( INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/" )

message( STATUS "Install directory: ${INSTALL_DIR}")

install( TARGETS ${PROJECT_NAME}
    LIBRARY
        DESTINATION ${INSTALL_DIR}/${LIB_DIR}
    RUNTIME
        DESTINATION ${INSTALL_DIR}/${LIB_DIR}
)

# Copy over support files
install( DIRECTORY "${CMAKE_SOURCE_DIR}/support_files/"
    DESTINATION ${INSTALL_DIR}
    PATTERN ".*" EXCLUDE
)

add_subdirectory( templates )

# ccache
# Turns on ccache if found
include( ccache )

# Formatting
# Adds a custom target to format all the code at once
include( ClangFormat )

# godot-cpp
# From here: https://github.com/godotengine/godot-cpp
if ( NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/extern/godot-cpp/Makefile" )
    message(
        FATAL_ERROR
            "[${PROJECT_NAME}] The godot-cpp submodule was not downloaded. Please update submodules: git submodule update --init --recursive."
    )
endif()

set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )

add_subdirectory( extern/godot-cpp )
if ( NOT MSVC )
    # Add this before the add_subdirectory( extern/quickjs ) line
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=pedantic -Wno-error=cast-function-type")

    # Add this line to disable treating warnings as errors
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=duplicated-branches")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=shadow")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-dev")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-function")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=missing-field-initializers")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=return-type")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else ()
    # Add this line to disable treating warnings as errors
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4005")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4002")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4458")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4700")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4505")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4715")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4238")

    # sets the fsanitize flags
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")

    target_compile_options(${PROJECT_NAME} PRIVATE /bigobj)
endif ()

set_target_properties( godot-cpp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden    # visibility needs to be the same as the main library
)

# Set the CMAKE_PREFIX_PATH to include the Vcpkg installed directory
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

#option(LUAU_BUILD_CLI "" OFF)
#option(LUAU_BUILD_TESTS "" OFF)
#option(LUAU_STATIC_CRT "" ON)
#add_subdirectory( extern/luau )

#target_include_directories( ${PROJECT_NAME}
#    PRIVATE
#        "extern/luau/VM/include",
#        "extern/luau/Analysis/include",
#        "extern/luau/Ast/include",
#        "extern/luau/CodeGen/include",
#        "extern/luau/Common/include",
#        "extern/luau/Compiler/include",
#        "extern/luau/Config/include",
#        "extern/luau/EqSat/include"
#        "extern/luau/Ast/include")

add_subdirectory( extern/lua-5.1.5 )

if ( NOT MSVC)
    target_compile_options(liblua_static PRIVATE -include ${CMAKE_SOURCE_DIR}/extern/lua-5.1.5/include/lua51_prefix.h)
else()
    target_include_directories(liblua_static PRIVATE ${CMAKE_SOURCE_DIR}/extern/lua-5.1.5/include/lua51_prefix.h)
endif ()

option(USE_LUAJIT "Use LuaJIT" ON)

if (USE_LUAJIT)
    # Include the PkgConfig module
    include(FindPkgConfig)

    # Check for LuaJit using pkg-config
    pkg_check_modules(LUAJIT REQUIRED luajit)

    if (LUAJIT_FOUND)
        # Include directories for LuaJit
        include_directories(${LUAJIT_INCLUDE_DIRS})
    else()
        # Fallback: Manually specify the LuaJit paths
        if (MSVC)
		    set(LUAJIT_INCLUDE_DIRS "C:\Users\mintkat\luajit\src")
            set(LUAJIT_LIBRARIES "C:\Users\mintkat\luajit\src\lua51.dll")
        endif()
        include_directories(${LUAJIT_INCLUDE_DIRS})
    endif()
endif()

# For anyone on MSVC having issues with 'lua51.lib' copy it to the build directory,
# because the linker can't find it in the vcpkg_installed directory.


#find_package(Lua REQUIRED)

if (USE_LUAJIT)
    # Include directories for LuaJit
    include_directories(${LUAJIT_INCLUDE_DIRS})
else() #
    #include_directories ( ${LUA_INCLUDE_DIR} )
    include_directories ( ${CMAKE_SOURCE_DIR}/extern/lua-5.1.5/include )
    include_directories ( ${CMAKE_SOURCE_DIR}/extern/lua-5.1.5/src )
endif()

if (WIN32)
    if (${LIB_ARCH} STREQUAL "x86_64")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/windows_x86_64_release/v8_monolith.lib")
    elseif( ${LIB_ARCH} STREQUAL "arm64")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/windows_arm64_release/v8_monolith.lib")
    endif()
elseif(LINUX)
    if (${LIB_ARCH} STREQUAL "x86_64")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/linux_x86_64_release/libv8_monolith.a")
    else(${LIB_ARCH} STREQUAL "arm64")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/linux_arm64_release/libv8_monolith.a")
    endif()
elseif(APPLE)
    if (IOS)
        if (${LIB_ARCH} STREQUAL "arm64")    
            set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/ios_arm64_release/libv8_monolith.a")
        elseif(${LIB_ARCH} STREQUAL "x86_64")
            set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/ios_x86_64_release/libv8_monolith.a")
        endif()
    else()
        if (${LIB_ARCH} STREQUAL "arm64")
            set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/macos_arm64_release/libv8_monolith.a")
        elseif(${LIB_ARCH} STREQUAL "x86_64")
            set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/macos_x86_64_release/libv8_monolith.a")
        endif()
    endif()
elseif(ANDROID)
    if (${LIB_ARCH} STREQUAL "arm64")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/android_arm64_release/libv8_monolith.a")
    elseif(${LIB_ARCH} STREQUAL "arm32")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/android_arm_release/libv8_monolith.a")
    elseif(${LIB_ARCH} STREQUAL "x86_64")
        set(V8_LIB_PATH "${CMAKE_SOURCE_DIR}/extern/v8/android_x86_64_release/libv8_monolith.a")
    endif()
endif()
        
include_directories(${CMAKE_SOURCE_DIR}/extern/v8/include)

#add_library(V8_LIB STATIC IMPORTED GLOBAL)
#set_property(TARGET V8_LIB PROPERTIES
#    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX;C" 
#    IMPORTED_LOCATION ${V8_LIB_PATH})

# Find the sol2 package
find_package(sol2 CONFIG REQUIRED)

# Link the libraries
if (USE_LUAJIT)
    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            godot-cpp
            ${LUAJIT_LIBRARIES}
            sol2
            ${V8_LIB_PATH}
            #Luau.Compiler Luau.VM
    )
else()
    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            godot-cpp
            liblua_static
            sol2
            ${V8_LIB_PATH}
            #Luau.Compiler Luau.VM
    )
endif()