package sunaba.core;

import haxe.Constraints.Function;

@:native("Event")
extern class Event extends BaseObject {
    public function new();
    public function connect(func: Function): Void;
    public function disconnect(func: Function): Void;
    public function emit(...args: Variant): Void;
}

abstract EventAbstract(Event) from Event to Event {
    @:op(a())
    public function callNoArgs() {
        this.emit();
    }
}