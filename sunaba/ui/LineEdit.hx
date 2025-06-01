package sunaba.ui;

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
    public var rightIcon: sunaba.core.Texture2D;
    public var secret: Bool;
    public var secretCharacter: String;
    public var selectAllOnFocus: Bool;
    public var selectingEnabled: Bool;
    public var shortcutKeysEnabled: Bool;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: sunaba.core.ArrayList;
    public var text: String;
    public var textDirection: Int;
    public var virtualKeyboardEnabled: Bool;
    public var virtualKeyboardType: Int;
    public var editingToggled: sunaba.core.Event;
    public var textChangeRejected: sunaba.core.Event;
    public var textChanged: sunaba.core.Event;
    public var textSubmitted: sunaba.core.Event;
    public function applyIme(): Void;
    public function cancelIme(): Void;
    public function clear(): Void;
    public function deleteCharAtCaret(): Void;
    public function deleteText(from: Int, to: Int): Void;
    public function deselect(): Void;
}