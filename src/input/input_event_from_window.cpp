#include "input_event_from_window.h"

void lucidfx::input::bindInputEventFromWindow(sol::state_view& lua) {
    lua.new_usertype<InputEventFromWindow>("InputEventFromWindow",
        "new", sol::factories(
            []() { return new InputEventFromWindow(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::input::InputEvent>(),
        "windowId", sol::property(&InputEventFromWindow::getWindowId, &InputEventFromWindow::setWindowId),
        "cast", [](lucidfx::core::Resource* instance) {
            return new InputEventFromWindow(godot::Object::cast_to<GodotInputEventFromWindow>(instance->getResource()));
        }
    );
}