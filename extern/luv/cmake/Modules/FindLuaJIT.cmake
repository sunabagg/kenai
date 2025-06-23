# Findluajit.cmake
# Locate luajit library
# This module defines
#  LUAJIT_INCLUDE_DIR, where to find luajit.h, etc.
#  LUAJIT_LIBRARIES, the libraries to link against to use luajit.
#  LUAJIT_FOUND, If false, do not try to use luajit.

find_path(LUAJIT_INCLUDE_DIR luajit.h
        PATHS
        ${CMAKE_PREFIX_PATH}
        PATH_SUFFIXES include
)

find_library(LUAJIT_LIBRARIES NAMES luajit
        PATHS
        ${CMAKE_PREFIX_PATH}
        PATH_SUFFIXES lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(luajit DEFAULT_MSG LUAJIT_INCLUDE_DIR LUAJIT_LIBRARIES)

if(LUAJIT_FOUND)
    set(LUAJIT_LIBRARIES ${LUAJIT_LIBRARIES})
    set(LUAJIT_INCLUDE_DIRS ${LUAJIT_INCLUDE_DIR})
else()
    set(LUAJIT_LIBRARIES)
    set(LUAJIT_INCLUDE_DIRS)
endif()