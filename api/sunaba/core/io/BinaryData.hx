package sunaba.core.io;

import haxe.io.Bytes;

@:native("BinaryData")
// BinaryData is a class that represents a binary data buffer.
extern class BinaryData {
    public function new();

    @:native("new")
    public static function fromTable(table : sunaba.core.Vector<Float>) : BinaryData;

    public function size() : Int;

    public function get(index : Int) : ByteObject;

    public function set(index : Int, value : ByteObject) : Void;
    
    public function resize(size : Int) : Void;

    public function append(value : ByteObject) : Void;

    public function insert(index : Int, value : ByteObject) : Void;

    public function toTable() : sunaba.core.Vector<Float>;
}

function BinaryDataToBytes(binaryData: BinaryData) : Bytes {
    var size = binaryData.size();
    var bytes = Bytes.alloc(size);
    for (i in 0...size) {
        bytes.set(i, binaryData.get(i).getInt());
    }
    return bytes;
}