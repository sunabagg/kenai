target_sources(${PROJECT_NAME} PRIVATE
        mesh_renderer.cpp
        box.cpp
        sphere.cpp
        capsule.cpp
        bind_mesh_classes.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "mesh"
)