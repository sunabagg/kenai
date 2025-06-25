package sunaba.core;

@:native("TextureLayeredRD")
extern class TextureLayeredRD extends TextureLayered {
    @:native("cast")
    public static function castFrom(type: Dynamic) : TextureLayeredRD;
}

abstract TextureLayeredRDAbstract(TextureLayeredRD) from TextureLayeredRD to TextureLayeredRD {
    @:from
    public static function fromResource(resource: Resource) : TextureLayeredRDAbstract {
        var textureLayeredRD = TextureLayeredRD.castFrom(resource);
        if (textureLayeredRD.isNull()) {
            return null;
        }
        return textureLayeredRD;
    } 
} // end package sunaba.core