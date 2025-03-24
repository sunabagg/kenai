package sunaba.core;

@:native("Texture")
extern class Texture extends Resource {
}

abstract TextureAbstract(Texture) from Texture to Texture {
    @:from
    public static function fromResource(resource: Resource) : TextureAbstract {
        return Texture.castFrom(resource);
    } 
}