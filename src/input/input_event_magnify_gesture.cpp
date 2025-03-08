#include "input_event_magnify_gesture.h"

void sunaba::input::bindInputEventMagnifyGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventMagnifyGesture>("InputEventMagnifyGesture",
        sol::constructors<InputEventMagnifyGesture(), InputEventMagnifyGesture(GodotInputEventMagnifyGesture*)>(),
        sol::base_classes, sol::bases<sunaba::input::InputEventGesture>(),
        "factor", sol::property(&InputEventMagnifyGesture::getFactor, &InputEventMagnifyGesture::setFactor),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventMagnifyGesture(dynamic_cast<GodotInputEventMagnifyGesture*>(instance->getResource()));
        }
    );
}