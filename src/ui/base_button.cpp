#include "base_button.h"
#include "button_group.h"

namespace lucidware::ui {
    void BaseButtonProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void BaseButtonProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void BaseButtonProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void BaseButtonProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    
    void BaseButtonProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    
    void BaseButtonProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    
    void BaseButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    
    void BaseButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    
    void BaseButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void BaseButtonProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool BaseButtonProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void BaseButtonProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant BaseButtonProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 BaseButtonProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String BaseButtonProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void BaseButtonProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool BaseButtonProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    //Object* BaseButtonProxy::_make_custom_tooltip(const String &for_text) const {
    //    if (control_element != nullptr) {
    //        return control_element->makeCustomTooltip(for_text);
    //    }
    //    return nullptr;
    //}

    TypedArray<Vector3i> BaseButtonProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void BaseButtonProxy::_pressed() {
        if (this->element != nullptr) {
            this->element->pressed();
        }
    }

    void BaseButtonProxy::_toggled(bool p_toggled_on) {
        if (this->element != nullptr) {
            this->element->toggled(p_toggled_on);
        }
    }

    ButtonGroup* BaseButton::getButtonGroup() {
        return new ButtonGroup(base_button->get_button_group().ptr());
    }

    void BaseButton::setButtonGroup(ButtonGroup* group) {
        base_button->set_button_group(group->getButtonGroup());
    }

    void BaseButtonSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("pressed"), &BaseButtonSignalWrapper::pressed);
        ClassDB::bind_method(D_METHOD("toggled", "p_toggled_on"), &BaseButtonSignalWrapper::toggled);
        ClassDB::bind_method(D_METHOD("button_down"), &BaseButtonSignalWrapper::button_down);
        ClassDB::bind_method(D_METHOD("button_up"), &BaseButtonSignalWrapper::button_up);
    }

    void BaseButtonSignalWrapper::pressed() {
        if (element != nullptr) {
            Array args;
            element->pressedEvent->emit(args);
        }
    }

    void BaseButtonSignalWrapper::toggled(bool p_toggled_on) {
        if (element != nullptr) {
            Array args;
            args.push_back(p_toggled_on);
            element->toggledEvent->emit(args);
        }
    }

    void BaseButtonSignalWrapper::button_down() {
        if (element != nullptr) {
            Array args;
            element->buttonDown->emit(args);
        }
    }

    void BaseButtonSignalWrapper::button_up() {
        if (element != nullptr) {
            Array args;
            element->buttonUp->emit(args);
        }
    }

    void bindBaseButton(sol::state &lua) {
        lua.new_usertype<BaseButton>("BaseButton",
            "new", sol::factories(
                []() { return new BaseButton(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control>(),
            "actionMode", sol::property(
                &BaseButton::getActionMode,
                &BaseButton::setActionMode
            ),
            "buttonGroup", sol::property(
                &BaseButton::getButtonGroup,
                &BaseButton::setButtonGroup
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
            "cast", [](Element* e) {
                BaseButtonNode* base_button = Object::cast_to<BaseButtonNode>(e->getNode());
                return new BaseButton(base_button);
            }
        );
    }
}