#include "event.h"

using namespace godot;

void sunaba::core::bindEvent(sol::state &lua) {
    lua.new_usertype<sunaba::core::Event>("Event",
        "new", sol::factories(
            []() { return new sunaba::core::Event(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "connect", &sunaba::core::Event::connectLua,
        "disconnect", &sunaba::core::Event::disconnectLua,
        "emit", &sunaba::core::Event::emitLua,
        "clear", &sunaba::core::Event::clear
    );
}