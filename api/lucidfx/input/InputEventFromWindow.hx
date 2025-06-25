package lucidfx.input;

@:native("InputEventFromWindow")
extern class InputEventFromWindow extends InputEvent {
    public var windowId: Int;
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEventFromWindow;
} // end package lucidfx.input

abstract InputEventFromWindowAbstract(InputEventFromWindow) from InputEventFromWindow to InputEventFromWindow {
    @:from
    public static function fromResource(resource: Resource) : InputEventFromWindowAbstract {
        var inputEventFromWindow = InputEventFromWindow.castFrom(resource);
        if (inputEventFromWindow.isNull()) {
            return null;
        }
        return inputEventFromWindow;
    }
}