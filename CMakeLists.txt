# SPDX-License-Identifier: Unlicense

cmake_minimum_required( VERSION 3.22 )

set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )

if ( __COMPILER_GNU OR GCC OR CLANG )
    # Add this before the add_subdirectory( extern/quickjs ) line
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=pedantic -Wno-error=cast-function-type")


    # Add this line to disable treating warnings as errors
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=duplicated-branches")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=shadow")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-function")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=missing-field-initializers")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=return-type")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=sign-compare")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=comment")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=array-bounds")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

add_subdirectory( extern/godot-cpp )

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

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Build universal lib on macOS
# Note that CMAKE_OSX_ARCHITECTURES must be set before project().
if ( APPLE )
    set( CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "" )
endif()

# Main project information
project( sunaba
    LANGUAGES
        C
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
        src/core/lua_function_wrapper.h
        src/core/luasocket_symbols.cpp)

target_compile_features( ${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

# LIB_ARCH is the architecture being built. It is set to the build system's architecture.
# For macOS, we build a universal library (both arm64 and x86_64).
set( LIB_ARCH ${CMAKE_SYSTEM_PROCESSOR} )
if ( APPLE )
    set( LIB_ARCH "universal" )
elseif ( ANDROID )
    set( LIB_ARCH ${CMAKE_ANDROID_ARCH_ABI} )
    # Disable FORTIFY_SOURCE to prevent buffer overflow crashes in Lua strchr calls
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0")
    # Additional Android-specific flags
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-stack-protector")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-stack-protector")
    
    # Sol2 safety configuration for Android
    add_compile_definitions(SOL_ALL_SAFETIES_OFF=1)
    add_compile_definitions(SOL_NO_CHECK_NUMBER_PRECISION=1)
    add_compile_definitions(SOL_SAFE_REFERENCES=0)
    
    # Additional Lua safety flags for Android
    add_compile_definitions(LUA_USE_APICHECK=0)
    add_compile_definitions("LUAI_ASSERT(x)=((void)0)")
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

if (EMSCRIPTEN)
    target_compile_options( ${PROJECT_NAME}
        PUBLIC
        -sSIDE_MODULE=2#not sure if this had some effect
        -sSUPPORT_LONGJMP=emscripten#fixed exception handling related errors
        -flto=full#fixed lto errors
        -pthread#fixed shared memory errors
        #removed -fno-exceptions
    )

    target_link_options( ${PROJECT_NAME}
        INTERFACE
        -sWASM_BIGINT
        -sSUPPORT_LONGJMP=emscripten#same stuff here
        -fvisibility=hidden
        -shared
        -flto=full
        -pthread
    )

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=macro-redefined")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=implicit-function-declaration")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unknown-warning-option")

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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=sign-compare")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=comment")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=array-bounds")
endif()

set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )

if ( __COMPILER_GNU OR GCC OR CLANG OR APPLE )
    # Add this before the add_subdirectory( extern/quickjs ) line
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=pedantic -Wno-error=cast-function-type")
    


    # Add this line to disable treating warnings as errors
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=duplicated-branches")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=shadow")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-function")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=missing-field-initializers")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=return-type")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=sign-compare")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=comment")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=array-bounds")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

    target_compile_options( ${PROJECT_NAME}
        PUBLIC
        -Wno-error=pedantic
        -Wno-error=cast-function-type
        -Wno-error=duplicated-branches
        -Wno-error=shadow
        -Wno-error=deprecated-declarations
        -Wno-error=unused-function
        -Wno-error=missing-field-initializers
        -Wno-error=return-type
        -Wno-error=address
        -Wno-error=pedantic
        -Wno-error=sign-compare
        -Wno-error=comment
        -Wno-error=array-bounds
        -fpermissive
        -fexceptions
        -ftemplate-backtrace-limit=0
            -D_GLIBCXX_USE_CXX11_ABI=1
    )
endif()

if ( MSVC )
    # Add this line to disable treating warnings as errors
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4005")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4002")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4458")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4700")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4505")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4715")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4238")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4239")
    #C4459
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4101")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4459")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4127")

    # sets the fsanitize flags
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")

    target_compile_options(${PROJECT_NAME} PRIVATE /bigobj)
endif ()

#set_target_properties( godot-cpp
#    PROPERTIES
#        CXX_VISIBILITY_PRESET hidden    # visibility needs to be the same as the main library
#)

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

option(USE_LUAJIT "Use LuaJIT" ON)

if (EMSCRIPTEN OR APPLE OR ANDROID)
    set(USE_LUAJIT OFF)
endif()

if (USE_LUAJIT)
    # Include the PkgConfig module
    include(FindPkgConfig)

    # Check for LuaJit using pkg-config
    pkg_check_modules(LUAJIT luajit)

    if (LUAJIT_FOUND)
        # Include directories for LuaJit
        include_directories(${LUAJIT_INCLUDE_DIRS})
    else()
        # Fallback to Lua 5.1.5
        set(USE_LUAJIT OFF)
        add_subdirectory( extern/lua-5.1.5 )
    endif()
else()
    add_subdirectory( extern/lua-5.1.5 )
endif()

# For anyone on MSVC having issues with 'lua51.lib' copy it to the build directory,
# because the linker can't find it in the vcpkg_installed directory.


#find_package(Lua REQUIRED)

if (USE_LUAJIT)
    add_compile_definitions( USE_LUAJIT )
    # Include directories for LuaJIT
    include_directories(${LUAJIT_INCLUDE_DIRS})
else() #
    add_compile_definitions( USE_PUCRIO_LUA )
    #include_directories ( ${LUA_INCLUDE_DIR} )
    include_directories( ${CMAKE_SOURCE_DIR}/extern/lua-5.1.5/include() )
    include_directories ( ${CMAKE_SOURCE_DIR}/extern/lua-5.1.5/src )
endif()

if (NOT EMSCRIPTEN AND NOT ANDROID)
    target_include_directories(${PROJECT_NAME} PRIVATE extern/portable-file-dialogs )
    add_compile_definitions( USE_PORTABLE_FILE_DIALOGS )
endif()

# Find the sol2 package
add_subdirectory( extern/sol2 )

include_directories( ${CMAKE_SOURCE_DIR}/extern/hx-lua-simdjson/src )

#add_library( hxsimdjson STATIC 
#    extern/hx-lua-simdjson/src/hxluasimdjson.h
#    extern/hx-lua-simdjson/src/hxluasimdjson.cpp
#    extern/hx-lua-simdjson/src/simdjson.h
#    extern/hx-lua-simdjson/src/simdjson.cpp 
#)

#target_compile_features( hxsimdjson
#    PRIVATE
#        cxx_std_17
#)

# Find pthread (needed for simdjson)
#find_package(Threads REQUIRED)

#include_directories( ${CMAKE_BINARY_DIR}/extern/godot-cpp/gen/include )
#include_directories( ${CMAKE_BINARY_DIR}/extern/godot-cpp/gen/src )
#include_directories( ${CMAKE_SOURCE_DIR}/extern/godot-cpp/include )
#include_directories( ${CMAKE_SOURCE_DIR}/extern/godot-cpp/src )

if (__COMPILER_GNU OR GCC OR CLANG)
    #target_compile_options( hxsimdjson
    #PUBLIC
    #    -Wno-error=pedantic
    #    -Wno-error=cast-function-type
    #    -Wno-error=duplicated-branches
    #    -Wno-error=shadow
    #    -Wno-error=deprecated-declarations
    #    -Wno-error=unused-function
    #    -Wno-error=missing-field-initializers
    #    -Wno-error=return-type
    #    -Wno-error=address
    #    -Wno-error=pedantic
    #    -Wno-error=sign-compare
    #    -Wno-error=comment
    #    -Wno-error=array-bounds
    #    -fpermissive
    #    -fexceptions
    #    -ftemplate-backtrace-limit=0
    #    -D_GLIBCXX_USE_CXX11_ABI=1
    #    -fPIC
    #)
endif()

include_directories( ${CMAKE_BINARY_DIR}/extern/godot-cpp/gen/include )

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build")
    # Add debug-specific settings here
else()
    message(STATUS "Non-debug build")
    # Add non-debug-specific settings here
endif()

set( LUA_USE_DLOPEN OFF )

if (NOT EMSCRIPTEN)
    add_subdirectory( extern/luasocket )
    target_include_directories( ${PROJECT_NAME}
        PRIVATE
            extern/luasocket/src
            extern/luasocket/src/socket
            extern/luasocket/src/mime
    )
    target_compile_definitions( ${PROJECT_NAME}
        PRIVATE
            USE_LUASOCKET
    )
    set( LUASEC_WITH_LUASOCKET OFF )
    add_subdirectory( extern/luasec )
    target_include_directories( ${PROJECT_NAME}
        PRIVATE
            extern/luasec/src 
    )
    target_compile_definitions( ${PROJECT_NAME}
        PRIVATE
            USE_LUASEC
    )
    add_subdirectory( extern/luv )
endif()

# Link the libraries
if (USE_LUAJIT)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            godot-cpp
            ${LUAJIT_STATIC_LIBRARIES}
            sol2
            luasocket::static
            luasec::ssl
    )
else()
    if (EMSCRIPTEN)
        target_link_libraries(${PROJECT_NAME}
            PRIVATE
                godot-cpp
                liblua_static
                sol2
        )
    else()
        target_link_libraries(${PROJECT_NAME}
            PRIVATE
                godot-cpp
                liblua_static
                sol2
                luasocket::static
                luasec::ssl
        )
    endif()
endif()