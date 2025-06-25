package lucidfx.core;

import haxe.Constraints.Function;

@:native("Event")
extern class Event extends BaseObject {
    public function new();
    public function connect(func: Function): Void;
    public function disconnect(func: Function): Void;
    public function emit(...args: Variant): Void;
    public function clear(): Void;
}

abstract EventAbstract(Event) from Event to Event {
    @:op(a())
    public function callNoArgs() {
        this.emit();
    }

    @:op(a())
    public function call(...args: Variant) {
        this.emit(...args);
    }

    /*@op(A += B)
    public static function add(event: Event, func: Function): Void {
        event.connect(func);
    }

    @op(A -= B)
    public static function remove(event: Event, func: Function): Void {
        event.disconnect(func);
    }*/
}