#include "input_event_screen_touch.h"

void sunaba::input::bindInputEventScreenTouch(sol::state_view& lua) {
    lua.new_usertype<sunaba::input::InputEventScreenTouch>("InputEventScreenTouch",
        "new", sol::factories(
            []() { return new sunaba::input::InputEventScreenTouch(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent, sunaba::input::InputEventFromWindow>(),
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
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventScreenTouch(godot::Object::cast_to<GodotInputEventScreenTouch>(instance->getResource()));
        }
    );
}