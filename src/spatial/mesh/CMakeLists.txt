target_sources(${PROJECT_NAME} PRIVATE
        mesh_renderer.h
        mesh_renderer.cpp
        box.h
        box.cpp
        sphere.h
        sphere.cpp
        capsule.h
        capsule.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "mesh"
)