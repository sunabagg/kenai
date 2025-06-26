#include "status_indicator.h"

namespace sunaba::desktop {
    void StatusIndicatorSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("pressed", "mouse_button", "mouse_position"), &StatusIndicatorSignalWrapper::pressed);
    }

    void StatusIndicatorSignalWrapper::pressed(int mouse_button, const Vector2i& mouse_position) {
        if (element != nullptr) {
            Array args;
            args.append(mouse_button);
            args.append(mouse_position);
            element->pressedEvent->emit(args);
        }
    }

    void bindStatusIndicator(sol::state& lua) {
        lua.new_usertype<StatusIndicator>("StatusIndicator",
            "new", sol::factories(
                []() { return new StatusIndicator(); }
            )
        );
    }
}