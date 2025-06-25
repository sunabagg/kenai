package sunaba.input;

@:native("InputEventJoypadMotion")
extern class InputEventJoypadMotion extends InputEvent {
    public var axis: Int;
    public var axisValue: Float;
    @:native("cast")
    public static function castFrom(resource: Dynamic): InputEventJoypadMotion;
}

abstract InputEventJoypadMotionAbstract(InputEventJoypadMotion) from InputEventJoypadMotion to InputEventJoypadMotion {
    @:from
    public static function fromResource(resource: Resource) : InputEventJoypadMotionAbstract {
        var inputEventJoypadMotion = InputEventJoypadMotion.castFrom(resource);
        if (inputEventJoypadMotion.isNull()) {
            return null;
        }
        return inputEventJoypadMotion;
    }
} // end package sunaba.input