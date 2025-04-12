package sunaba.input;

@:native("InputEventShortcut")
extern class InputEventShortcut extends InputEventWithModifiers {
    public var events: Array<InputEvent>;
    public function getAsText(): String;
    public function hasValidEvent(): Bool;
    public function matchesEvent(event: InputEvent): Bool;
    @:native("cast")
    public function castFrom(res: Dynamic): InputEventShortcut;
}

abstract InputEventShortcutAbstract(InputEventShortcut) from InputEventShortcut to InputEventShortcut {
    @:from
    public static function fromResource(resource: Resource) : InputEventShortcutAbstract {
        var inputEventShortcut = InputEventShortcut.castFrom(resource);
        if (inputEventShortcut.isNull()) {
            return null;
        }
        return inputEventShortcut;
    }
} // end package sunaba.input