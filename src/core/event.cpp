#include "event.h"

using namespace godot;

void sunaba::core::bindEvent(sol::state &lua) {
    lua.new_usertype<sunaba::core::Event>("Event",
        sol::constructors<sunaba::core::Event()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "connect", &sunaba::core::Event::connectLua,
        "disconnect", &sunaba::core::Event::disconnectLua,
        "emit", &sunaba::core::Event::emitLua,
        "clear", &sunaba::core::Event::clear
    );
}

sunaba::core::Event* sunaba::core::Event::createFromSignal(godot::Signal signal) {
    EventBridge* eventBridge = memnew(EventBridge);
    Callable callable(eventBridge, "callEvent");
    signal.connect(callable);
    return eventBridge->event;
}