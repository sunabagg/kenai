package kenai.core;

import kenai.core.io.BinaryData;
import lua.Table;
import haxe.Int32;
import haxe.Int64;

@:native("Variant")
extern class VariantNative {
    public function new();
    @:native("new")
    public static function fromInt32(value:Int32):VariantNative;
    @:native("new")
    public static function fromInt64(value:Int64):VariantNative;
    @:native("new")
    public static function fromInt(value:Int):VariantNative;
    @:native("new")
    public static function fromFloat32(vale:Float):VariantNative;
    @:native("new")
    public static function fromFloat64(value:Float):VariantNative;
    @:native("new")
    public static function fromString(value:String):VariantNative;
    @:native("new")
    public static function fromBool(value:Bool):VariantNative;
    @:native("new")
    public static function fromVector2(value:Vector2):VariantNative;
    @:native("new")
    public static function fromVector3(value:Vector3):VariantNative;
    @:native("new")
    public static function fromVector4(value:Vector4):VariantNative;
    @:native("new")
    public static function fromVector2i(value:Vector2i):VariantNative;
    @:native("new")
    public static function fromVector3i(value:Vector3i):VariantNative;
    @:native("new")
    public static function fromVector4i(value:Vector4i):VariantNative;
    @:native("new")
    public static function fromColor(value:Color):VariantNative;
    @:native("new")
    public static function fromRect2(value:Rect2):VariantNative;
    @:native("new")
    public static function fromRect2i(value:Rect2i):VariantNative;
    @:native("new")
    public static function fromBasis(value:Basis):VariantNative;
    @:native("new")
    public static function fromTransform2D(value:Transform2D):VariantNative;
    @:native("new")
    public static function fromTransform3D(value:Transform3D):VariantNative;
    //@:native("new")
    //public static function fromPlane(value:Plane):Variant;
    @:native("new")
    public static function fromQuatrernion(value:Quaternion):VariantNative;
    //@:native("new")
    //public static function fromDictionary(value:Dictionary):Variant;
    //@:native("new")
    //public static function fromArrayList(value:ArrayList):Variant;
    public static function fromByteArray(value:BinaryData):VariantNative;
    public static function fromIntArray(value:Vector<Int>): VariantNative;
    public static function fromIntArray64(value:Vector<Int>): VariantNative;
    public static function fromFloatArray(value:Vector<Float>): VariantNative;
    public static function fromFloatArray64(value:Vector<Float>): VariantNative;
    public static function fromStringArray(value:Vector<String>): VariantNative;
    public static function fromVector2Array(value:Vector<Vector2>): VariantNative;
    public static function fromVector3Array(value:Vector<Vector3>): VariantNative;
    public static function fromVector4Array(value:Vector<Vector4>): VariantNative;
    public static function fromElement(value:Element): VariantNative;
    public static function fromResource(value:Resource): VariantNative;
    public function getType():Int;
    public static function getTypeName(type: Int):String;
    public function asString():String;
    public function asInt32():Int32;
    public function asInt():Int;
    public function asFloat32():Float;
    public function asFloat64():Float;
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
    //public function asPlane():Plane;
    public function asQuaternion():Quaternion;
    //public function asDictionary():Dictionary;
    //public function asArrayList():ArrayList;
    public function asByteArray():BinaryData;
    public function asIntArray():Vector<Int>;
    public function asIntArray64():kenai.core.Vector<Int>;
    public function asFloatArray():Vector<Float>;
    public function asFloatArray64():kenai.core.Vector<Float>;
    public function asStringArray():Vector<String>;
    public function asVector2Array():Vector<Vector2>;
    public function asVector3Array():Vector<Vector3>;
    public function asVector4Array():Vector<Vector4>;
    public function asElement():Element;
    public function asResource():Resource;
    @:native("tostring")
    public function toString():String;
}