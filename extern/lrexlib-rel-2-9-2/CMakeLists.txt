cmake_minimum_required(VERSION 3.14)
project(lrexlib VERSION 2.9.2 LANGUAGES C)

# Supported engines (regex backends)
set(REGEX_BACKENDS pcre2)

# Collect all sources
foreach(backend ${REGEX_BACKENDS})
    file(GLOB_RECURSE BACKEND_SRCS CONFIGURE_DEPENDS src/${backend}/*.c)
    add_library(${backend}_rexlib STATIC ${BACKEND_SRCS})
    target_include_directories(${backend}_rexlib PUBLIC src/${backend})
endforeach()

# Optional: create a "meta" target that depends on all
add_custom_target(lrexlib_all DEPENDS ${REGEX_BACKENDS})


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

find_path(PCRE2_INCLUDE_DIR pcre2.h
    HINTS /usr/include /usr/local/include /opt/homebrew/include
)

find_library(PCRE2_LIBRARY NAMES pcre2-8
    HINTS /usr/lib /usr/local/lib /opt/homebrew/lib
)

if(NOT PCRE2_INCLUDE_DIR OR NOT PCRE2_LIBRARY)
    message(FATAL_ERROR "PCRE2 not found. Please install PCRE2 development files.")
endif()

target_compile_definitions(pcre2_rexlib PRIVATE PCRE2_CODE_UNIT_WIDTH=8)
target_compile_definitions(pcre2_rexlib PRIVATE "PCRE2_CODE_UNIT_WIDTH=8")

target_include_directories(pcre2_rexlib PRIVATE ${PCRE2_INCLUDE_DIR})
target_link_libraries(pcre2_rexlib PRIVATE ${PCRE2_LIBRARY})
