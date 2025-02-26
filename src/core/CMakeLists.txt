target_sources(${PROJECT_NAME} PRIVATE
        convert_godot_lua.h
        convert_godot_lua.cpp
        base_object.h
        base_object.cpp
        scene_system.h
        scene_system.cpp
        scene_node.h
        scene_node.cpp
        lua_bind.h
        lua_bind.cpp
        type_bind.cpp
        lua_function_wrapper.h
        bind_core_classes.h
        bind_core_classes.cpp
        string_utils.h
        resource.h
        resource.cpp
        texture.h
        texture.cpp
        image.h
        image.cpp
        texture2d.h
        texture2d.cpp
)

add_subdirectory(io)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "core"
)