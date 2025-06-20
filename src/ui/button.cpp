#include "button.h"

namespace sunaba::ui {
    void ButtonProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void ButtonProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void ButtonProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void ButtonProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    
    void ButtonProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    
    void ButtonProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    
    void ButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    
    void ButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    
    void ButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void ButtonProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
        ButtonNode::_draw();
    }

    bool ButtonProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return ButtonNode::_can_drop_data(at_position, data);
    }

    void ButtonProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
        ButtonNode::_drop_data(at_position, data);
    }

    Variant ButtonProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return ButtonNode::_get_drag_data(at_position);
    }

    Vector2 ButtonProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return ButtonNode::_get_minimum_size();
    }

    String ButtonProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return ButtonNode::_get_tooltip(at_position);
    }

    void ButtonProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
        ButtonNode::_gui_input(event);
    }

    bool ButtonProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return ButtonNode::_has_point(point);
    }

    //Object* ButtonProxy::_make_custom_tooltip(const String &for_text) const {
    //    if (control_element != nullptr) {
    //        return control_element->makeCustomTooltip(for_text);
    //    }
    //    return nullptr;
    //}

    TypedArray<Vector3i> ButtonProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return ButtonNode::_structured_text_parser(args, text);
    }

    void ButtonProxy::_pressed() {
        if (this->element != nullptr) {
            this->element->pressed();
        }
        ButtonNode::_pressed();
    }

    void ButtonProxy::_toggled(bool p_toggled_on) {
        if (this->element != nullptr) {
            this->element->toggled(p_toggled_on);
        }
        ButtonNode::_toggled(p_toggled_on);
    }

    void bindButton(sol::state &lua) {
        using namespace sol;
        using namespace sunaba::ui;

        lua.new_usertype<Button>("Button",
            "new", sol::factories(
                []() { return new Button(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, sunaba::ui::Control, sunaba::ui::BaseButton>(),
            "alignment", sol::property(
                &Button::getAlignment,
                &Button::setAlignment
            ),
            "autowrapMode", sol::property(
                &Button::getAutowrapMode,
                &Button::setAutowrapMode
            ),
            "clipText", sol::property(
                &Button::getClipText,
                &Button::setClipText
            ),
            "expandIcon", sol::property(
                &Button::isExpandIcon,
                &Button::setExpandIcon
            ),
            "flat", sol::property(
                &Button::isFlat,
                &Button::setFlat
            ),
            "icon", sol::property(
                &Button::getIcon,
                &Button::setIcon
            ),
            "iconAlignment", sol::property(
                &Button::getIconAlignment,
                &Button::setIconAlignment
            ),
            "language", sol::property(
                &Button::getLanguage,
                &Button::setLanguage
            ),
            "text", sol::property(
                &Button::getText,
                &Button::setText
            ),
            "textDirection", sol::property(
                &Button::getTextDirection,
                &Button::setTextDirection
            ),
            "textOverrunBehavior", sol::property(
                &Button::getTextOverrunBehavior,
                &Button::setTextOverrunBehavior
            ),
            "verticalIconAlignment", sol::property(
                &Button::getVerticalIconAlignment,
                &Button::setVerticalIconAlignment
            ),
            "cast", [](sunaba::core::Element* e) {
                ButtonNode* button = Object::cast_to<ButtonNode>(e->getNode());
                return new Button(button);
            }
        );
    }
}