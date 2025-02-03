target_sources(${PROJECT_NAME} PRIVATE
        base_object.h
        base_object.cpp
        scene_system.h
        scene_system.cpp
        lua_bind.h
        lua_bind.cpp
        type_bind.cpp
        lua_function_wrapper.h
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "core"
)