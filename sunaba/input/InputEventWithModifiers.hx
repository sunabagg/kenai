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
}