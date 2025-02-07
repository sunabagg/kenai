target_sources( ${PROJECT_NAME}
    PRIVATE
        RegisterExtension.cpp
        app.h
        app.cpp
 )

add_subdirectory( core )
add_subdirectory( spatial )
add_subdirectory( tests )

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
