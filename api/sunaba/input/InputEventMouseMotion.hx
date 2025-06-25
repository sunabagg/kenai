package sunaba.input;

import sunaba.core.Vector2;

@:native("InputEventMouseMotion")
extern class InputEventMouseMotion extends InputEventMouse {
    public var penInverted: Bool;
    public var pressure: Float;
    public var relative: Vector2;
    public var screenRelative: Vector2;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventMouseMotion;
}

abstract InputEventMouseMotionAbstract(InputEventMouseMotion) from InputEventMouseMotion to InputEventMouseMotion {
    @:from
    public static function fromResource(resource: Resource) : InputEventMouseMotionAbstract {
        var inputEventMouseMotion = InputEventMouseMotion.castFrom(resource);
        if (inputEventMouseMotion.isNull()) {
            return null;
        }
        return inputEventMouseMotion;
    }
} // end package sunaba.input