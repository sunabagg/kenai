#include "input_event_pan_gesture.h"

void kenai::input::bindInputEventPanGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventPanGesture>("InputEventPanGesture",
        "new", sol::factories(
            []() { return new InputEventPanGesture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent, kenai::input::InputEventGesture>(),
        "delta", sol::property(&InputEventPanGesture::getDelta, &InputEventPanGesture::setDelta),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventPanGesture(godot::Object::cast_to<GodotInputEventPanGesture>(instance->getResource()));
        }
    );
}