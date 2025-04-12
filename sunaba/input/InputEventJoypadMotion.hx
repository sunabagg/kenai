package sunaba.input;

@:native("InputEventJoypadMotion")
extern class InputEventJoypadMotion extends InputEvent {
    public var axis: Int;
    public var axisValue: Float;
}