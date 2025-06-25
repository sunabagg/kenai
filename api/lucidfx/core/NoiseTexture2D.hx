package lucidfx.core;

@:native("NoiseTexture2D")
extern class NoiseTexture2D extends Texture2D {
    public var asNormalMap: Bool;
    public var bumpStrength: Float;
    public var colorRamp: Gradient;
    public var generateMipmaps: Bool;
    public var height: Int;
    public var in3dSpace: Bool;
    public var invert: Bool;
    public var noise: Noise;
    public var normalize: Bool;
    public var seamless: Bool;
    public var seamlessBlendSkirt: Float;
    public var width: Int;
    @:native("cast")
    public static function castFrom(type: Dynamic) : NoiseTexture2D;
}

abstract NoiseTexture2DAbstract(NoiseTexture2D) from NoiseTexture2D to NoiseTexture2D {
    @:from
    public static function fromResource(resource: Resource) : NoiseTexture2DAbstract {
        var noiseTexture = NoiseTexture2D.castFrom(resource);
        if (noiseTexture.isNull()) {
            return null;
        }
        return noiseTexture;
    } 
}