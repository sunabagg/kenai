cmake_minimum_required(VERSION 3.10)
project(hx-lua-simdjson)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Find Lua
find_package(Lua REQUIRED)

# Find pthread (needed for simdjson)
find_package(Threads REQUIRED)

# Source files
set(SOURCES
    src/hxluasimdjson.cpp
    src/simdjson.cpp
)

# Include directories
include_directories(
    ${LUA_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# Shared library output name based on OS
if(WIN32)
    set(LIB_EXT dll)
else()
    set(LIB_EXT so)
endif()

set(TARGET_NAME "hxsimdjson.${LIB_EXT}")

# Create the shared library
add_library(${TARGET_NAME} SHARED ${SOURCES})

# Link against Lua and pthread
target_link_libraries(${TARGET_NAME} ${LUA_LIBRARIES} Threads::Threads)

# Installation
install(TARGETS ${TARGET_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Clean up
set_target_properties(${TARGET_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
