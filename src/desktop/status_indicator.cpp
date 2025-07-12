#include "status_indicator.h"

namespace kenai::desktop {
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
            ),
            sol::base_classes, sol::bases<BaseObject, Element>(),
            "icon", sol::property(
                &StatusIndicator::getIcon,
                &StatusIndicator::setIcon
            ),
            "menu", sol::property(
                &StatusIndicator::getMenu,
                &StatusIndicator::setMenu
            ),
            "tooltip", sol::property(
                &StatusIndicator::getTooltip,
                &StatusIndicator::setTooltip
            ),
            "visible", sol::property(
                &StatusIndicator::getVisible,
                &StatusIndicator::setVisible
            ),
            "pressed", sol::property(
                &StatusIndicator::getPressedEvent,
                &StatusIndicator::setPressedEvent
            ),
            "getRect", &StatusIndicator::getRect,
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<StatusIndicator*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                StatusIndicatorNode* indicator = Object::cast_to<StatusIndicatorNode>(e->getNode());
                return new StatusIndicator(indicator);
            }
        );
    }
}