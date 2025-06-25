package sunaba.core;

@:native("AtlasTexture")
extern class AtlasTexture extends Texture {
    public var atlas: Texture2D;
    public var filterClip: Bool;
    public var margin: Rect2;
    public var region: Rect2;
    @:native("cast")
    public static function castFrom(type: Dynamic) : AtlasTexture;
}

abstract AtlasTextureAbstract(AtlasTexture) from AtlasTexture to AtlasTexture {
    @:from
    public static function fromResource(resource: Resource) : AtlasTextureAbstract {
        var atlastxt = AtlasTexture.castFrom(resource);
        if (atlastxt.isNull()) {
            return null;
        }
        return atlastxt;
    } 
}