package sunaba.spatial;

import sunaba.core.ImageTextureLayered;

@:native("CubemapArray")
extern class CubemapArray extends ImageTextureLayered {
    public function createPlaceholder() : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : CubemapArray;
}

abstract CubemapArrayAbstract(CubemapArray) from CubemapArray to CubemapArray {
    @:from
    public static function fromResource(resource: Resource) : CubemapArrayAbstract {
        var cubemapArray = CubemapArray.castFrom(resource);
        if (cubemapArray.isNull()) {
            return null;
        }
        return cubemapArray;
    } 
} // end package sunaba.spatial