#include "input_event_from_window.h"

void kenai::input::bindInputEventFromWindow(sol::state_view& lua) {
    lua.new_usertype<InputEventFromWindow>("InputEventFromWindow",
        "new", sol::factories(
            []() { return new InputEventFromWindow(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::input::InputEvent>(),
        "windowId", sol::property(&InputEventFromWindow::getWindowId, &InputEventFromWindow::setWindowId),
        "cast", [](kenai::core::Resource* instance) {
            return new InputEventFromWindow(godot::Object::cast_to<GodotInputEventFromWindow>(instance->getResource()));
        }
    );
}