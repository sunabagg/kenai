package sunaba.input;

@:native("InputEventWithModifiers")
extern class InputEventWithModifiers extends InputEventFromWindow {
    public var altPressed: Bool;
    public var commandOrControlAutoremap: Bool;
    public var ctrlPressed: Bool;
    public var metaPressed: Bool;
    public var shiftPressed: Bool;
    public function getModifiersMask(): Int;
    public function isCommandOrControlPressed(): Bool;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventWithModifiers;
}

abstract InputEventWithModifiersAbstract(InputEventWithModifiers) from InputEventWithModifiers to InputEventWithModifiers {
    @:from
    public static function fromResource(resource: Resource) : InputEventWithModifiersAbstract {
        var inputEventWithModifiers = InputEventWithModifiers.castFrom(resource);
        if (inputEventWithModifiers.isNull()) {
            return null;
        }
        return inputEventWithModifiers;
    }
} // end package sunaba.input