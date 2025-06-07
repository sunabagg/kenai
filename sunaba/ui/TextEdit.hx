package sunaba.ui;

@:native("TextEdit")
extern class TextEdit extends Control {
    public var autowrapMode: Int;
    public var caretBlink: Bool;
    public var caretBlinkInterval: Float;
    public var caretDrawWhenEditableDisabled: Bool;
    public var caretMidGrapheme: Bool;
    public var caretMoveOnRightClick: Bool;
    public var caretMultiple: Bool;
}