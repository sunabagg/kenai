package lucidware.core;

@:native("TextureLayered")
extern class TextureLayered extends Texture {
    public function getFormat(): Int;
    public function getHeight(): Int;
    public function getLayerData(layer: Int): Image;
    public function getLayerType() : Int;
    public function getLayers(): Int;
    public function getWidth(): Int;
    public function hasMipmaps(): Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic) : TextureLayered;
}

abstract TextureLayeredAbstract(TextureLayered) from TextureLayered to TextureLayered {
    @:from
    public static function fromResource(resource: Resource) : TextureLayeredAbstract {
        var textureLayered = TextureLayered.castFrom(resource);
        if (textureLayered.isNull()) {
            return null;
        }
        return textureLayered;
    } 
} // end package lucidware.core