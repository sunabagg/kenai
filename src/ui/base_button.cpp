#include "base_button.h"

namespace sunaba::ui {
    void bindBaseButton(sol::state &lua) {
        lua.new_usertype<BaseButton>("BaseButton",
            sol::constructors<BaseButton(), BaseButton(BaseButtonNode*), BaseButton(BaseButtonProxy*)>(),
            sol::base_classes, sol::bases<Control>(),
            "actionMode", sol::property(
                &BaseButton::getActionMode,
                &BaseButton::setActionMode
            ),
            "buttonMask", sol::property(
                &BaseButton::getButtonMask,
                &BaseButton::setButtonMask
            ),
            "buttonPressed", sol::property(
                &BaseButton::getButtonPressed,
                &BaseButton::setButtonPressed
            ),
            "disabled", sol::property(
                &BaseButton::getDisabled,
                &BaseButton::setDisabled
            ),
            "focusMode", sol::property(
                &BaseButton::getFocusMode,
                &BaseButton::setFocusMode
            ),
            "keepPressedOutside", sol::property(
                &BaseButton::getKeepPressedOutside,
                &BaseButton::setKeepPressedOutside
            ),
            "shortcut", sol::property(
                &BaseButton::getShortcut,
                &BaseButton::setShortcut
            ),
            "shortcutFeedback", sol::property(
                &BaseButton::getShortcutFeedback,
                &BaseButton::setShortcutFeedback
            ),
            "toggleMode", sol::property(
                &BaseButton::getToggleMode,
                &BaseButton::setToggleMode
            ),
            "buttonDown", sol::property(
                &BaseButton::getButtonDown,
                &BaseButton::setButtonDown
            ),
            "buttonUp", sol::property(
                &BaseButton::getButtonUp,
                &BaseButton::setButtonUp
            ),
            "toggled", sol::property(
                &BaseButton::getToggledEvent,
                &BaseButton::setToggledEvent
            ),
            "pressed", sol::property(
                &BaseButton::getPressedEvent,
                &BaseButton::setPressedEvent
            ),
            "getDrawMode", &BaseButton::getDrawMode,
            "isHovered", &BaseButton::isHovered,
            "setPressedNoEvent", &BaseButton::setPressedNoEvent,
        );
    }
}