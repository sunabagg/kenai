package lucidfx.input;

@:native("InputEventGesture")
extern class InputEventGesture extends InputEventWithModifiers {
    public var position: Vector2;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventGesture;
}

abstract InputEventGestureAbstract(InputEventGesture) from InputEventGesture to InputEventGesture {
    @:from
    public static function fromResource(resource: Resource) : InputEventGestureAbstract {
        var inputEventGesture = InputEventGesture.castFrom(resource);
        if (inputEventGesture.isNull()) {
            return null;
        }
        return inputEventGesture;
    }
}