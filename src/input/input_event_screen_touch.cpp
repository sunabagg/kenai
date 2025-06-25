#include "input_event_screen_touch.h"

void lucidware::input::bindInputEventScreenTouch(sol::state_view& lua) {
    lua.new_usertype<lucidware::input::InputEventScreenTouch>("InputEventScreenTouch",
        "new", sol::factories(
            []() { return new lucidware::input::InputEventScreenTouch(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent, lucidware::input::InputEventFromWindow>(),
        "canceled", sol::property(
            &InputEventScreenTouch::isCanceled,
            &InputEventScreenTouch::setCanceled
        ),
        "doubleTap", sol::property(
            &InputEventScreenTouch::isDoubleTap,
            &InputEventScreenTouch::setDoubleTap
        ),
        "index", sol::property(
            &InputEventScreenTouch::getIndex,
            &InputEventScreenTouch::setIndex
        ),
        "position", sol::property(
            &InputEventScreenTouch::getPosition,
            &InputEventScreenTouch::setPosition
        ),
        "pressed", sol::property(
            &InputEventScreenTouch::isPressed,
            &InputEventScreenTouch::setPressed
        ),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventScreenTouch(godot::Object::cast_to<GodotInputEventScreenTouch>(instance->getResource()));
        }
    );
}