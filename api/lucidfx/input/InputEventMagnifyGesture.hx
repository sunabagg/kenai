package lucidfx.input;

@:native("InputEventMagnifyGesture")
extern class InputEventMagnifyGesture extends InputEventGesture {
    public var factor: Float;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventMagnifyGesture;
}

abstract InputEventMagnifyGestureAbstract(InputEventMagnifyGesture) from InputEventMagnifyGesture to InputEventMagnifyGesture {
    @:from
    public static function fromResource(resource: Resource) : InputEventMagnifyGestureAbstract {
        var inputEventMagnifyGesture = InputEventMagnifyGesture.castFrom(resource);
        if (inputEventMagnifyGesture.isNull()) {
            return null;
        }
        return inputEventMagnifyGesture;
    }
} // end package lucidfx.input