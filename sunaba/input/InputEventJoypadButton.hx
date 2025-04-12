package sunaba.input;

@:native("InputEventJoypadButton")
extern class InputEventJoypadButton extends InputEvent {
    public var buttonIndex: Int;
    public var pressed: Bool;
    public var pressure: Float;
    @:native("cast")
    public static function castFrom(resource: Dynamic): InputEventJoypadButton;
}

abstract InputEventJoypadButtonAbstract(InputEventJoypadButton) from InputEventJoypadButton to InputEventJoypadButton {
    @:from
    public static function fromResource(resource: Resource) : InputEventJoypadButtonAbstract {
        var inputEventJoypadButton = InputEventJoypadButton.castFrom(resource);
        if (inputEventJoypadButton.isNull()) {
            return null;
        }
        return inputEventJoypadButton;
    }
} // end package sunaba.input