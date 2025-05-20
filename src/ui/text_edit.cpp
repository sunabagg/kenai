#include "text_edit.h"

namespace sunaba::ui {
    void TextEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TextEditProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TextEditProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TextEditProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TextEditProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TextEditProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TextEditProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TextEditProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TextEditProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TextEditProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TextEditProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TextEditProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->_getMinimumSize();
        }
        return Vector2();
    }

    String TextEditProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TextEditProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool TextEditProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> TextEditProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void TextEditProxy::_backspace(int caret_index) {
        if (this->element != nullptr) {
            this->element->onBackspace(caret_index);
        }
    }

    void TextEditProxy::_copy(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCopy(caret_index);
        }
    }

    void TextEditProxy::_cut(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCut(caret_index);
        }
    }

    void TextEditProxy::_handle_unicode_input(int unicode_char, int caret_index) {
        if (this->element != nullptr) {
            this->element->onHandleUnicodeInput(unicode_char, caret_index);
        }
    }

    void TextEditProxy::_paste(int caret_index) {
        if (this->element != nullptr) {
            this->element->onPaste(caret_index);
        }
    }

    void TextEditProxy::_paste_primary_clipboard(int caret_index) {
        if (this->element != nullptr) {
            this->element->onPastePrimaryClipboard(caret_index);
        }
    }

    void bindTextEdit(sol::state& lua) {
        lua.new_usertype<TextEdit>("TextEdit",
            sol::constructors<TextEdit()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "autowrapMode", sol::property(
                &TextEdit::getAutowrapMode,
                &TextEdit::setAutowrapMode
            ),
            "caretBlink", sol::property(
                &TextEdit::getCaretBlink,
                &TextEdit::setCaretBlink
            ),
            "caretBlinkInterval", sol::property(
                &TextEdit::getCaretBlinkInterval,
                &TextEdit::setCaretBlinkInterval
            ),
            "caretDrawWhenEditableDisabled", sol::property(
                &TextEdit::getCaretDrawWhenEditableDisabled,
                &TextEdit::setCaretDrawWhenEditableDisabled
            ),
            "caretMidGrapheme", sol::property(
                &TextEdit::getCaretMidGrapheme,
                &TextEdit::setCaretMidGrapheme
            ),
            "caretMoveOnRightClick", sol::property(
                &TextEdit::getCaretMoveOnRightClick,
                &TextEdit::setCaretMoveOnRightClick
            ),
            "caretMultiple", sol::property(
                &TextEdit::getCaretMultiple,
                &TextEdit::setCaretMultiple
            ),
            "caretType", sol::property(
                &TextEdit::getCaretType,
                &TextEdit::setCaretType
            ),
            "clipContents", sol::property(
                &TextEdit::getClipContents,
                &TextEdit::setClipContents
            ),
        );
    }
}