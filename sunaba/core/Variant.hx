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
    public static function fromFloat32(vale:Float):Variant;
    @:native("new")
    public static function fromFloat64(value:Float):Variant;
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
    //@:native("new")
    //public static function fromPlane(value:Plane):Variant;
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
    public inline function toString():String {
        return this.asString();
    }
    @:from
    public static function fromInt(value:Int):VariantAbstract {
        return Variant.fromInt64(value);
    }
    @:to
    public inline function toInt():Int64 {
        return this.asInt64();
    }
    @:from
    public static function fromInt64(value:Int64):VariantAbstract {
        return Variant.fromInt64(value);
    }
    @:to
    public inline function toInt64():Int64 {
        return this.asInt64();
    }
    @:from
    public static function fromInt32(value:Int32):VariantAbstract {
        return Variant.fromInt32(value);
    }
    @:to
    public inline function toInt32():Int32 {
        return this.asInt64().toInt32();
    }
    @:from
    public static function fromFloat(value:Float):VariantAbstract {
        return Variant.fromFloat64(value);
    }
    @:to
    public inline function toFloat():Float {
        return this.asFloat64();
    }
    @:from
    public static function fromBool(value:Bool):VariantAbstract {
        return Variant.fromBool(value);
    }
    @:to
    public inline function toBool():Bool {
        return this.asBool();
    }
    @:from
    public static function fromVector2(value:Vector2):VariantAbstract {
        return Variant.fromVector2(value);
    }
    @:to
    public inline function toVector2():Vector2 {
        return this.asVector2();
    }
    @:from
    public static function fromVector3(value:Vector3):VariantAbstract {
        return Variant.fromVector3(value);
    }
    @:to
    public inline function toVector3():Vector3 {
        return this.asVector3();
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
    public inline function toVector2i():Vector2i {
        return this.asVector2i();
    }
    @:from
    public static function fromVector3i(value:Vector3i):VariantAbstract {
        return Variant.fromVector3i(value);
    }
    @:to
    public inline function toVector3i():Vector3i {
        return this.asVector3i();
    }
    @:from
    public static function fromVector4i(value:Vector4i):VariantAbstract {
        return Variant.fromVector4i(value);
    }
    @:to
    public inline function toVector4i():Vector4i {
        return this.asVector4i();
    }
    @:from
    public static function fromColor(value:Color):VariantAbstract {
        return Variant.fromColor(value);
    }
    @:to
    public inline function toColor():Color {
        return this.asColor();
    }
    @:from
    public static function fromRect2(value:Rect2):VariantAbstract {
        return Variant.fromRect2(value);
    }
    @:to
    public inline function toRect2():Rect2 {
        return this.asRect2();
    }
    @:from
    public static function fromRect2i(value:Rect2i):VariantAbstract {
        return Variant.fromRect2i(value);
    }
    @:to
    public inline function toRect2i():Rect2i {
        return this.asRect2i();
    }
    @:from
    public static function fromBasis(value:Basis):VariantAbstract {
        return Variant.fromBasis(value);
    }
    @:to
    public inline function toBasis():Basis {
        return this.asBasis();
    }
    @:from
    public static function fromTransform2D(value:Transform2D):VariantAbstract {
        return Variant.fromTransform2D(value);
    }
    @:to
    public inline function toTransform2D():Transform2D {
        return this.asTransform2D();
    }
    @:from
    public static function fromTransform3D(value:Transform3D):VariantAbstract {
        return Variant.fromTransform3D(value);
    }
    @:to
    public inline function toTransform3D():Transform3D {
        return this.asTransform3D();
    }
    /*@:from
    public static function fromPlane(value:Plane):VariantAbstract {
        return Variant.fromPlane(value);
    }
    @:to
    public static function toPlane(value:VariantAbstract):Plane {
        return value.asPlane();
    }*/
    @:from
    public static function fromQuaternion(value:Quaternion):VariantAbstract {
        return Variant.fromQuatrernion(value);
    }
    @:to
    public inline function toQuaternion():Quaternion {
        return this.asQuaternion();
    }
    @:from
    public static function fromElement(value:Element):VariantAbstract {
        return Variant.fromElement(value);
    }
    @:to
    public inline function toElement():Element {
        return this.asElement();
    }
    @:from
    public static function fromResource(value:Resource):VariantAbstract {
        return Variant.fromResource(value);
    }
    @:to
    public inline function toResource():Resource {
        return this.asResource();
    }
    @:from
    public static function fromByteArray(value:BinaryData):VariantAbstract {
        return Variant.fromByteArray(value);
    }
    @:to
    public inline function toByteArray():BinaryData {
        return this.asByteArray();
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
    public inline function toIntArray64():Table<Int, Int> {
        return this.asIntArray64();
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
    public inline function toFloatArray64():Table<Int, Float> {
        return this.asFloatArray64();
    }
    @:from
    public static function fromStringArray(value:Table<Int, String>):VariantAbstract {
        return Variant.fromStringArray(value);
    }
    @:to
    public inline function toStringArray():Table<Int, String> {
        return this.asStringArray();
    }
    @:from
    public static function fromVector2Array(value:Table<Int, Vector2>):VariantAbstract {
        return Variant.fromVector2Array(value);
    }
    @:to
    public inline function toVector2Array():Table<Int, Vector2> {
        return this.asVector2Array();
    }
    @:from
    public static function fromVector3Array(value:Table<Int, Vector3>):VariantAbstract {
        return Variant.fromVector3Array(value);
    }
    @:to
    public inline function toVector3Array():Table<Int, Vector3> {
        return this.asVector3Array();
    }

    @:from
    public static function fromVector4Array(value:Table<Int, Vector4>):VariantAbstract {
        return Variant.fromVector4Array(value);
    }
    @:to
    public inline function toVector4Array():Table<Int, Vector4> {
        return this.asVector4Array();
    }
}