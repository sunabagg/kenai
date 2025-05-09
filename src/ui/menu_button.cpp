#include "menu_button.h"

namespace sunaba::ui {
    void MenuButtonProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void MenuButtonProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void MenuButtonProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void MenuButtonProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void MenuButtonProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void MenuButtonProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void MenuButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void MenuButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void MenuButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void MenuButtonProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool MenuButtonProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void MenuButtonProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant MenuButtonProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 MenuButtonProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String MenuButtonProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void MenuButtonProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool MenuButtonProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> MenuButtonProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void MenuButtonProxy::_pressed() {
        if (this->element != nullptr) {
            this->element->pressed();
        }
    }
}