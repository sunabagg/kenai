cmake_minimum_required(VERSION 3.16)
project(luasec_test_with_shared)

# Test using LuaSec as a subdirectory with shared library enabled
set(LUASEC_BUILD_SHARED ON)
set(LUASEC_BUILD_STATIC ON)
set(LUASEC_INSTALL ON)
add_subdirectory(../luasec luasec_build)

# Create a simple test
add_executable(test_shared test.c)
target_link_libraries(test_shared luasec::ssl)

message(STATUS "Test project with shared enabled:")
if(TARGET ssl_static)
    message(STATUS "  - ssl_static: YES")
endif()
if(TARGET ssl_shared)
    message(STATUS "  - ssl_shared: YES") 
endif()
if(TARGET luasec::ssl)
    message(STATUS "  - luasec::ssl: YES (alias)")
endif()
