package lucidfx.input;

@:native("InputEventAction")
extern class InputEventAction extends InputEvent {
    public var action: String;
    public var eventIndex: Int;
    public var pressed: Bool;
    public var strength: Float;
    @:native("cast")
    public static function castFrom(resource: Dynamic): InputEventAction;
}

abstract InputEventActionAbstract(InputEventAction) from InputEventAction to InputEventAction {
    @:from
    public static function fromResource(resource: Resource) : InputEventActionAbstract {
        var inputEventAction = InputEventAction.castFrom(resource);
        if (inputEventAction.isNull()) {
            return null;
        }
        return inputEventAction;
    }
}