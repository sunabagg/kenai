#include "bind_core_classes.h"

#include "scene_system.h"
#include "lua_bind.h"


void sunaba::core::bindCoreClasses(sol::state& lua) {
    bindSceneSystem(lua);
    bind_base_types(lua);
}