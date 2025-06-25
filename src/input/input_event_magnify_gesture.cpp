#include "input_event_magnify_gesture.h"

void lucidware::input::bindInputEventMagnifyGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventMagnifyGesture>("InputEventMagnifyGesture",
        "new", sol::factories(
            []() { return new InputEventMagnifyGesture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::input::InputEvent, lucidware::input::InputEventGesture>(),
        "factor", sol::property(&InputEventMagnifyGesture::getFactor, &InputEventMagnifyGesture::setFactor),
        "cast", [](lucidware::core::Resource* instance) {
            return new InputEventMagnifyGesture(godot::Object::cast_to<GodotInputEventMagnifyGesture>(instance->getResource()));
        }
    );
}