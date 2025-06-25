package lucidfx.core;

@:native("BitMap")
extern class BitMap extends Resource {
    public function convertToImage() : Image;
    public function create(size : Vector2i) : Void;
    public function createFromImageAlpha(image : Image, threshold : Float) : Void;
    public function getBit(x : Int, y : Int) : Bool;
    public function getBitv(p : Vector2i) : Bool;
    public function getSize() : Vector2i;
    public function getTrueBitCount() : Int;
    public function growMask(pixels : Int, rect : Rect2i) : Void;
    public function opaqueToPolygons(rect : Rect2i, epsilon : Float) : lua.Table<Int, Vector2i>;
    public function resize(size : Vector2i) : Void;
    public function setBit(x : Int, y : Int, bit : Bool) : Void;
    public function setBitRect(rect : Rect2i, bit : Bool) : Void;
    public function setBitv(p : Vector2i, bit : Bool) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : BitMap;
}

abstract BitMapAbstract(BitMap) from BitMap to BitMap {
    @:from
    public static function fromResource(resource: Resource) : BitMapAbstract {
        var bmp = BitMap.castFrom(resource);
        if (bmp.isNull()) {
            return null;
        }
        return bmp;
    } 
}