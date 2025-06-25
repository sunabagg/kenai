package sunaba.core.io;

@:native("BinaryData")
// BinaryData is a class that represents a binary data buffer.
extern class BinaryData {
    public function new();

    @:native("new")
    public static function fromTable(table : lua.Table<Int, Float>) : BinaryData;

    public function size() : Int;

    public function get(index : Int) : ByteObject;

    public function set(index : Int, value : ByteObject) : Void;
    
    public function resize(size : Int) : Void;

    public function append(value : ByteObject) : Void;

    public function insert(index : Int, value : ByteObject) : Void;

    public function toTable() : lua.Table<Int, Float>;
}