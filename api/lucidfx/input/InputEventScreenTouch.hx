package lucidfx.input;

@:native("InputEventScreenTouch")
extern class InputEventScreenTouch extends InputEventFromWindow {
    public var cancelled: Bool;
    public var doubleTap: Bool;
    public var index: Int;
    public var position: Vector2;
    public var pressed: Bool;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventScreenTouch;
}

abstract InputEventScreenTouchAbstract(InputEventScreenTouch) from InputEventScreenTouch to InputEventScreenTouch {
    @:from
    public static function fromResource(resource: Resource) : InputEventScreenTouchAbstract {
        var inputEventScreenTouch = InputEventScreenTouch.castFrom(resource);
        if (inputEventScreenTouch.isNull()) {
            return null;
        }
        return inputEventScreenTouch;
    }
} // end package lucidfx.input