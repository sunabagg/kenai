package lucidfx.spatial;

import lucidfx.core.ImageTextureLayered;

@:native("Cubemap")
extern class Cubemap extends ImageTextureLayered {
    public function createPlaceholder() : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Cubemap;
}

abstract CubemapAbstract(Cubemap) from Cubemap to Cubemap {
    @:from
    public static function fromResource(resource: Resource) : CubemapAbstract {
        var cubemap = Cubemap.castFrom(resource);
        if (cubemap.isNull()) {
            return null;
        }
        return cubemap;
    } 
} // end package lucidfx.spatial