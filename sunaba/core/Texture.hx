package lucidware.core;

@:native("Texture")
extern class Texture extends Resource {
    @:native("cast")
    public static function castFrom(type: Dynamic) : Texture;
}

abstract TextureAbstract(Texture) from Texture to Texture {
    @:from
    public static function fromResource(resource: Resource) : TextureAbstract {
        var txt = Texture.castFrom(resource);
        if (txt.isNull()) {
            return null;
        }
        return txt;
    } 
}