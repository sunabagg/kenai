# LuaSocket helper library (internal version)
set(LUASOCKET_SOURCES
    io.c
    buffer.c
    timeout.c
    usocket.c
)

set(LUASOCKET_HEADERS
    buffer.h
    io.h
    socket.h
    timeout.h
    usocket.h
    wsocket.h
)

# Create static library for LuaSocket
add_library(luasocket_static STATIC ${LUASOCKET_SOURCES})

set_target_properties(luasocket_static PROPERTIES
    OUTPUT_NAME luasocket
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Compiler flags
target_compile_options(luasocket_static PRIVATE
    -Wall
    -pedantic
    -O2
    -fPIC
)

# Add debug definition
target_compile_definitions(luasocket_static PRIVATE
    -DLUASOCKET_DEBUG
)

# Include directories for Lua
if(LUA_FOUND)
    target_include_directories(luasocket_static PRIVATE ${LUA_INCLUDE_DIR})
else()
    target_include_directories(luasocket_static PRIVATE ${LUA_INCLUDE_DIRS})
endif()

# Install static library and headers 
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    # Building standalone
    install(TARGETS luasocket_static
        EXPORT luasecTargets
        ARCHIVE DESTINATION lib
    )
    
    install(FILES ${LUASOCKET_HEADERS}
        DESTINATION include/luasocket
    )
else()
    # When building as part of luasec, only install if not a subdirectory or LUASEC_INSTALL is ON
    if(NOT LUASEC_IS_SUBPROJECT OR LUASEC_INSTALL)
        install(TARGETS luasocket_static
            EXPORT luasecTargets
            ARCHIVE DESTINATION lib
        )
    endif()
endif()
