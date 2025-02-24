target_sources(${PROJECT_NAME} PRIVATE
        element.h
)

add_subdirectory( mesh )

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "ui"
)