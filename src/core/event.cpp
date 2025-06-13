#include "event.h"

using namespace godot;

void sunaba::core::bindEvent(sol::state &lua) {
    lua.new_usertype<sunaba::core::Event>("Event",
        sol::constructors<sunaba::core::Event()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "link", [](sunaba::core::Event& event, sol::object func) {
            event.connectLua(func.as<sol::function>());
        },
        "unlink", [](sunaba::core::Event& event, sol::object func) {
            event.disconnectLua(func.as<sol::function>());
        },
        "emit", &sunaba::core::Event::emitLua,
        "clear", &sunaba::core::Event::clear
    );
}