package sunaba.core.io;

@:native("Byte")
extern class ByteObject  {
    public function new();

    @:native("new")
    public static function fromInt(value:Int):ByteObject;

    @:native("new")
    public static function fromFloat(value:Float):ByteObject;

    public function getInt() :Int;

    public function getFloat() :Float;

    public function setInt(value:Int):Void;
    
    public function setFloat(value:Float):Void;
}