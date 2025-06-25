package lucidware.input;

@:native("InputEventScreenDrag")
extern class InputEventScreenDrag extends InputEventFromWindow {
    public var index: Int;
    public var penInverted: Bool;
    public var position: Vector2;
    public var pressure: Float;
    public var relative: Vector2;
    public var screenRelative: Vector2;
    public var screenVelocity: Vector2;
    public var tilt: Vector2;
    public var velocity: Vector2;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventScreenDrag;
}

abstract InputEventScreenDragAbstract(InputEventScreenDrag) from InputEventScreenDrag to InputEventScreenDrag {
    @:from
    public static function fromResource(resource: Resource) : InputEventScreenDragAbstract {
        var inputEventScreenDrag = InputEventScreenDrag.castFrom(resource);
        if (inputEventScreenDrag.isNull()) {
            return null;
        }
        return inputEventScreenDrag;
    }
} // end package lucidware.input