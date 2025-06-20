#include "input_event_pan_gesture.h"

void sunaba::input::bindInputEventPanGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventPanGesture>("InputEventPanGesture",
        "new", sol::factories(
            []() { return new InputEventPanGesture(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent, sunaba::input::InputEventGesture>(),
        "delta", sol::property(&InputEventPanGesture::getDelta, &InputEventPanGesture::setDelta),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventPanGesture(godot::Object::cast_to<GodotInputEventPanGesture>(instance->getResource()));
        }
    );
}