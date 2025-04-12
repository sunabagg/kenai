package sunaba.input;

@:native("InputEventJoypadButton")
extern class InputEventJoypadButton extends InputEvent {
    public var buttonIndex: Int;
    public var pressed: Bool;
    public var pressure: Float;
}