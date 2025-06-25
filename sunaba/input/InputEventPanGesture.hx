package lucidware.input;

@:native("InputEventPanGesture")
extern class InputEventPanGesture extends InputEventGesture {
    public var delta: Vector2;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventPanGesture;
}

abstract InputEventPanGestureAbstract(InputEventPanGesture) from InputEventPanGesture to InputEventPanGesture {
    @:from
    public static function fromResource(resource: Resource) : InputEventPanGestureAbstract {
        var inputEventPanGesture = InputEventPanGesture.castFrom(resource);
        if (inputEventPanGesture.isNull()) {
            return null;
        }
        return inputEventPanGesture;
    }
} // end package lucidware.input