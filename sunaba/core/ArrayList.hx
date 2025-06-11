package sunaba.core;

@:native("ArrayList")
extern class ArrayList {
    public function new();
    public function append(value : Variant) : Void;
    public function appendArray(array : ArrayList) : Void;
    public function assign(array : ArrayList) : Void;
    public function back() : Variant;
    public function bsearch(value : Variant, before: Bool = true) : Int;
    public function clear() : Void;
    public function count() : Int;
    public function duplicate(deep: Bool = false) : ArrayList;
    public function erase(value : Variant) : Void;
    public function fill(value : Variant) : Void;
    public function front() : Variant;
    public function get(index : Int) : Variant;
    public function has(value : Variant) : Bool;
    public function hash() : Int;
    public function insert(index : Int, value : Variant) : Void;
    public function isEmpty() : Bool;
    public function isReadOnly() : Bool;
    public function makeReadOnly() : Void;
    public function max() : Variant;
    public function min() : Variant;
    public function pickRandom() : Variant;
    public function popAt(index : Int) : Variant;
    public function popBack() : Variant;
    public function popFront() : Variant;
    public function pushBack(value : Variant) : Void;
    public function pushFront(value : Variant) : Void;
    public function removeAt(index : Int) : Void;
    public function resize(size : Int) : Void;
    public function reverse() : Void;
    public function rfind(what: Variant, from: Int = -1) : Int;
    public function set(index : Int, value : Variant) : Void;
    public function shuffle() : Void;
    public function size() : Int;
    public function slice(begin: Int, end: Int, step: Int = 1, deep: Bool = false) : ArrayList;
    public function sort(): Void;
}

class ArrayListIterator {
    public var index: Int;
    public var array: ArrayList;
    public function new(array: ArrayList) {
        this.index = 0;
        this.array = array;
    }

    public function hasNext(): Bool {
        return this.index < this.array.size();
    }

    public function next(): Variant {
        if (this.hasNext()) {
            var value = this.array.get(this.index);
            this.index++;
            return value;
        } else {
            throw "No more elements in the iterator";
        }
    }
}

abstract ArrayListAbstract(ArrayList) from ArrayList to ArrayList {
    @:op([])
    public inline function get(index: Int): Variant {
        return this.get(index);
    }

    @:op([])
    public inline function set(index: Int, value: Variant): Void {
        this.set(index, value);
    }

    @:arrayAccess
    public inline function getArray(index: Int): Variant {
        return this.get(index);
    }

    @:arrayAccess
    public inline function setArray(index: Int, value: Variant): Void {
        this.set(index, value);
    }

    public inline function forEach(callback: Variant->Void): Void {
        for (i in 0...this.size()) {
            callback(this.get(i));
        }
    }

    @:to
    public inline function toArray(): Array<Variant> {
        var result = new Array<Variant>(this.size());
        for (i in 0...this.size()) {
            result[i] = this.get(i);
        }
        return result;
    }

    @:from
    public static function fromArray(array: Array<Variant>): ArrayList {
        var result = new ArrayList();
        for (item in array) {
            result.append(item);
        }
        return result;
    }

    public function iterator(): ArrayListIterator {
        return new ArrayListIterator(this);
    }
}
