package sunaba.core;

@:generic
extern class Vector<T> {
    public function set(index:Int, value:T):Void;
    public function at(index:Int):T;
}