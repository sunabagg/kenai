#include "input_event_gesture.h"

void kenai::input::bindInputEventGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventGesture>("InputEventGesture",
        "new", sol::factories(
            []() { return new InputEventGesture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent>(),
        "position", sol::property(&InputEventGesture::getPosition, &InputEventGesture::setPosition),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventGesture(godot::Object::cast_to<GodotInputEventGesture>(instance->getResource()));
        }
    );
}