package lucidware.core;

import lucidware.core.io.BinaryData;

@:native("Image")
extern class Image extends Resource {
    public function adjustBcs(brightness : Float, contrast : Float, saturation : Float) : Void;
    public function blendRect(src : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function blendRectMask(src : Image, mask : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function blitRect(src : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function blitRectMask(src : Image, mask : Image, rect: Rect2i, dst : Vector2i) : Void;
    public function bumpMapToNormalMap(bumpScale : Float = 1.0) : Void;
    public function clearMipmaps() : Void;
    public function compress(mode : Int, source : Int = 0, astcFormat : Int = 0) : Int;
    public function computeImageMetrics(comparedImage : Image, useLuma : Bool) : Dictionary;
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
    public function getPixel(x : Int, y : Int) : Color;
    public function getPixelv(p : Vector2) : Color;
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
    public function loadJpegFromBuffer(buffer : BinaryData) : Int;
    public function loadKtxFromBuffer(buffer : BinaryData) : Int;
    public function loadPngFromBuffer(buffer : BinaryData) : Int;
    public function loadSvgtFromBuffer(buffer : BinaryData) : Int;
    public function loadSvgFromString(str : String) : Int;
    public function loadTgaFromBuffer(buffer : BinaryData) : Int;
    public function loadWebpFromBuffer(buffer : BinaryData) : Int;
    public function normalMapToXY() : Void;
    public function premultiplyAlpha() : Void;
    public function resize(width : Int, height : Int, interpolation : Int = 1) : Void;
    public function resizeToPo2(square : Bool = false, interpolation : Int = 1) : Void;
    public function rgbeToSrgb() : Image;
    public function rotate90(direction : Int) : Void;
    public function rotate180() : Void;
    public function saveRxr(path : String, grayscale : Bool = false) : Int;
    public function saveRxrToBuffer(grayscale : Bool = false) : BinaryData;
    public function saveJpeg(path : String, quality : Int = 100) : Int;
    public function saveJpegToBuffer(quality : Int = 100) : BinaryData;
    public function savePng(path : String) : Int;
    public function savePngToBuffer() : BinaryData;
    public function saveWebp(path : String, lossy : Bool = false, quality : Float = 0.75) : Int;
    public function saveWebpToBuffer(lossy : Bool = false, quality : Float = 0.75) : BinaryData;
    public function setData(width : Int, height : Int, useMipmaps : Bool, format : Int, data : BinaryData) : Void;
    public function setPixel(x : Int, y : Int, color : Color) : Void;
    public function setPixelv(p : Vector2, color : Color) : Void;
    public function shrinkX2() : Void;
    public function srgbToLinear() : Void;
    @:native("cast")
    public static function castFrom(res : Resource) : Image;
}

abstract ImageAbstarct(Image) from Image to Image {
    @:from
    public static function fromResource(resource: Resource) : ImageAbstarct {
        var img = Image.castFrom(resource);
        if (img.isNull()) {
            return null;
        }
        return img;
    } 
}