package lucidfx.core;

@:native("ImageTextureLayered")
extern class ImageTextureLayered extends TextureLayered {
    public function createFromImages(images: lua.Table<Int, Image>) : Int;
    public function updateLayer(image: Image, layer: Int) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : ImageTextureLayered;
}

abstract ImageTextureLayeredAbstract(ImageTextureLayered) from ImageTextureLayered to ImageTextureLayered {
    @:from
    public static function fromResource(resource: Resource) : ImageTextureLayeredAbstract {
        var imageTextureLayered = ImageTextureLayered.castFrom(resource);
        if (imageTextureLayered.isNull()) {
            return null;
        }
        return imageTextureLayered;
    } 
} // end package lucidfx.core