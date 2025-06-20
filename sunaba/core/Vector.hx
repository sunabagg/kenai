package sunaba.core;

@:generic
extern class Vector<T> {
    public function set(index:Int, value:T):Void;
    public function at(index:Int):T;
    public function get(index:Int):T;
    public function find(value:T):Int;
    public function erase(index:Int):Void;
    public function insert(index:Int, value:T):Void;
}