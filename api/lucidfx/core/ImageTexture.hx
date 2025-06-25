package lucidfx.core;

@:native("ImageTexture")
extern class ImageTexture extends Texture2D {
    public var image: Image;
    public static function createFromImage(image: Image) : ImageTexture;
    public function getFormat() : Int;
    public function setSizeOverride(size: Vector2) : Void;
    public function update(image: Image) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : ImageTexture;
}

abstract ImageTextureAbstract(ImageTexture) from ImageTexture to ImageTexture {
    @:from
    public static function fromResource(resource: Resource) : ImageTextureAbstract {
        var imgTxt = ImageTexture.castFrom(resource);
        if (imgTxt.isNull()) {
            return null;
        }
        return imgTxt;
    } 
}