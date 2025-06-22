cmake_minimum_required(VERSION 3.16)

# Check if this is being built as a subdirectory
get_directory_property(LUASEC_IS_SUBPROJECT PARENT_DIRECTORY)

if(NOT LUASEC_IS_SUBPROJECT)
    project(luasec VERSION 1.3.2 LANGUAGES C)
else()
    # When built as subdirectory, make variables available to parent scope
    set(LUASEC_VERSION "1.3.2" PARENT_SCOPE)
endif()

# Options (use different defaults when built as subdirectory)
if(LUASEC_IS_SUBPROJECT)
    option(LUASEC_BUILD_SHARED "Build shared library" OFF)
    option(LUASEC_BUILD_STATIC "Build static library" ON)
    option(LUASEC_WITH_LUASOCKET "Use internal LuaSocket" ON)
    option(LUASEC_INSTALL "Install LuaSec files" OFF)
else()
    option(LUASEC_BUILD_SHARED "Build shared library" ON)
    option(LUASEC_BUILD_STATIC "Build static library" ON)
    option(LUASEC_WITH_LUASOCKET "Use internal LuaSocket" ON)
    option(LUASEC_INSTALL "Install LuaSec files" ON)
endif()

# Find required packages
find_package(PkgConfig REQUIRED)
find_package(OpenSSL REQUIRED)

# Try to find Lua (only if not provided by parent project)
if(NOT TARGET lua OR NOT DEFINED LUA_INCLUDE_DIR)
    find_package(Lua QUIET)
    if(NOT LUA_FOUND)
        pkg_check_modules(LUA REQUIRED lua5.1)
    endif()
endif()

# Set installation directories (only when not a subdirectory or LUASEC_INSTALL is ON)
if(NOT LUASEC_IS_SUBPROJECT OR LUASEC_INSTALL)
    if(NOT LUAPATH)
        if(LUA_FOUND)
            set(LUAPATH "${CMAKE_INSTALL_PREFIX}/share/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}")
        else()
            set(LUAPATH "${CMAKE_INSTALL_PREFIX}/share/lua/5.1")
        endif()
    endif()

    if(NOT LUACPATH)
        if(LUA_FOUND)
            set(LUACPATH "${CMAKE_INSTALL_PREFIX}/lib/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}")
        else()
            set(LUACPATH "${CMAKE_INSTALL_PREFIX}/lib/lua/5.1")
        endif()
    endif()
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
if(LUA_FOUND AND LUA_INCLUDE_DIR)
    include_directories(${LUA_INCLUDE_DIR})
elseif(LUA_FOUND AND LUA_INCLUDE_DIRS)
    include_directories(${LUA_INCLUDE_DIRS})
endif()

# Add subdirectories
add_subdirectory(src)

# Installation of Lua modules (only when not a subdirectory or LUASEC_INSTALL is ON)
if(NOT LUASEC_IS_SUBPROJECT OR LUASEC_INSTALL)
    install(FILES 
        src/ssl.lua
        DESTINATION ${LUAPATH}
    )

    install(FILES
        src/https.lua
        DESTINATION ${LUAPATH}/ssl
    )
endif()

# Export targets for find_package (only when not a subdirectory or LUASEC_INSTALL is ON)
if(NOT LUASEC_IS_SUBPROJECT OR LUASEC_INSTALL)
    include(CMakePackageConfigHelpers)

    # Create package config
    configure_package_config_file(
        luasecConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/luasecConfig.cmake
        INSTALL_DESTINATION lib/cmake/luasec
    )

    # Install package config
    install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/luasecConfig.cmake
        DESTINATION lib/cmake/luasec
    )

    # Export targets
    if(LUASEC_BUILD_STATIC OR LUASEC_BUILD_SHARED)
        install(EXPORT luasecTargets
            FILE luasecTargets.cmake
            NAMESPACE luasec::
            DESTINATION lib/cmake/luasec
        )
    endif()
endif()

# Print configuration summary
if(NOT LUASEC_IS_SUBPROJECT)
    message(STATUS "LuaSec Configuration:")
    message(STATUS "  Build shared library: ${LUASEC_BUILD_SHARED}")
    message(STATUS "  Build static library: ${LUASEC_BUILD_STATIC}")
    message(STATUS "  Use internal LuaSocket: ${LUASEC_WITH_LUASOCKET}")
    if(LUASEC_INSTALL)
        message(STATUS "  Lua path: ${LUAPATH}")
        message(STATUS "  Lua C path: ${LUACPATH}")
    endif()
else()
    message(STATUS "LuaSec (subdirectory): static=${LUASEC_BUILD_STATIC}, shared=${LUASEC_BUILD_SHARED}, install=${LUASEC_INSTALL}")
endif()
