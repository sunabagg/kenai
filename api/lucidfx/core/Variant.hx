package lucidfx.core;

import lucidfx.core.io.BinaryData;
import lua.Table;
import haxe.Int32;
import haxe.Int64;

abstract Variant(VariantNative) from VariantNative to VariantNative {
    @:from
    public static function fromString(value:String):Variant {
        return VariantNative.fromString(value);
    }
    @:to
    public inline function toString():String {
        return this.asString();
    }
    @:from
    public static function fromInt(value:Int):Variant {
        return VariantNative.fromInt(value);
    }
    @:to
    public inline function toInt():Int64 {
        return this.asInt64();
    }
    @:from
    public static function fromInt64(value:Int64):Variant {
        return VariantNative.fromInt64(value);
    }
    @:to
    public inline function toInt64():Int64 {
        return this.asInt64();
    }
    @:from
    public static function fromInt32(value:Int32):Variant {
        return VariantNative.fromInt32(value);
    }
    @:to
    public inline function toInt32():Int32 {
        return this.asInt32();
    }
    @:from
    public static function fromFloat(value:Float):Variant {
        return VariantNative.fromFloat64(value);
    }
    @:to
    public inline function toFloat():Float {
        return this.asFloat64();
    }
    @:from
    public static function fromBool(value:Bool):Variant {
        return VariantNative.fromBool(value);
    }
    @:to
    public inline function toBool():Bool {
        return this.asBool();
    }
    @:from
    public static function fromVector2(value:Vector2):Variant {
        return VariantNative.fromVector2(value);
    }
    @:to
    public inline function toVector2():Vector2 {
        return this.asVector2();
    }
    @:from
    public static function fromVector3(value:Vector3):Variant {
        return VariantNative.fromVector3(value);
    }
    @:to
    public inline function toVector3():Vector3 {
        return this.asVector3();
    }
    @:from
    public static function fromVector4(value:Vector4):Variant {
        return VariantNative.fromVector4(value);
    }
    @:to
    public inline function toVector4():Vector4 {
        return this.asVector4();
    }
    @:from
    public static function fromVector2i(value:Vector2i):Variant {
        return VariantNative.fromVector2i(value);
    }
    @:to
    public inline function toVector2i():Vector2i {
        return this.asVector2i();
    }
    @:from
    public static function fromVector3i(value:Vector3i):Variant {
        return VariantNative.fromVector3i(value);
    }
    @:to
    public inline function toVector3i():Vector3i {
        return this.asVector3i();
    }
    @:from
    public static function fromVector4i(value:Vector4i):Variant {
        return VariantNative.fromVector4i(value);
    }
    @:to
    public inline function toVector4i():Vector4i {
        return this.asVector4i();
    }
    @:from
    public static function fromColor(value:Color):Variant {
        return VariantNative.fromColor(value);
    }
    @:to
    public inline function toColor():Color {
        return this.asColor();
    }
    @:from
    public static function fromRect2(value:Rect2):Variant {
        return VariantNative.fromRect2(value);
    }
    @:to
    public inline function toRect2():Rect2 {
        return this.asRect2();
    }
    @:from
    public static function fromRect2i(value:Rect2i):Variant {
        return VariantNative.fromRect2i(value);
    }
    @:to
    public inline function toRect2i():Rect2i {
        return this.asRect2i();
    }
    @:from
    public static function fromBasis(value:Basis):Variant {
        return VariantNative.fromBasis(value);
    }
    @:to
    public inline function toBasis():Basis {
        return this.asBasis();
    }
    @:from
    public static function fromTransform2D(value:Transform2D):Variant {
        return VariantNative.fromTransform2D(value);
    }
    @:to
    public inline function toTransform2D():Transform2D {
        return this.asTransform2D();
    }
    @:from
    public static function fromTransform3D(value:Transform3D):Variant {
        return VariantNative.fromTransform3D(value);
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
    public static function fromQuaternion(value:Quaternion):Variant {
        return VariantNative.fromQuatrernion(value);
    }
    @:to
    public inline function toQuaternion():Quaternion {
        return this.asQuaternion();
    }
    @:from
    public static function fromElement(value:Element):Variant {
        return VariantNative.fromElement(value);
    }
    @:to
    public inline function toElement():Element {
        return this.asElement();
    }
    @:from
    public static function fromResource(value:Resource):Variant {
        return VariantNative.fromResource(value);
    }
    @:to
    public inline function toResource():Resource {
        return this.asResource();
    }
    @:from
    public static function fromByteArray(value:BinaryData):Variant {
        return VariantNative.fromByteArray(value);
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
    public static function fromIntArray64(value:lua.Table<Int, Int>):Variant {
        return VariantNative.fromIntArray64(value);
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
    public static function fromFloatArray64(value:Table<Int, Float>):Variant {
        return VariantNative.fromFloatArray64(value);
    }
    @:to
    public inline function toFloatArray64():Table<Int, Float> {
        return this.asFloatArray64();
    }
    @:from
    public static function fromStringArray(value:Table<Int, String>):Variant {
        return VariantNative.fromStringArray(value);
    }
    @:to
    public inline function toStringArray():Table<Int, String> {
        return this.asStringArray();
    }
    @:from
    public static function fromVector2Array(value:Table<Int, Vector2>):Variant {
        return VariantNative.fromVector2Array(value);
    }
    @:to
    public inline function toVector2Array():Table<Int, Vector2> {
        return this.asVector2Array();
    }
    @:from
    public static function fromVector3Array(value:Table<Int, Vector3>):Variant {
        return VariantNative.fromVector3Array(value);
    }
    @:to
    public inline function toVector3Array():Table<Int, Vector3> {
        return this.asVector3Array();
    }

    @:from
    public static function fromVector4Array(value:Table<Int, Vector4>):Variant {
        return VariantNative.fromVector4Array(value);
    }
    @:to
    public inline function toVector4Array():Table<Int, Vector4> {
        return this.asVector4Array();
    }
}