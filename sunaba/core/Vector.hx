package sunaba.core;

import lua.Table;

@:generic
extern class VectorNative<T> {
    @:selfCall
    public function new();
    public function set(index:Int, value:T):Void;
    public function get(index:Int):T;
    public function find(value:T):Int;
    public function erase(index:Int):Void;
    public function insert(index:Int, value:T):Void;
    public function add(value:T):Void;
    public function clear():Void;
    public function next():T;
}

@:generic
@:forward(set, get, find, erase, insert, add, clear, next)
abstract Vector<T>(VectorNative<T>) from VectorNative<T> to VectorNative<T> {
    public function new() {
        this = new VectorNative<T>();
    }

    public function size():Int {
        var s = this;
        return untyped __lua__("#s");
    }

    @:arrayAccess
    public function get(index:Int):T {
        var s = this;
        return untyped __lua__("s[index]");
    }

    @:arrayAccess
    public function set(index:Int, value:T):T {
        var s = this;
        untyped __lua__("s[index] = value");
        return value;
    }

    @:to
    public inline function toArray():Array<T> {
        var s: Vector<T> = this;
        var array: Array<T> = [];
        for (i in 0...s.size()) {
            var value = s.get(i);
            if (value == null) {
                throw "Vector.toArray: null value at index " + i;
            }
            array.push(value);
        }
        return array;
    }

    @:from
    @:generic
    public static function fromTable<A>(table:Table<Int, A>):Vector<A> {
        var vector: Vector<A> = untyped __lua__("table");
        return vector;
    }
   
    @:from
    @:generic
    public static function fromArray<A>(array:Array<A>):Vector<A> {
        var vector: Vector<A> = new Vector<A>();
        for (i in 0...array.length) {
            var value: A = array[i];
            if (value == null) {
                throw "Vector.fromArray: null value at index " + i;
            }
            vector.add(value);
        }
        return vector;
    }
}