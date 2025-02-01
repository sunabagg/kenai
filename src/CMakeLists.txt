target_sources( ${PROJECT_NAME}
    PRIVATE
        RegisterExtension.cpp
)

add_subdirectory( core )

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
