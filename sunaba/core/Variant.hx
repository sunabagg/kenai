package sunaba.core;

import sunaba.core.io.BinaryData;
import lua.Table;

@:native("Variant")
extern class Variant {
    public function new();
    @:native("new")
    public static function fromInt(value:Int):Variant;
    @:native("new")
    public static function fromFloat(value:Float):Variant;
    @:native("new")
    public static function fromString(value:String):Variant;
    @:native("new")
    public static function fromBool(value:Bool):Variant;
    @:native("new")
    public static function fromVector2(value:Vector2):Variant;
    @:native("new")
    public static function fromVector3(value:Vector3):Variant;
    @:native("new")
    public static function fromVector4(value:Vector4):Variant;
    @:native("new")
    public static function fromVector2i(value:Vector2i):Variant;
    @:native("new")
    public static function fromVector3i(value:Vector3i):Variant;
    @:native("new")
    public static function fromVector4i(value:Vector4i):Variant;
    @:native("new")
    public static function fromColor(value:Color):Variant;
    @:native("new")
    public static function fromRect2(value:Rect2):Variant;
    @:native("new")
    public static function fromRect2i(value:Rect2i):Variant;
    @:native("new")
    public static function fromBasis(value:Basis):Variant;
    @:native("new")
    public static function fromTransform2D(value:Transform2D):Variant;
    @:native("new")
    public static function fromTransform3D(value:Transform3D):Variant;
    @:native("new")
    public static function fromPlane(value:Plane):Variant;
    @:native("new")
    public static function fromQuatrernion(value:Quaternion):Variant;
    //@:native("new")
    //public static function fromDictionary(value:Dictionary):Variant;
    //@:native("new")
    //public static function fromArrayList(value:ArrayList):Variant;
    public static function fromByteArray(value:BinaryData):Variant;
    public static function fromIntArray(value:Table<Int, Int>): Variant;
    public static function fromIntArray64(value:Array<Int>): Variant;
    public static function fromFloatArray(value:Table<Int, Float>): Variant;
    public static function fromFloatArray64(value:Array<Float>): Variant;
    public static function fromStringArray(value:Table<Int, String>): Variant;
    public static function fromVector2Array(value:Table<Int, Vector2>): Variant;
    public static function fromVector3Array(value:Table<Int, Vector3>): Variant;
    public static function fromElement(value:Element): Variant;
    public static function fromResource(value:Resource): Variant;
    public function getType():Int;
    public function getTypeName():String;
    public function asString():String;
    public function asInt():Int;
    public function asFloat():Float;
    public function asBool():Bool;
    public function asVector2():Vector2;
    public function asVector3():Vector3;
    public function asVector4():Vector4;
    public function asVector2i():Vector2i;
    public function asVector3i():Vector3i;
    public function asVector4i():Vector4i;
    public function asColor():Color;
    public function asRect2():Rect2;
    public function asRect2i():Rect2i;
    public function asBasis():Basis;
    public function asTransform2D():Transform2D;
    public function asTransform3D():Transform3D;
    public function asPlane():Plane;
    public function asQuaternion():Quaternion;
    //public function asDictionary():Dictionary;
    //public function asArrayList():ArrayList;
    public function asByteArray():BinaryData;
    public function asIntArray():Table<Int, Int>;
    public function asIntArray64():Array<Int>;
    public function asFloatArray():Table<Int, Float>;
    public function asFloatArray64():Array<Float>;
    public function asStringArray():Table<Int, String>;
    public function asVector2Array():Table<Int, Vector2>;
    public function asVector3Array():Table<Int, Vector3>;
    public function asElement():Element;
    public function asResource():Resource;
    @:native("tostring")
    public function toString():String;
}