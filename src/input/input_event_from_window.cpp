#include "input_event_from_window.h"

void sunaba::input::bindInputEventFromWindow(sol::state_view& lua) {
    lua.new_usertype<InputEventFromWindow>("InputEventFromWindow",
        "new", sol::factories(
            []() { return new InputEventFromWindow(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::input::InputEvent>(),
        "windowId", sol::property(&InputEventFromWindow::getWindowId, &InputEventFromWindow::setWindowId),
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEventFromWindow(godot::Object::cast_to<GodotInputEventFromWindow>(instance->getResource()));
        }
    );
}