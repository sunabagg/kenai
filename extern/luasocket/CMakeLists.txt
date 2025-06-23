cmake_minimum_required(VERSION 3.12)

# LuaSocket CMake Build System
# 
# This project can be used in several ways:
# 1. Standalone build: cmake .. && cmake --build .
# 2. As a subdirectory: add_subdirectory(extern/luasocket) in parent CMakeLists.txt
# 3. After installation: find_package(luasocket REQUIRED)
#
# When used as a subdirectory, targets are available as:
# - luasocket::static or luasocket::shared (recommended)
# - luasocket (alias to static by default)
# - Individual components: luasocket_socket_core_static, luasocket_mime_core_static, etc.

# Determine if this is being built as a subdirectory
if(DEFINED PROJECT_NAME)
    set(LUASOCKET_IS_SUBPROJECT TRUE)
else()
    set(LUASOCKET_IS_SUBPROJECT FALSE)
endif()

project(luasocket VERSION 3.0.0 LANGUAGES C)

# Options - adjust defaults based on whether this is a subproject
if(LUASOCKET_IS_SUBPROJECT)
    option(LUASOCKET_BUILD_SHARED "Build shared library" OFF)
    option(LUASOCKET_BUILD_STATIC "Build static library" ON)
    option(LUASOCKET_BUILD_UNIX "Build Unix domain sockets support" ON)
    option(LUASOCKET_BUILD_SERIAL "Build serial support" ON)
    option(LUASOCKET_INSTALL "Install luasocket" OFF)  # Default OFF for subprojects
    option(LUASOCKET_FORCE_INSTALL "Force install even when used as subproject" OFF)
    option(LUASOCKET_DEBUG "Enable debug mode" OFF)
else()
    option(LUASOCKET_BUILD_SHARED "Build shared library" OFF)
    option(LUASOCKET_BUILD_STATIC "Build static library" ON)
    option(LUASOCKET_BUILD_UNIX "Build Unix domain sockets support" ON)
    option(LUASOCKET_BUILD_SERIAL "Build serial support" ON)
    option(LUASOCKET_INSTALL "Install luasocket" ON)   # Default ON for standalone builds
    option(LUASOCKET_FORCE_INSTALL "Force install even when used as subproject" OFF)
    option(LUASOCKET_DEBUG "Enable debug mode" OFF)
endif()

# Find Lua - make it optional if parent project already found it
if(NOT TARGET Lua::Lua AND NOT LUA_FOUND)
    find_package(Lua REQUIRED)
endif()

# Set debug mode
if(LUASOCKET_DEBUG)
    set(LUASOCKET_DEBUG_FLAG "DEBUG")
else()
    set(LUASOCKET_DEBUG_FLAG "NODEBUG")
endif()

# Platform-specific settings
if(WIN32)
    set(SOCKET_PLATFORM_SOURCES src/wsocket.c)
    set(PLATFORM_LIBS ws2_32)
    set(PLATFORM_DEFINES
        -DWIN32
        -DNDEBUG
        -D_WINDOWS
        -D_USRDLL
        -D_CRT_SECURE_NO_WARNINGS
        -D_WINDLL
        -DWINVER=0x0501
    )
else()
    set(SOCKET_PLATFORM_SOURCES src/usocket.c)
    set(PLATFORM_LIBS)
    set(PLATFORM_DEFINES)
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin|FreeBSD")
        list(APPEND PLATFORM_DEFINES -DUNIX_HAS_SUN_LEN)
    endif()
    if(CMAKE_SYSTEM_NAME MATCHES "SunOS")
        list(APPEND PLATFORM_LIBS nsl socket resolv)
    endif()
endif()

# Common compiler flags
set(COMMON_DEFINES
    -DLUASOCKET_${LUASOCKET_DEBUG_FLAG}
    ${PLATFORM_DEFINES}
)

# Source files for socket core
set(SOCKET_CORE_SOURCES
    src/luasocket.c
    src/timeout.c
    src/buffer.c
    src/io.c
    src/auxiliar.c
    src/compat.c
    src/options.c
    src/inet.c
    src/except.c
    src/select.c
    src/tcp.c
    src/udp.c
    ${SOCKET_PLATFORM_SOURCES}
)

# Source files for MIME core
set(MIME_CORE_SOURCES
    src/mime.c
    src/compat.c
)

# Source files for Unix domain sockets
set(UNIX_SOURCES
    src/buffer.c
    src/auxiliar.c
    src/options.c
    src/timeout.c
    src/io.c
    src/usocket.c
    src/unixstream.c
    src/unixdgram.c
    src/compat.c
    src/unix.c
)

# Source files for serial support
set(SERIAL_SOURCES
    src/buffer.c
    src/compat.c
    src/auxiliar.c
    src/options.c
    src/timeout.c
    src/io.c
    src/usocket.c
    src/serial.c
)

# Create socket core library
if(LUASOCKET_BUILD_STATIC)
    add_library(luasocket_socket_core_static STATIC ${SOCKET_CORE_SOURCES})
    target_include_directories(luasocket_socket_core_static 
        PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include/luasocket>
        PRIVATE 
            ${LUA_INCLUDE_DIR}
    )
    target_compile_definitions(luasocket_socket_core_static PRIVATE ${COMMON_DEFINES})
    target_link_libraries(luasocket_socket_core_static PRIVATE ${PLATFORM_LIBS})
    
    # Set output name
    set_target_properties(luasocket_socket_core_static PROPERTIES 
        OUTPUT_NAME luasocket_socket_core
        ARCHIVE_OUTPUT_NAME luasocket_socket_core
    )
endif()

if(LUASOCKET_BUILD_SHARED)
    add_library(luasocket_socket_core_shared SHARED ${SOCKET_CORE_SOURCES})
    target_include_directories(luasocket_socket_core_shared 
        PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include/luasocket>
        PRIVATE 
            ${LUA_INCLUDE_DIR}
    )
    target_compile_definitions(luasocket_socket_core_shared PRIVATE ${COMMON_DEFINES})
    target_link_libraries(luasocket_socket_core_shared PRIVATE ${LUA_LIBRARIES} ${PLATFORM_LIBS})
    
    # Set output name
    set_target_properties(luasocket_socket_core_shared PROPERTIES 
        OUTPUT_NAME socket-${PROJECT_VERSION}
        LIBRARY_OUTPUT_NAME socket-${PROJECT_VERSION}
    )
endif()

# Create MIME core library
if(LUASOCKET_BUILD_STATIC)
    add_library(luasocket_mime_core_static STATIC ${MIME_CORE_SOURCES})
    target_include_directories(luasocket_mime_core_static 
        PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include/luasocket>
        PRIVATE 
            ${LUA_INCLUDE_DIR}
    )
    target_compile_definitions(luasocket_mime_core_static PRIVATE ${COMMON_DEFINES})
    
    # Set output name
    set_target_properties(luasocket_mime_core_static PROPERTIES 
        OUTPUT_NAME luasocket_mime_core
        ARCHIVE_OUTPUT_NAME luasocket_mime_core
    )
endif()

if(LUASOCKET_BUILD_SHARED)
    add_library(luasocket_mime_core_shared SHARED ${MIME_CORE_SOURCES})
    target_include_directories(luasocket_mime_core_shared 
        PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include/luasocket>
        PRIVATE 
            ${LUA_INCLUDE_DIR}
    )
    target_compile_definitions(luasocket_mime_core_shared PRIVATE ${COMMON_DEFINES})
    target_link_libraries(luasocket_mime_core_shared PRIVATE ${LUA_LIBRARIES})
    
    # Set MIME version
    set(MIME_VERSION "1.0.3")
    set_target_properties(luasocket_mime_core_shared PROPERTIES 
        OUTPUT_NAME mime-${MIME_VERSION}
        LIBRARY_OUTPUT_NAME mime-${MIME_VERSION}
    )
endif()

# Unix domain sockets (only on Unix-like systems)
if(LUASOCKET_BUILD_UNIX AND NOT WIN32)
    if(LUASOCKET_BUILD_STATIC)
        add_library(luasocket_unix_static STATIC ${UNIX_SOURCES})
        target_include_directories(luasocket_unix_static 
            PUBLIC 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                $<INSTALL_INTERFACE:include/luasocket>
            PRIVATE 
                ${LUA_INCLUDE_DIR}
        )
        target_compile_definitions(luasocket_unix_static PRIVATE ${COMMON_DEFINES})
        
        set_target_properties(luasocket_unix_static PROPERTIES 
            OUTPUT_NAME luasocket_unix
            ARCHIVE_OUTPUT_NAME luasocket_unix
        )
    endif()
    
    if(LUASOCKET_BUILD_SHARED)
        add_library(luasocket_unix_shared SHARED ${UNIX_SOURCES})
        target_include_directories(luasocket_unix_shared 
            PUBLIC 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                $<INSTALL_INTERFACE:include/luasocket>
            PRIVATE 
                ${LUA_INCLUDE_DIR}
        )
        target_compile_definitions(luasocket_unix_shared PRIVATE ${COMMON_DEFINES})
        target_link_libraries(luasocket_unix_shared PRIVATE ${LUA_LIBRARIES})
        
        set_target_properties(luasocket_unix_shared PROPERTIES 
            OUTPUT_NAME unix
            LIBRARY_OUTPUT_NAME unix
        )
    endif()
endif()

# Serial support
if(LUASOCKET_BUILD_SERIAL AND NOT WIN32)

    if(LUASOCKET_BUILD_STATIC)
        add_library(luasocket_serial_static STATIC ${SERIAL_SOURCES})
        target_include_directories(luasocket_serial_static 
            PUBLIC 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                $<INSTALL_INTERFACE:include/luasocket>
            PRIVATE 
                ${LUA_INCLUDE_DIR}
        )
        target_compile_definitions(luasocket_serial_static PRIVATE ${COMMON_DEFINES})
        
        set_target_properties(luasocket_serial_static PROPERTIES 
            OUTPUT_NAME luasocket_serial
            ARCHIVE_OUTPUT_NAME luasocket_serial
        )
    endif()
    
    if(LUASOCKET_BUILD_SHARED)
        add_library(luasocket_serial_shared SHARED ${SERIAL_SOURCES})
        target_include_directories(luasocket_serial_shared 
            PUBLIC 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                $<INSTALL_INTERFACE:include/luasocket>
            PRIVATE 
                ${LUA_INCLUDE_DIR}
        )
        target_compile_definitions(luasocket_serial_shared PRIVATE ${COMMON_DEFINES})
        target_link_libraries(luasocket_serial_shared PRIVATE ${LUA_LIBRARIES})
        
        set_target_properties(luasocket_serial_shared PROPERTIES 
            OUTPUT_NAME serial
            LIBRARY_OUTPUT_NAME serial
        )
    endif()
endif()

# Create combined static library for convenience
if(LUASOCKET_BUILD_STATIC)
    add_library(luasocket_static INTERFACE)
    target_link_libraries(luasocket_static INTERFACE 
        luasocket_socket_core_static 
        luasocket_mime_core_static
    )
    
    if(LUASOCKET_BUILD_UNIX AND NOT WIN32)
        target_link_libraries(luasocket_static INTERFACE luasocket_unix_static)
    endif()
    
    if(LUASOCKET_BUILD_SERIAL AND NOT WIN32)

        target_link_libraries(luasocket_static INTERFACE luasocket_serial_static)
    endif()
    
    # Propagate include directories and dependencies for static library usage
    target_include_directories(luasocket_static INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/luasocket>
    )
    
    # Alias for easier usage
    add_library(luasocket::static ALIAS luasocket_static)
    
    # For subproject usage, also create a simple "luasocket" alias
    if(LUASOCKET_IS_SUBPROJECT)
        add_library(luasocket ALIAS luasocket_static)
        add_library(luasocket::luasocket ALIAS luasocket_static)
    endif()
endif()

# Create combined shared library for convenience
if(LUASOCKET_BUILD_SHARED)
    add_library(luasocket_shared INTERFACE)
    target_link_libraries(luasocket_shared INTERFACE 
        luasocket_socket_core_shared 
        luasocket_mime_core_shared
    )
    
    if(LUASOCKET_BUILD_UNIX AND NOT WIN32)
        target_link_libraries(luasocket_shared INTERFACE luasocket_unix_shared)
    endif()
    
    if(LUASOCKET_BUILD_SERIAL AND NOT WIN32)

        target_link_libraries(luasocket_shared INTERFACE luasocket_serial_shared)
    endif()
    
    # Propagate include directories for shared library usage
    target_include_directories(luasocket_shared INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/luasocket>
    )
    
    # Alias for easier usage
    add_library(luasocket::shared ALIAS luasocket_shared)
    
    # For subproject usage when only shared is built
    if(LUASOCKET_IS_SUBPROJECT AND NOT LUASOCKET_BUILD_STATIC)
        add_library(luasocket ALIAS luasocket_shared)
        add_library(luasocket::luasocket ALIAS luasocket_shared)
    endif()
endif()

# Installation (only when not used as subproject, unless explicitly requested)
if(LUASOCKET_INSTALL AND (NOT LUASOCKET_IS_SUBPROJECT OR LUASOCKET_FORCE_INSTALL))
    include(GNUInstallDirs)
    
    # Install headers
    install(FILES
        src/auxiliar.h
        src/buffer.h
        src/compat.h
        src/except.h
        src/inet.h
        src/io.h
        src/luasocket.h
        src/mime.h
        src/options.h
        src/pierror.h
        src/select.h
        src/socket.h
        src/timeout.h
        src/tcp.h
        src/udp.h
        src/unix.h
        src/usocket.h
        src/wsocket.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/luasocket
    )
    
    # Install Lua files
    install(FILES
        src/ltn12.lua
        src/socket.lua
        src/mime.lua
        DESTINATION ${CMAKE_INSTALL_DATADIR}/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
    )
    
    install(FILES
        src/http.lua
        src/url.lua
        src/tp.lua
        src/ftp.lua
        src/headers.lua
        src/smtp.lua
        DESTINATION ${CMAKE_INSTALL_DATADIR}/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}/socket
    )
    
    # Install libraries
    if(LUASOCKET_BUILD_STATIC)
        install(TARGETS 
            luasocket_socket_core_static 
            luasocket_mime_core_static
            EXPORT luasocketTargets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )
        
        if(LUASOCKET_BUILD_UNIX AND NOT WIN32)
            install(TARGETS luasocket_unix_static
                EXPORT luasocketTargets
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            )
        endif()
        
        if(LUASOCKET_BUILD_SERIAL AND NOT WIN32)

            install(TARGETS luasocket_serial_static
                EXPORT luasocketTargets
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            )
        endif()
    endif()
    
    if(LUASOCKET_BUILD_SHARED)
        install(TARGETS 
            luasocket_socket_core_shared 
            luasocket_mime_core_shared
            EXPORT luasocketTargets
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
        
        if(LUASOCKET_BUILD_UNIX AND NOT WIN32)
            install(TARGETS luasocket_unix_shared
                EXPORT luasocketTargets
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            )
        endif()
        
        if(LUASOCKET_BUILD_SERIAL AND NOT WIN32)

            install(TARGETS luasocket_serial_shared
                EXPORT luasocketTargets
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            )
        endif()
    endif()
    
    # Generate and install CMake config files
    include(CMakePackageConfigHelpers)
    
    # Create package config file
    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/luasocketConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/luasocketConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/luasocket
    )
    
    # Create package version file
    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/luasocketConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )
    
    # Install CMake files
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/luasocketConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/luasocketConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/luasocket
    )
    
    # Install targets
    install(EXPORT luasocketTargets
        FILE luasocketTargets.cmake
        NAMESPACE luasocket::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/luasocket
    )
endif()

# Add test target (optional)
if(BUILD_TESTING)
    enable_testing()
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/hello.lua")
        add_test(NAME luasocket_test
            COMMAND ${LUA_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/test/hello.lua"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()
endif()
