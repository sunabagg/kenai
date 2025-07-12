#include "input_event_screen_touch.h"

void kenai::input::bindInputEventScreenTouch(sol::state_view& lua) {
    lua.new_usertype<kenai::input::InputEventScreenTouch>("InputEventScreenTouch",
        "new", sol::factories(
            []() { return new kenai::input::InputEventScreenTouch(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent, kenai::input::InputEventFromWindow>(),
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
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventScreenTouch(godot::Object::cast_to<GodotInputEventScreenTouch>(instance->getResource()));
        }
    );
}