package sunaba.ui;

@:native("TextEdit")
extern class TextEdit extends Control {
    public var autowrapMode: Int;
    public var caretBlink: Bool;
    public var caretBlinkInterval: Float;
}