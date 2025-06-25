package lucidfx.input;

@:native("InputEventMidi")
extern class InputEventMidi extends InputEvent {
    public var channel: Int;
    public var controllerNumber: Int;
    public var controllerValue: Int;
    public var instrument: Int;
    public var message: Int;
    public var pitch: Int;
    public var pressure: Int;
    public var velocity: Int;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventMidi;
}

abstract InputEventMidiAbstract(InputEventMidi) from InputEventMidi to InputEventMidi {
    @:from
    public static function fromResource(resource: Resource) : InputEventMidiAbstract {
        var inputEventMidi = InputEventMidi.castFrom(resource);
        if (inputEventMidi.isNull()) {
            return null;
        }
        return inputEventMidi;
    }
} // end package lucidfx.input