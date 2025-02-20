#include "bind_core_classes.h"

#include "scene_system.h"
#include "lua_bind.h"
#include "./io/bind_binary_classes.h"
#include "./io/bind_io_classes.h"

void sunaba::core::bindCoreClasses(sol::state& lua) {
    sunaba::core::io::bindBinaryClasses(lua);
    bind_base_types(lua);
    bindSceneSystem(lua);
    sunaba::core::io::bindIoClasses(lua);
}