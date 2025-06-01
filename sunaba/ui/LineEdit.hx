package sunaba.ui;

@:native("LineEdit")
extern class LineEdit extends Control {
    public var alignment: Int;
    public var caretBlink: Bool;
    public var caretBlinkInterval: Float;
}