package kenai.ui;

import kenai.desktop.PopupMenu;

@:native("LineEdit")
extern class LineEdit extends Control {
    public var alignment: Int;
    public var caretBlink: Bool;
    public var caretBlinkInterval: Float;
    public var caretColumn: Int;
    public var caretForceDisplayed: Bool;
    public var caretMidGrapheme: Bool;
    public var clearButtonEnabled: Bool;
    public var contextMenuEnabled: Bool;
    public var deselectOnFocusLossEnabled: Bool;
    public var dragAndDropSelectionEnabled: Bool;
    public var drawControlChars: Bool;
    public var editable: Bool;
    public var emojiMenuEnabled: Bool;
    public var expandToTextLength: Bool;
    public var flat: Bool;
    public var keepEditingOnTextSubmit: Bool;
    public var language: String;
    public var maxLength: Int;
    public var middleMousePasteEnabled: Bool;
    public var mouseDefaultCursorShape: Int;
    public var placeholderText: String;
    public var rightIcon: kenai.core.Texture2D;
    public var secret: Bool;
    public var secretCharacter: String;
    public var selectAllOnFocus: Bool;
    public var selectingEnabled: Bool;
    public var shortcutKeysEnabled: Bool;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: kenai.core.ArrayList;
    public var text: String;
    public var textDirection: Int;
    public var virtualKeyboardEnabled: Bool;
    public var virtualKeyboardType: Int;
    public var editingToggled: kenai.core.Event;
    public var textChangeRejected: kenai.core.Event;
    public var textChanged: kenai.core.Event;
    public var textSubmitted: kenai.core.Event;
    public function applyIme(): Void;
    public function cancelIme(): Void;
    public function clear(): Void;
    public function deleteCharAtCaret(): Void;
    public function deleteText(from: Int, to: Int): Void;
    public function deselect(): Void;
    public function edit(): Void;
    public function getMenu(): PopupMenu;
    public function getScrollOffset(): Float;
    public function getSelectedText(): String;
    public function getSelectionFromColumn(): Int;
    public function hasImeText(): Bool;
    public function hasRedo(): Bool;
    public function hasSelection(): Bool;
    public function hasUndo(): Bool;
    public function insertTextAtCaret(text: String): Void;
    public function isEditing(): Bool;
    public function isMenuVisible(): Bool;
    public function select(from: Int, ?to: Int): Void;
    public function selectAll(): Void;
    public function unedit(): Void;
    @:native("cast")
    public static function toLineEdit(obj: Dynamic): LineEdit;
}

abstract LineEditAbstract(LineEdit) from LineEdit to LineEdit {
    @:from
    public static function fromElement(element: kenai.core.Element): LineEditAbstract {
        var lineEdit = LineEdit.toLineEdit(element);
        if (lineEdit.isNull()){
            return null;
        }
        return lineEdit;
    }
}