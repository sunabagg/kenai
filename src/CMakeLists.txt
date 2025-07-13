target_sources( ${PROJECT_NAME}
    PRIVATE
        RegisterExtension.cpp
        app.h
        app.cpp
 )

add_subdirectory( core )
add_subdirectory( desktop )
add_subdirectory( input )
add_subdirectory( spatial )
add_subdirectory( tests )
add_subdirectory( ui )
add_subdirectory( audio )
add_subdirectory( networking )

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
