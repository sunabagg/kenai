#include "event.h"

using namespace godot;

void sunaba::core::bindEvent(sol::state &lua) {
    lua.new_usertype<sunaba::core::Event>("Event",
        sol::constructors<sunaba::core::Event()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "connect", &sunaba::core::Event::connectLuaTable,
        "disconnect", &sunaba::core::Event::disconnectLuaTable,
        "emit", &sunaba::core::Event::emitLua,
        "clear", &sunaba::core::Event::clear
    );
}