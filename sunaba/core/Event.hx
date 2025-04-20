package sunaba.core;

import haxe.Constraints.Function;

@:native("Event")
extern class Event extends BaseObject {
    public function new();
    public function connect(func: Function): Void;
    public function disconnect(func: Function): Void;
    public function emit(args: Array<Dynamic>): Void;
}