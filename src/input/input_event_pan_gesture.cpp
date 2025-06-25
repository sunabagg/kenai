#include "input_event_pan_gesture.h"

void lucidfx::input::bindInputEventPanGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventPanGesture>("InputEventPanGesture",
        "new", sol::factories(
            []() { return new InputEventPanGesture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent, lucidfx::input::InputEventGesture>(),
        "delta", sol::property(&InputEventPanGesture::getDelta, &InputEventPanGesture::setDelta),
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventPanGesture(godot::Object::cast_to<GodotInputEventPanGesture>(instance->getResource()));
        }
    );
}