#include "input_event_screen_touch.h"

void lucidfx::input::bindInputEventScreenTouch(sol::state_view& lua) {
    lua.new_usertype<lucidfx::input::InputEventScreenTouch>("InputEventScreenTouch",
        "new", sol::factories(
            []() { return new lucidfx::input::InputEventScreenTouch(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent, lucidfx::input::InputEventFromWindow>(),
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
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventScreenTouch(godot::Object::cast_to<GodotInputEventScreenTouch>(instance->getResource()));
        }
    );
}