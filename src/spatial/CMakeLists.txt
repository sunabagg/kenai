target_sources(${PROJECT_NAME} PRIVATE
        transform.h
        transform.cpp
        camera.h
        camera.cpp
        i_visual_instance.h
        i_visual_instance.cpp
        i_geometry_instance.h
        i_geometry_instance.cpp
        bind_spatial_classes.h
        bind_spatial_classes.cpp
        fog_material.h
        fog_material.cpp
        base_material3d.h
        base_material3d.cpp
        cubemap.h
        cubemap.cpp
        cubemap_array.h
        cubemap_array.cpp
        curve3d.h
        curve3d.cpp
        occluder3d.h
        occluder3d.cpp
        orm_material3d.h
        orm_material3d.cpp
        panorama_sky_material.h
        panorama_sky_material.cpp
        physical_sky_material.h
        physical_sky_material.cpp
        array_occluder3d.h
        array_occluder3d.cpp
        polygon_occluder3d.h
        polygon_occluder3d.cpp
        box_occluder3d.h
        box_occluder3d.cpp
        procedural_sky_material.h
        procedural_sky_material.cpp
        quad_occluder3d.h
        quad_occluder3d.cpp
        skeleton_profile.h
        skeleton_profile.cpp
        skeleton_profile_humanoid.h
        skeleton_profile_humanoid.cpp
        skin.h
        skin.cpp
)

add_subdirectory( mesh )

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "spatial"
)