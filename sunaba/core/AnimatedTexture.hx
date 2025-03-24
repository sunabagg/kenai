package sunaba.core;

@:native("AnimatedTexture")
extern class AnimatedTexture extends Texture2D {
    public var currentFrame: Int;
    public var frames: Int;
    public var oneShort: Bool;
    public var pause: Bool;
    public var speedScale: Float;
    public function getFrameDuration(frame: Int) : Float;
    public function getFrameTexture(frame: Int) : Texture2D;
    public function setFrameDuration(frame: Int, duration: Float) : Void;
    public function setFrameTexture(frame: Int, texture: Texture2D) : Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : AnimatedTexture;
}

abstract AnimatedTextureAbstract(AnimatedTexture) from AnimatedTexture to AnimatedTexture {
    @:from
    public static function fromResource(resource: Resource) : AnimatedTextureAbstract {
        var animTxt = AnimatedTexture.castFrom(resource);
        if (animTxt.isNull()) {
            return null;
        }
        return animTxt;
    } 
}