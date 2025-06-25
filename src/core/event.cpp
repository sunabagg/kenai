#include "event.h"

using namespace godot;

void lucidfx::core::bindEvent(sol::state &lua) {
    lua.new_usertype<lucidfx::core::Event>("Event",
        "new", sol::factories(
            []() { return new lucidfx::core::Event(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject>(),
        "connect", &lucidfx::core::Event::connectLua,
        "disconnect", &lucidfx::core::Event::disconnectLua,
        "emit", &lucidfx::core::Event::emitLua,
        "clear", &lucidfx::core::Event::clear
    );
}