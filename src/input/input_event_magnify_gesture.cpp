#include "input_event_magnify_gesture.h"

void lucidfx::input::bindInputEventMagnifyGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventMagnifyGesture>("InputEventMagnifyGesture",
        "new", sol::factories(
            []() { return new InputEventMagnifyGesture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent, lucidfx::input::InputEventGesture>(),
        "factor", sol::property(&InputEventMagnifyGesture::getFactor, &InputEventMagnifyGesture::setFactor),
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventMagnifyGesture(godot::Object::cast_to<GodotInputEventMagnifyGesture>(instance->getResource()));
        }
    );
}