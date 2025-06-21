cmake_minimum_required(VERSION 3.12)
project(luasocket_example)

# Find required packages
find_package(Lua REQUIRED)

# Include luasocket build directory
add_subdirectory(.. luasocket_build)

# Create test executable
add_executable(test_static test_static.c)

# Link against Lua and luasocket static libraries
target_link_libraries(test_static 
    PRIVATE
        ${LUA_LIBRARIES}
        luasocket_socket_core_static
        luasocket_mime_core_static
)

target_include_directories(test_static 
    PRIVATE 
        ${LUA_INCLUDE_DIR}
)
