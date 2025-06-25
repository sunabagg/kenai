package sunaba.input;

import sunaba.core.Vector2;

@:native("InputEventMouse")
extern class InputEventMouse extends InputEventWithModifiers {
    public var buttonMask: Int;
    public var globalPosition: Vector2;
    public var position: Vector2;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventMouse;
}

abstract InputEventMouseAbstract(InputEventMouse) from InputEventMouse to InputEventMouse {
    @:from
    public static function fromResource(resource: Resource) : InputEventMouseAbstract {
        var inputEventMouse = InputEventMouse.castFrom(resource);
        if (inputEventMouse.isNull()) {
            return null;
        }
        return inputEventMouse;
    }
} // end package sunaba.input