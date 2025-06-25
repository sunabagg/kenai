package sunaba.input;

@:native("InputEventMouseButton")
extern class InputEventMouseButton extends InputEventMouse {
    public var buttonIndex: Int;
    public var canceled: Bool;
    public var doubleClick: Bool;
    public var factor: Float;
    public var pressed: Bool;
    @:native("cast")
    public static function castFrom(resource: Dynamic): InputEventMouseButton;
}

abstract InputEventMouseButtonAbstract(InputEventMouseButton) from InputEventMouseButton to InputEventMouseButton {
    @:from
    public static function fromResource(resource: Resource) : InputEventMouseButtonAbstract {
        var inputEventMouseButton = InputEventMouseButton.castFrom(resource);
        if (inputEventMouseButton.isNull()) {
            return null;
        }
        return inputEventMouseButton;
    }
} // end package sunaba.input