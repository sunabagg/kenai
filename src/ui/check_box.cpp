#include "check_box.h"

namespace lucidware::ui {
    void CheckBoxProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void CheckBoxProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void CheckBoxProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void CheckBoxProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    
    void CheckBoxProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    
    void CheckBoxProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    
    void CheckBoxProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    
    void CheckBoxProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    
    void CheckBoxProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void CheckBoxProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool CheckBoxProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void CheckBoxProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant CheckBoxProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 CheckBoxProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String CheckBoxProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void CheckBoxProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool CheckBoxProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    //Object* CheckBoxProxy::_make_custom_tooltip(const String &for_text) const {
    //    if (control_element != nullptr) {
    //        return control_element->makeCustomTooltip(for_text);
    //    }
    //    return nullptr;
    //}

    TypedArray<Vector3i> CheckBoxProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void CheckBoxProxy::_pressed() {
        if (this->element != nullptr) {
            this->element->pressed();
        }
    }

    void CheckBoxProxy::_toggled(bool p_toggled_on) {
        if (this->element != nullptr) {
            this->element->toggled(p_toggled_on);
        }
    }

    void bindCheckBox(sol::state &lua) {
        lua.new_usertype<CheckBox>("CheckBox",
            "new", sol::factories(
                []() { return new CheckBox(); }
            ),
            sol::base_classes, sol::bases<lucidware::core::BaseObject, Element, lucidware::core::CanvasItem, Control, BaseButton, Button>(),
            "alignment", sol::property(
                &CheckBox::getAlignment,
                &CheckBox::setAlignment
            ),
            "toggleMode", sol::property(
                &CheckBox::getToggleMode,
                &CheckBox::setToggleMode
            ),
            "cast", [](lucidware::core::Element* e) {
                CheckBoxNode* checkBox = Object::cast_to<CheckBoxNode>(e->getNode());
                return new CheckBox(checkBox);
            }
        );
    }
}