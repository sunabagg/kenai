# LuaSocket static library (if using internal LuaSocket)
if(LUASEC_WITH_LUASOCKET)
    add_subdirectory(luasocket)
endif()

# LuaSec source files
set(LUASEC_SOURCES
    options.c
    x509.c
    context.c
    ssl.c
    config.c
    ec.c
)

set(LUASEC_HEADERS
    options.h
    context.h
    ec.h
    ssl.h
    x509.h
    compat.h
)

# Compiler definitions
set(LUASEC_DEFINITIONS "")
if(LUASEC_WITH_LUASOCKET)
    list(APPEND LUASEC_DEFINITIONS -DWITH_LUASOCKET)
endif()

# Create shared library
if(LUASEC_BUILD_SHARED)
    add_library(ssl_shared SHARED ${LUASEC_SOURCES})
    set_target_properties(ssl_shared PROPERTIES
        OUTPUT_NAME ssl
        PREFIX ""  # No lib prefix for Lua modules
        SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX}
    )
    
    # Link libraries for shared version
    target_link_libraries(ssl_shared
        OpenSSL::SSL
        OpenSSL::Crypto
    )
    
    if(LUASEC_WITH_LUASOCKET)
        target_link_libraries(ssl_shared luasocket_static)
        target_include_directories(ssl_shared PRIVATE luasocket)
    endif()
    
    # Platform-specific settings
    if(APPLE)
        set_target_properties(ssl_shared PROPERTIES
            BUNDLE TRUE
            BUNDLE_EXTENSION "so"
            LINK_FLAGS "-undefined dynamic_lookup"
        )
    endif()
    
    # Apply definitions
    target_compile_definitions(ssl_shared PRIVATE ${LUASEC_DEFINITIONS})
    
    # Compiler flags
    target_compile_options(ssl_shared PRIVATE
        -Wall
        -pedantic
        -fPIC
    )

    
    
    # Install shared library (only when not a subdirectory or LUASEC_INSTALL is ON)
    if(NOT LUASEC_IS_SUBPROJECT OR LUASEC_INSTALL)
        install(TARGETS ssl_shared
            EXPORT luasecTargets
            LIBRARY DESTINATION ${LUACPATH}
            RUNTIME DESTINATION ${LUACPATH}
        )
    endif()
endif()

# Create static library
if(LUASEC_BUILD_STATIC)
    add_library(ssl_static STATIC ${LUASEC_SOURCES})
    set_target_properties(ssl_static PROPERTIES
        OUTPUT_NAME ssl
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/static
    )
    
    # Link libraries for static version
    target_link_libraries(ssl_static
        OpenSSL::SSL
        OpenSSL::Crypto
    )
    
    if(LUASEC_WITH_LUASOCKET)
        target_link_libraries(ssl_static luasocket_static)
        target_include_directories(ssl_static PRIVATE luasocket)
    endif()
    
    # Apply definitions
    target_compile_definitions(ssl_static PRIVATE ${LUASEC_DEFINITIONS})
    
    # Compiler flags
    target_compile_options(ssl_static PRIVATE
        -Wall
        -pedantic
        -O2
        -fPIC
    )
    
    # Install static library (only when not a subdirectory or LUASEC_INSTALL is ON)
    if(NOT LUASEC_IS_SUBPROJECT OR LUASEC_INSTALL)
        install(TARGETS ssl_static
            EXPORT luasecTargets
            ARCHIVE DESTINATION lib
        )
        
        # Install headers for static library usage
        install(FILES ${LUASEC_HEADERS}
            DESTINATION include/luasec
        )
    endif()
endif()

# Create an alias target for easier linking
if(LUASEC_BUILD_STATIC)
    add_library(luasec::ssl ALIAS ssl_static)
elseif(LUASEC_BUILD_SHARED)
    add_library(luasec::ssl ALIAS ssl_shared)
endif()
