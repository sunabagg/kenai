package sunaba.core;

import sunaba.core.io.BinaryData;
import lua.Table;
import haxe.Int32;
import haxe.Int64;

@:native("Variant")
extern class Variant {
    public function new();
    @:native("new")
    public static function fromInt32(value:Int32):Variant;
    @:native("new")
    public static function fromInt64(value:Int64):Variant;
    @:native("new")
    public static function fromFloat32(vale:Single):Variant;
    @:native("new")
    public static function fromFloat64(value:Single):Variant;
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
    public static function fromIntArray64(value:Table<Int, Int>): Variant;
    public static function fromFloatArray(value:Table<Int, Float>): Variant;
    public static function fromFloatArray64(value:Table<Int, Float>): Variant;
    public static function fromStringArray(value:Table<Int, String>): Variant;
    public static function fromVector2Array(value:Table<Int, Vector2>): Variant;
    public static function fromVector3Array(value:Table<Int, Vector3>): Variant;
    public static function fromVector4Array(value:Table<Int, Vector4>): Variant;
    public static function fromElement(value:Element): Variant;
    public static function fromResource(value:Resource): Variant;
    public function getType():Int;
    public static function getTypeName(type: Int):String;
    public function asString():String;
    public function asInt32():Int32;
    public function asInt64():Int64;
    public function asFloat32():Single;
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
    public function asPlane():Plane;
    public function asQuaternion():Quaternion;
    //public function asDictionary():Dictionary;
    //public function asArrayList():ArrayList;
    public function asByteArray():BinaryData;
    public function asIntArray():Table<Int, Int>;
    public function asIntArray64():lua.Table<Int, Int>;
    public function asFloatArray():Table<Int, Float>;
    public function asFloatArray64():lua.Table<Int, Float>;
    public function asStringArray():Table<Int, String>;
    public function asVector2Array():Table<Int, Vector2>;
    public function asVector3Array():Table<Int, Vector3>;
    public function asVector4Array():Table<Int, Vector4>;
    public function asElement():Element;
    public function asResource():Resource;
    @:native("tostring")
    public function toString():String;
}

abstract VariantAbstract(Variant) from Variant to Variant {
    @:from
    public static function fromString(value:String):VariantAbstract {
        return Variant.fromString(value);
    }
    @:to
    public static function toString(value:VariantAbstract):String {
        return value.asString();
    }
    @:from
    public static function fromInt(value:Int):VariantAbstract {
        return Variant.fromInt64(value);
    }
    @:to
    public static function toInt(value:VariantAbstract):Int64 {
        return value.asInt64();
    }
    @:from
    public static function fromInt64(value:Int64):VariantAbstract {
        return Variant.fromInt64(value);
    }
    @:to
    public static function toInt64(value:VariantAbstract):Int64 {
        return value.asInt64();
    }
    @:from
    public static function fromInt32(value:Int32):VariantAbstract {
        return Variant.fromInt32(value);
    }
    @:to
    public static function toInt32(value:VariantAbstract):Int32 {
        return value.asInt64().toInt32();
    }
    @:from
    public static function fromFloat32(value:Single):VariantAbstract {
        return Variant.fromFloat32(value);
    }
    @:to
    public static function toFloat32(value:VariantAbstract):Single {
        return value.asFloat32();
    }
    @:from
    public static function fromFloat64(value:Float):VariantAbstract {
        return Variant.fromFloat64(value);
    }
    @:to
    public static function toFloat64(value:VariantAbstract):Float {
        return value.asFloat64();
    }
    @:from
    public static function fromBool(value:Bool):VariantAbstract {
        return Variant.fromBool(value);
    }
    @:to
    public static function toBool(value:VariantAbstract):Bool {
        return value.asBool();
    }
    @:from
    public static function fromVector2(value:Vector2):VariantAbstract {
        return Variant.fromVector2(value);
    }
    @:to
    public static function toVector2(value:VariantAbstract):Vector2 {
        return value.asVector2();
    }
    @:from
    public static function fromVector3(value:Vector3):VariantAbstract {
        return Variant.fromVector3(value);
    }
    @:to
    public static function toVector3(value:VariantAbstract):Vector3 {
        return value.asVector3();
    }
    @:from
    public static function fromVector4(value:Vector4):VariantAbstract {
        return Variant.fromVector4(value);
    }
    @:to
    public static function toVector4(value:VariantAbstract):Vector4 {
        return value.asVector4();
    }
    @:from
    public static function fromVector2i(value:Vector2i):VariantAbstract {
        return Variant.fromVector2i(value);
    }
    @:to
    public static function toVector2i(value:VariantAbstract):Vector2i {
        return value.asVector2i();
    }
    @:from
    public static function fromVector3i(value:Vector3i):VariantAbstract {
        return Variant.fromVector3i(value);
    }
    @:to
    public static function toVector3i(value:VariantAbstract):Vector3i {
        return value.asVector3i();
    }
    @:from
    public static function fromVector4i(value:Vector4i):VariantAbstract {
        return Variant.fromVector4i(value);
    }
    @:to
    public static function toVector4i(value:VariantAbstract):Vector4i {
        return value.asVector4i();
    }
    @:from
    public static function fromColor(value:Color):VariantAbstract {
        return Variant.fromColor(value);
    }
    @:to
    public static function toColor(value:VariantAbstract):Color {
        return value.asColor();
    }
    @:from
    public static function fromRect2(value:Rect2):VariantAbstract {
        return Variant.fromRect2(value);
    }
    @:to
    public static function toRect2(value:VariantAbstract):Rect2 {
        return value.asRect2();
    }
    @:from
    public static function fromRect2i(value:Rect2i):VariantAbstract {
        return Variant.fromRect2i(value);
    }
    @:to
    public static function toRect2i(value:VariantAbstract):Rect2i {
        return value.asRect2i();
    }
    @:from
    public static function fromBasis(value:Basis):VariantAbstract {
        return Variant.fromBasis(value);
    }
    @:to
    public static function toBasis(value:VariantAbstract):Basis {
        return value.asBasis();
    }
    @:from
    public static function fromTransform2D(value:Transform2D):VariantAbstract {
        return Variant.fromTransform2D(value);
    }
    @:to
    public static function toTransform2D(value:VariantAbstract):Transform2D {
        return value.asTransform2D();
    }
    @:from
    public static function fromTransform3D(value:Transform3D):VariantAbstract {
        return Variant.fromTransform3D(value);
    }
    @:to
    public static function toTransform3D(value:VariantAbstract):Transform3D {
        return value.asTransform3D();
    }
    @:from
    public static function fromPlane(value:Plane):VariantAbstract {
        return Variant.fromPlane(value);
    }
    @:to
    public static function toPlane(value:VariantAbstract):Plane {
        return value.asPlane();
    }
    @:from
    public static function fromQuaternion(value:Quaternion):VariantAbstract {
        return Variant.fromQuatrernion(value);
    }
    @:to
    public static function toQuaternion(value:VariantAbstract):Quaternion {
        return value.asQuaternion();
    }
    @:from
    public static function fromElement(value:Element):VariantAbstract {
        return Variant.fromElement(value);
    }
    @:to
    public static function toElement(value:VariantAbstract):Element {
        return value.asElement();
    }
    @:from
    public static function fromResource(value:Resource):VariantAbstract {
        return Variant.fromResource(value);
    }
    @:to
    public static function toResource(value:VariantAbstract):Resource {
        return value.asResource();
    }
    @:from
    public static function fromByteArray(value:BinaryData):VariantAbstract {
        return Variant.fromByteArray(value);
    }
    @:to
    public static function toByteArray(value:VariantAbstract):BinaryData {
        return value.asByteArray();
    }
    /*@:from
    public static function fromIntArray(value:Table<Int, Int>):VariantAbstract {
        return Variant.fromIntArray(value);
    }
    @:to
    public static function toIntArray(value:VariantAbstract):Table<Int, Int> {
        return value.asIntArray();
    }
    */
    @:from
    public static function fromIntArray64(value:lua.Table<Int, Int>):VariantAbstract {
        return Variant.fromIntArray64(value);
    }
    @:to
    public static function toIntArray64(value:VariantAbstract):Table<Int, Int> {
        return value.asIntArray64();
    }
    /*@:from
    public static function fromFloatArray(value:Table<Int, Float>):VariantAbstract {
        return Variant.fromFloatArray(value);
    }
    @:to
    public static function toFloatArray(value:VariantAbstract):Table<Int, Float> {
        return value.asFloatArray();
    }*/
    @:from
    public static function fromFloatArray64(value:Table<Int, Float>):VariantAbstract {
        return Variant.fromFloatArray64(value);
    }
    @:to
    public static function toFloatArray64(value:VariantAbstract):Table<Int, Float> {
        return value.asFloatArray64();
    }
    @:from
    public static function fromStringArray(value:Table<Int, String>):VariantAbstract {
        return Variant.fromStringArray(value);
    }
    @:to
    public static function toStringArray(value:VariantAbstract):Table<Int, String> {
        return value.asStringArray();
    }
    @:from
    public static function fromVector2Array(value:Table<Int, Vector2>):VariantAbstract {
        return Variant.fromVector2Array(value);
    }
    @:to
    public static function toVector2Array(value:VariantAbstract):Table<Int, Vector2> {
        return value.asVector2Array();
    }
    @:from
    public static function fromVector3Array(value:Table<Int, Vector3>):VariantAbstract {
        return Variant.fromVector3Array(value);
    }
    @:to
    public static function toVector3Array(value:VariantAbstract):Table<Int, Vector3> {
        return value.asVector3Array();
    }

    @:from
    public static function fromVector4Array(value:Table<Int, Vector4>):VariantAbstract {
        return Variant.fromVector4Array(value);
    }
    @:to
    public static function toVector4Array(value:VariantAbstract):Table<Int, Vector4> {
        return value.asVector4Array();
    }
}