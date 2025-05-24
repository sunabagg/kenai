#include "code_edit.h"

namespace sunaba::ui {
    void CodeEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void CodeEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void CodeEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void CodeEditProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void CodeEditProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void CodeEditProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void CodeEditProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void CodeEditProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void CodeEditProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void CodeEditProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool CodeEditProxy::_can_drop_data(const Vector2& at_position, const Variant& data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void CodeEditProxy::_drop_data(const Vector2& at_position, const Variant& data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant CodeEditProxy::_get_drag_data(const Vector2& at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 CodeEditProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

    String CodeEditProxy::_get_tooltip(const Vector2& at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void CodeEditProxy::_gui_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool CodeEditProxy::_has_point(const Vector2& point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> CodeEditProxy::_structured_text_parser(const Array& args, const String& text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void CodeEditProxy::_backspace(int caret_index) {
        if (this->element != nullptr) {
            this->element->onBackspace(caret_index);
        }
    }

    void CodeEditProxy::_copy(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCopy(caret_index);
        }
    }

    void CodeEditProxy::_cut(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCut(caret_index);
        }
    }

    void CodeEditProxy::_handle_unicode_input(int unicode_char, int caret_index) {
        if (this->element != nullptr) {
            this->element->onHandleUnicodeInput(unicode_char, caret_index);
        }
    }
}