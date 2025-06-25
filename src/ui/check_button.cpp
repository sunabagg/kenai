#include "check_button.h"

namespace lucidware::ui {
    void CheckButtonProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void CheckButtonProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void CheckButtonProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void CheckButtonProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    void CheckButtonProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    void CheckButtonProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    void CheckButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    void CheckButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    void CheckButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }
    void CheckButtonProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }
    bool CheckButtonProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }
    void CheckButtonProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }
    Variant CheckButtonProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }
    Vector2 CheckButtonProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }
    String CheckButtonProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }
    void CheckButtonProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }
    bool CheckButtonProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }
    //Object* CheckButtonProxy::_make_custom_tooltip(const String &for_text) const {
    //     if (element != nullptr) {
    //         return element->makeCustomTooltip(for_text);
    //     }
    //     return nullptr;
    // }
    TypedArray<Vector3i> CheckButtonProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }
    void CheckButtonProxy::_pressed() {
        if (this->element != nullptr) {
            this->element->pressed();
        }
    }
    void CheckButtonProxy::_toggled(bool p_toggled_on) {
        if (this->element != nullptr) {
            this->element->toggled(p_toggled_on);
        }
    }

    void bindCheckButton(sol::state& lua) {
        lua.new_usertype<CheckButton>("CheckButton",
            "new", sol::factories(
                []() { return new CheckButton(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control, lucidware::ui::BaseButton, Button>(),
            "alignment", sol::property(
                &CheckButton::getAlignment,
                &CheckButton::setAlignment
            ),
            "toggleMode", sol::property(
                &CheckButton::getToggleMode,
                &CheckButton::setToggleMode
            ),
            "cast", [](lucidware::core::Element* e) {
                CheckButtonNode* check_button_node = Object::cast_to<CheckButtonNode>(e->getNode());
                return new CheckButton(check_button_node);
            }
        );
    }
}