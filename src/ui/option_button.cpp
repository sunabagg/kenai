#include "option_button.h"

namespace sunaba::ui {
    void OptionButtonProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void OptionButtonProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void OptionButtonProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void OptionButtonProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void OptionButtonProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void OptionButtonProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void OptionButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void OptionButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void OptionButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void OptionButtonProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool OptionButtonProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void OptionButtonProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant OptionButtonProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 OptionButtonProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String OptionButtonProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void OptionButtonProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool OptionButtonProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> OptionButtonProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void OptionButtonProxy::_pressed() {
        if (element != nullptr) {
            element->pressed();
        }
    }

    void OptionButtonProxy::_toggled(bool p_toggled_on) {
        if (element != nullptr) {
            element->toggled(p_toggled_on);
        }
    }

    void bindOptionButton(sol::state& lua) {
        lua.new_usertype<OptionButton>("OptionButton",
            sol::constructors<OptionButton()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, BaseButton, Button>(),
            "actionMode", sol::property(
                &OptionButton::getActionMode,
                &OptionButton::setActionMode
            ),
            "alignment", sol::property(
                &OptionButton::getAlignment,
                &OptionButton::setAlignment
            ),
            "allowReselect", sol::property(
                &OptionButton::getAllowReselect,
                &OptionButton::setAllowReselect
            ),
            "fitToLongestItem", sol::property(
                &OptionButton::isFitToLongestItem,
                &OptionButton::setFitToLongestItem
            ),
            "itemCount", sol::property(
                &OptionButton::getItemCount,
                &OptionButton::setItemCount
            ),
            "selected", sol::property(
                &OptionButton::getSelected,
                &OptionButton::setSelected
            ),
            "toggleMode", sol::property(
                &OptionButton::isToggleMode,
                &OptionButton::setToggleMode
            ),
            "itemFocused", sol::property(
                &OptionButton::getItemFocusedEvent,
                &OptionButton::setItemFocusedEvent
            ),
            "itemSelected", sol::property(
                &OptionButton::getItemSelectedEvent,
                &OptionButton::setItemSelectedEvent
            ),
        );
    }
}