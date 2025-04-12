package sunaba.input;

@:native("InputEventAction")
extern class InputEventAction extends InputEvent {
    public var action: String;
    public var eventIndex: Int;
    public var pressed: Bool;
    public var strength: Float;
}