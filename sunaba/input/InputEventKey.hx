package lucidware.input;

@:native("InputEventKey")
extern class InputEventKey extends InputEventWithModifiers {
    public var echo: Bool;
    public var keyLabel: Int;
    public var location: Int;
    public var physicalKeycode: Int;
    public var pressed: Bool;
    public var unicode: Int;
    public function asTextKeyLabel(): String;
    public function asTextKeycode(): String;
    public function asTextLocation(): String;
    public function asTextPhysicalKeycode(): String;
    public function getKeyLabelWithModifiers(): Int;
    public function getKeycodeWithModifiers(): Int;
    public function getPhysicalKeycodeWithModifiers(): Int;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventKey;
}

abstract InputEventKeyAbstract(InputEventKey) from InputEventKey to InputEventKey {
    @:from
    public static function fromResource(resource: Resource) : InputEventKeyAbstract {
        var inputEventKey = InputEventKey.castFrom(resource);
        if (inputEventKey.isNull()) {
            return null;
        }
        return inputEventKey;
    }
} // end package lucidware.input