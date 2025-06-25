#include "input_event_from_window.h"

void lucidware::input::bindInputEventFromWindow(sol::state_view& lua) {
    lua.new_usertype<InputEventFromWindow>("InputEventFromWindow",
        "new", sol::factories(
            []() { return new InputEventFromWindow(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent>(),
        "windowId", sol::property(&InputEventFromWindow::getWindowId, &InputEventFromWindow::setWindowId),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventFromWindow(godot::Object::cast_to<GodotInputEventFromWindow>(instance->getResource()));
        }
    );
}