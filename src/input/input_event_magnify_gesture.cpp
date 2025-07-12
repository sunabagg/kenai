#include "input_event_magnify_gesture.h"

void kenai::input::bindInputEventMagnifyGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventMagnifyGesture>("InputEventMagnifyGesture",
        "new", sol::factories(
            []() { return new InputEventMagnifyGesture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent, kenai::input::InputEventGesture>(),
        "factor", sol::property(&InputEventMagnifyGesture::getFactor, &InputEventMagnifyGesture::setFactor),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventMagnifyGesture(godot::Object::cast_to<GodotInputEventMagnifyGesture>(instance->getResource()));
        }
    );
}