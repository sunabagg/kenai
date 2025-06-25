#include "input_event_pan_gesture.h"

void lucidware::input::bindInputEventPanGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventPanGesture>("InputEventPanGesture",
        "new", sol::factories(
            []() { return new InputEventPanGesture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent, lucidware::input::InputEventGesture>(),
        "delta", sol::property(&InputEventPanGesture::getDelta, &InputEventPanGesture::setDelta),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventPanGesture(godot::Object::cast_to<GodotInputEventPanGesture>(instance->getResource()));
        }
    );
}