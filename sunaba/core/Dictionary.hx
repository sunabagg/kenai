package sunaba.core;

@:native("Dictionary")
extern class Dictionary {
    public function new();
    public function assign(dict : Dictionary) : Void;
    public function clear() : Void;
    public function duplicate(deep: Bool = false) : Dictionary;
    public function erase(key : Variant) : Void;
    public function findKey(key : Variant) : Variant;
    public function get(key : Variant, ?default: Variant) : Variant;
    public function getOrAdd(key : Variant, ?default : Variant) : Variant;
    public function has(key : Variant) : Bool;
    public function hasAll(keys : ArrayList) : Bool;
    public function hash() : Int;
    public function isEmpty() : Bool;
    public function isReadOnly() : Bool;
    public function keys() : ArrayList;
    public function makeReadOnly() : Void;
    public function merge(dict : Dictionary, overwrite: Bool = false) : Void;
    public function recursiveEquals(dict : Dictionary, recursionCount: Int) : Bool;
    public function set(key : Variant, value : Variant) : Void;
    public function size() : Int;
    public function sort() : Void;
    public function values() : ArrayList;
}

abstract DictionaryAbstract(Dictionary) from Dictionary to Dictionary {
    @:op([])
    public inline function get(key: Variant): Variant {
        return this.get(key);
    }

    @:op([])
    public inline function set(key: Variant, value: Variant): Void {
        this.set(key, value);
    }

    @:arrayAccess
    public inline function getArray(key: Variant): Variant {
        return this.get(key);
    }

    @:arrayAccess
    public inline function setArray(key: Variant, value: Variant): Void {
        this.set(key, value);
    }

    public inline function forEach(func: Variant->Void): Void {
        var keys = this.keys();
        for (i in 0...keys.size()) {
            var key = keys[i];
            func(key, this.get(key));
        }
    }
}
