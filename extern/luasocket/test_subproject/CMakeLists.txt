cmake_minimum_required(VERSION 3.12)
project(test_parent_project)

# Add luasocket as a subdirectory
add_subdirectory(.. luasocket)

# Find Lua for our test
find_package(Lua REQUIRED)

# Create a simple test executable
add_executable(test_subdir_usage test_main.c)

# Link against luasocket using the convenient alias
target_link_libraries(test_subdir_usage 
    PRIVATE 
        luasocket::static
        ${LUA_LIBRARIES}
)

target_include_directories(test_subdir_usage 
    PRIVATE 
        ${LUA_INCLUDE_DIR}
)

# Print some information about the targets
message(STATUS "LuaSocket available targets:")
message(STATUS "  - luasocket::static")
message(STATUS "  - luasocket::shared (if enabled)")
message(STATUS "  - luasocket (alias)")
message(STATUS "  - Individual components available")
