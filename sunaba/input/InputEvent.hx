package sunaba.input;

import sunaba.core.Resource;

@:native("InputEvent")
extern class InputEvent extends Resource {
    public var device: Int;
    public function accumulate(event: InputEvent): Void;
    public function asText(): String;
    public function getActionStregth(action: String): Float;
    public function isAction(action: String, exactMatch : Bool = false): Bool;
    public function isActionPressed(action: String, allowEcho: Bool = false, exactMatch: Bool = false): Bool;
    public function isActionReleased(action: String, exactMatch: Bool = false): Bool;
    public function isActionType(): Bool;
    public function isCanceled(): Bool;
    public function isEcho(): Bool;
    public function isMatch(event: InputEvent, exactMatch: Bool = false): Bool;
    public function isPressed(): Bool;
    public function isReleased(): Bool;
    //public function xformedBy()
    @:native("cast")
    public static function castFrom(res: Dynamic): InputEvent;
}

abstract InputEventAbstract(InputEvent) from InputEvent to InputEvent {
    @:from
    public static function fromResource(resource: Resource) : InputEventAbstract {
        var inputEvent = InputEvent.castFrom(resource);
        if (inputEvent.isNull()) {
            return null;
        }
        return inputEvent;
    } 
} // end package sunaba.core