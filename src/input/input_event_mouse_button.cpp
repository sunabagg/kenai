#include "input_event_mouse_button.h"

void lucidware::input::bindInputEventMouseButton(sol::state_view& lua) {
    lua.new_usertype<InputEventMouseButton>("InputEventMouseButton",
        "new", sol::factories(
            []() { return new InputEventMouseButton(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent, lucidware::input::InputEventFromWindow, lucidware::input::InputEventWithModifiers, lucidware::input::InputEventMouse>(),
        "buttonIndex", sol::property(&InputEventMouseButton::getButtonIndex, &InputEventMouseButton::setButtonIndex),
        "canceled", sol::property(&InputEventMouseButton::isCanceled, &InputEventMouseButton::setCanceled),
        "doubleclick", sol::property(&InputEventMouseButton::isDoubleclick, &InputEventMouseButton::setDoubleclick),
        "factor", sol::property(&InputEventMouseButton::getFactor, &InputEventMouseButton::setFactor),
        "pressed", sol::property(&InputEventMouseButton::isPressed, &InputEventMouseButton::setPressed),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventMouseButton(godot::Object::cast_to<GodotInputEventMouseButton>(instance->getResource()));
        }
    );
}