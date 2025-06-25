#include "event.h"

using namespace godot;

void lucidware::core::bindEvent(sol::state &lua) {
    lua.new_usertype<lucidware::core::Event>("Event",
        "new", sol::factories(
            []() { return new lucidware::core::Event(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject>(),
        "connect", &lucidware::core::Event::connectLua,
        "disconnect", &lucidware::core::Event::disconnectLua,
        "emit", &lucidware::core::Event::emitLua,
        "clear", &lucidware::core::Event::clear
    );
}