package sunaba.core;

import sunaba.core.io.BinaryData;

extern class Image extends Resource {
    public function adjustBcs(brightness : Float, contrast : Float, saturation : Float) : Void;
    public function blendRect(src : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function blendRectMask(src : Image, mask : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function blitRect(src : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function blitRectMask(src : Image, mask : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function bumpMapToNormalMap(bumpScale : Float = 1.0) : Void;
    public function clearMipmaps() : Void;
    public function compress(mode : Int, source : Int = 0, astcFormat : Int = 0) : Int;
    public function computeImageMetrics(comparedImage : Image, useLuma : Bool) : Map<Dynamic, Dynamic>;
    public function convert(format : Int) : Void;
    public function copyFrom(src : Image) : Void;
    public static function create(width : Int, height : Int, format : Int, mipmaps : Bool = false) : Image;
    public static function createEmpty(width : Int, height : Int, format : Int, mipmaps : Bool = false) : Image;
    public static function createFromData(width : Int, height : Int, format : Int, data : BinaryData, mipmaps : Bool = false) : Image;
    public function crop(width : Int, height : Int) : Void;
    public function decompress() : Int;
    public function detectAlpha() : Void;
    public function detectUsedChannels(source : Int = 0) : Int;
    //public function fill(color : Color) : Void;
    //public function fillRect(rect : Rect2i, color : Color) : Void;
    public function fixAlphaEdges() : Void;
    public function flipX() : Void;
    public function flipY() : Void;
    public function generateMipmaps(renormalize : Bool = false) : Void;
    public function getData() : BinaryData;
    public function getDataSize() : Int;
    public function getFormat() : Int;
    public function getHeight() : Int;
    public function getMipmapCount() : Int;
    public function getMipmapOffset(level : Int) : Int;
    //public function getPixel(x : Int, y : Int) : Color;
    //public function getPixelv(p : Vector2) : Color;
    public function getRegion(rect : Rect2i) : Image;
    public function getSize() : Vector2i;
    public function getUsedRect() : Rect2i;
    public function getWidth() : Int;
    public function hasMipmaps() : Bool;
    public function isCompressed() : Bool;
    public function isEmpty() : Bool;
    public function isInvisible() : Bool;
    public function load(path : String) : Int;
    public function loadBmpFromBuffer(buffer : BinaryData) : Int;
    public static function loadFromFile(path : String) : Image;
    
}