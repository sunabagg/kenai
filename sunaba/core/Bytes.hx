package sunaba.core;

@:native("Bytes")
extern class Bytes {
    public function size() : Int;
    public function get(index : Int) : Int;
}