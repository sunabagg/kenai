target_sources(${PROJECT_NAME} PRIVATE
        transform.h
        transform.cpp
        camera.h
        camera.cpp
        i_visual_instance.h
        i_visual_instance.cpp
)

add_subdirectory( mesh )

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "spatial"
)