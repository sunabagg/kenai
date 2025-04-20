#include "event.h"

void sunaba::core::bindEvent(sol::state &lua) {
    lua.new_usertype<sunaba::core::Event>("Event",
        sol::constructors<sunaba::core::Event()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "connect", &sunaba::core::Event::connectLua,
        "disconnect", &sunaba::core::Event::disconnectLua,
        "emit", &sunaba::core::Event::emitLua
    );
}