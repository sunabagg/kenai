package sunaba.core;

@:generic
extern class VectorNative<T> {
    public function set(index:Int, value:T):Void;
    public function get(index:Int):T;
    public function find(value:T):Int;
    public function erase(index:Int):Void;
    public function insert(index:Int, value:T):Void;
    public function add(key:Int, value:T):Void;
    public function clear():Void;
    public function next():T;
}

@:generic
abstract Vector<T>(VectorNative<T>) from VectorNative<T> to VectorNative<T> {
    public function size():Int {
        var s = this;
        return untyped __lua__("#s");
    }

    @:arrayAccess
    public function get(index:Int):T {
        var s = this;
        return untyped __lua__("s[index]");
    }
}