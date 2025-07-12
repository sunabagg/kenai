#include "event.h"

using namespace godot;

void kenai::core::bindEvent(sol::state &lua) {
    lua.new_usertype<kenai::core::Event>("Event",
        "new", sol::factories(
            []() { return new kenai::core::Event(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject>(),
        "connect", &kenai::core::Event::connectLua,
        "disconnect", &kenai::core::Event::disconnectLua,
        "emit", &kenai::core::Event::emitLua,
        "clear", &kenai::core::Event::clear
    );
}