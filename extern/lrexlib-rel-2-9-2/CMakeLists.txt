cmake_minimum_required(VERSION 3.14)
project(lrexlib VERSION 2.9.2 LANGUAGES C)

# Supported engines (regex backends)
set(REGEX_BACKENDS pcre2)

file(GLOB PCRE2_SRCS CONFIGURE_DEPENDS src/pcre2/*.c)
file(GLOB CORE_SRCS CONFIGURE_DEPENDS src/*.c)
add_library(pcre2_rexlib STATIC ${PCRE2_SRCS} ${CORE_SRCS})
target_include_directories(pcre2_rexlib PUBLIC src/pcre2)
target_include_directories(pcre2_rexlib PUBLIC src)


# HTML docs
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc)

add_custom_command(
    OUTPUT doc/index.html doc/manual.html
    COMMAND rst2html --stylesheet-path=doc/lrexlib.css --link-stylesheet --initial-header-level=2 --date --time README.rst doc/manual.html
    COMMAND ${CMAKE_COMMAND} -E copy README.rst doc/index.txt
    DEPENDS README.rst
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(doc DEPENDS doc/index.html doc/manual.html)

# Clean generated files
add_custom_target(extra_clean
    COMMAND ${CMAKE_COMMAND} -E rm -f doc/index.html doc/manual.html doc/index.txt *.rockspec release-notes
)

target_compile_definitions(pcre2_rexlib PRIVATE PCRE2_CODE_UNIT_WIDTH=8)
target_compile_definitions(pcre2_rexlib PRIVATE "PCRE2_CODE_UNIT_WIDTH=8")

add_subdirectory( pcre2 )

#/Users/lucasabbas/build_sunaba_Darwin-Universal/extern/lrexlib-rel-2-9-2/pcre2/include
set(PCRE2_INCLUDE_DIRECTORY "${PROJECT_BINARY_DIR}/pcre2")

if (NOT PCRE2_INCLUDE_DIRECTORY)
    message(FATAL_ERROR "PCRE2 include directory not found. Please ensure PCRE2 is properly installed and PCRE2_INCLUDE_DIRECTORY is set.")
endif()
message(STATUS "PCRE2_INCLUDE_DIR: ${PCRE2_INCLUDE_DIRECTORY}")

target_include_directories(pcre2_rexlib PRIVATE pcre2/src)
target_include_directories(pcre2_rexlib PRIVATE ${PCRE2_INCLUDE_DIRECTORY})
include_directories(${PCRE2_INCLUDE_DIRECTORY})
target_link_libraries(pcre2_rexlib PRIVATE pcre2-8-static)
