#include "line_edit.h"

namespace sunaba::ui {
    void LineEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void LineEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void LineEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void LineEditProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void LineEditProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void LineEditProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void LineEditProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void LineEditProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void LineEditProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void LineEditProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool LineEditProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void LineEditProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant LineEditProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 LineEditProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->_getMinimumSize();
        }
        return Vector2();
    }

    String LineEditProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void LineEditProxy::_gui_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool LineEditProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> LineEditProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void LineEditSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("editingToggled", "toggledOn"), &LineEditSignalWrapper::editingToggled);
        ClassDB::bind_method(D_METHOD("textChangeRejected", "rejectedSubstring"), &LineEditSignalWrapper::textChangeRejected);
        ClassDB::bind_method(D_METHOD("textChanged", "newText"), &LineEditSignalWrapper::textChanged);
        ClassDB::bind_method(D_METHOD("textSubmitted", "newText"), &LineEditSignalWrapper::textSubmitted);
    }

    void LineEditSignalWrapper::editingToggled(bool toggledOn) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(toggledOn);
            this->element->editingToggledEvent->emit(args);
        }
    }

    void LineEditSignalWrapper::textChangeRejected(const String &rejectedSubstring) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(rejectedSubstring);
            this->element->textChangeRejectedEvent->emit(args);
        }
    }

    void LineEditSignalWrapper::textChanged(const String &newText) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(newText);
            this->element->textChangedEvent->emit(args);
        }
    }

    void LineEditSignalWrapper::textSubmitted(const String &newText) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(newText);
            this->element->textSubmittedEvent->emit(args);
        }
    }

    void bindLineEdit(sol::state& lua) {
        lua.new_usertype<LineEdit>("LineEdit",
            sol::constructors<LineEdit()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "alignment", sol::property(&LineEdit::getAlignment, &LineEdit::setAlignment),
            "caretBlink", sol::property(&LineEdit::getCaretBlink, &LineEdit::setCaretBlink),
            "carentBlinkInterval", sol::property(&LineEdit::getCaretBlinkInterval, &LineEdit::setCaretBlinkInterval),
            "caretColumn", sol::property(&LineEdit::getCaretColumn, &LineEdit::setCaretColumn),
            "caretForceDisplayed", sol::property(&LineEdit::getCaretForceDisplayed, &LineEdit::setCaretForceDisplayed),
            "caretMidGrapheme", sol::property(&LineEdit::getCaretMidGrapheme, &LineEdit::setCaretMidGrapheme),
            "clearButtonEnabled", sol::property(&LineEdit::getClearButtonEnabled, &LineEdit::setClearButtonEnabled),
            "contextMenuEnabled", sol::property(&LineEdit::getContextMenuEnabled, &LineEdit::setContextMenuEnabled),
            "deselectOnFocusLossEnabled", sol::property(&LineEdit::getDeselectOnFocusLossEnabled, &LineEdit::setDeselectOnFocusLossEnabled),
            "dragAndDropSelectionEnabled", sol::property(&LineEdit::getDragAndDropSelectionEnabled, &LineEdit::setDragAndDropSelectionEnabled),
            "drawControlChars", sol::property(&LineEdit::getDrawControlChars, &LineEdit::setDrawControlChars),
            "editable", sol::property(&LineEdit::getEditable, &LineEdit::setEditable),
            "emojiMenuEnabled", sol::property(&LineEdit::getEmojiMenuEnabled, &LineEdit::setEmojiMenuEnabled),
            "expandToTextLength", sol::property(&LineEdit::getExpandToTextLength, &LineEdit::setExpandToTextLength),
            "flat", sol::property(&LineEdit::getFlat, &LineEdit::setFlat),
            "focusMode", sol::property(&LineEdit::getFocusMode, &LineEdit::setFocusMode),
            "keepEditingOnTextSubmit", sol::property(&LineEdit::getKeepEditingOnTextSubmit, &LineEdit::setKeepEditingOnTextSubmit),
            "language", sol::property(&LineEdit::getLanguage, &LineEdit::setLanguage),
            "maxLength", sol::property(&LineEdit::getMaxLength, &LineEdit::setMaxLength),
            "middleMousePasteEnabled", sol::property(&LineEdit::getMiddleMousePasteEnabled, &LineEdit::setMiddleMousePasteEnabled),
            "mouseDefaultCursorShape", sol::property(&LineEdit::getMouseDefaultCursorShape, &LineEdit::setMouseDefaultCursorShape),
            "placeholderText", sol::property(&LineEdit::getPlaceholderText, &LineEdit::setPlaceholderText),
            "rightIcon", sol::property(&LineEdit::getRightIcon, &LineEdit::setRightIcon),
            "secret", sol::property(&LineEdit::getSecret, &LineEdit::setSecret),
            "secretCharacter", sol::property(&LineEdit::getSecretCharacter, &LineEdit::setSecretCharacter),
            "selectAllOnFocusEnabled", sol::property(&LineEdit::getSelectAllOnFocus, &LineEdit::setSelectAllOnFocus),
            "selectingEnabled", sol::property(&LineEdit::getSelectingEnabled, &LineEdit::setSelectingEnabled),
            "shortcutKeysEnabled", sol::property(&LineEdit::getShortcutKeysEnabled, &LineEdit::setShortcutKeysEnabled),
            "structuredTextBidiOverride", sol::property(&LineEdit::getStructuredTextBidiOverride, &LineEdit::setStructuredTextBidiOverride),
            "structuredTextBidiOverrideOptions", sol::property(&LineEdit::getStructuredTextBidiOverrideOptions, &LineEdit::setStructuredTextBidiOverrideOptions),
            "text", sol::property(&LineEdit::getText, &LineEdit::setText),
            "textDirection", sol::property(&LineEdit::getTextDirection, &LineEdit::setTextDirection),
            "virtualKeyboardEnabled", sol::property(&LineEdit::getVirtualKeyboardEnabled, &LineEdit::setVirtualKeyboardEnabled),
            "virtualKeyboardType", sol::property(&LineEdit::getVirtualKeyboardType, &LineEdit::setVirtualKeyboardType),
            "editingToggled", sol::property(&LineEdit::getEditingToggledEvent, &LineEdit::setEditingToggledEvent),
            "textChangeRejected", sol::property(&LineEdit::getTextChangeRejectedEvent, &LineEdit::setTextChangeRejectedEvent),
            "textChanged", sol::property(&LineEdit::getTextChangedEvent, &LineEdit::setTextChangedEvent),
            "textSubmitted", sol::property(&LineEdit::getTextSubmittedEvent, &LineEdit::setTextSubmittedEvent),
            "applyIme", &LineEdit::applyIme,
            "cancelIme", &LineEdit::cancelIme,
            "clear", &LineEdit::clear,
            "deleteCharAtCaret", &LineEdit::deleteCharAtCaret,
            "deleteText", &LineEdit::deleteText,
            "deselect", &LineEdit::deselect,
            "edit", &LineEdit::edit,
            "getMenu", &LineEdit::getMenu,
            "getScrollOffset", &LineEdit::getScrollOffset,
            "getSelectedText", &LineEdit::getSelectedText,
            "getSelectionFromColumn", &LineEdit::getSelectionFromColumn,
            "getSelectionToColumn", &LineEdit::getSelectionToColumn,
            "hasImeText", &LineEdit::hasImeText,
            "hasRedo", &LineEdit::hasRedo,
            "hasSelection", &LineEdit::hasSelection,
            "hasUndo", &LineEdit::hasUndo,
            "insertTextAtCaret", &LineEdit::insertTextAtCaret,
            "isEditing", &LineEdit::isEditing,
            "isMenuVisible", &LineEdit::isMenuVisible,
            "menuOption", &LineEdit::menuOption,
            "select", &LineEdit::select,
            "selectAll", &LineEdit::selectAll,
            "unedit", &LineEdit::unedit,
            "cast", [](Element* e) {
                LineEditNode* control = Object::cast_to<LineEditNode>(e->getNode());
                return new LineEdit(control);
            }
        );
    }
}