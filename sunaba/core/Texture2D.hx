package sunaba.core;

@:native("Texture2D")
extern class Texture2D extends Texture {
    public function createPlaceholder() : Resource;
    public function getHeight() : Int;
    public function getImage() : Image;
    public function getSize() : Vector2;
    public function getWidth() : Int;
    public function hasAlpha() : Bool;
}

abstract Texture2DAbstract(Texture2D) from Texture2D to Texture2D {
    @:from
    public static function fromResource(resource: Resource) : Texture2DAbstract {
        return Texture2D.castFrom(resource);
    } 
}