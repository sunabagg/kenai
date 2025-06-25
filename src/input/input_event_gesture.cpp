#include "input_event_gesture.h"

void lucidfx::input::bindInputEventGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventGesture>("InputEventGesture",
        "new", sol::factories(
            []() { return new InputEventGesture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent>(),
        "position", sol::property(&InputEventGesture::getPosition, &InputEventGesture::setPosition),
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventGesture(godot::Object::cast_to<GodotInputEventGesture>(instance->getResource()));
        }
    );
}