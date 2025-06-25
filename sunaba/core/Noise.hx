package lucidfx.core;

@:native("Noise")
extern class Noise extends Resource {
    public function getImage(width: Int, height: Int, invert: Bool = false, in3dSpace: Bool = false, normalize: Bool = true) : Image;
    public function getImage3D(width: Int, height: Int, depth: Int, invert: Bool = false, normalize: Bool = true) : Image;
    public function getNoise1d(x: Float) : Float;
    public function getNoise2d(x: Float, y: Float) : Float;
    public function getNoise2dv(p: Vector2) : Float;
    public function getNoise3d(x: Float, y: Float, z: Float) : Float;
    public function getNoise3dv(p: Vector3) : Float;
    public function getSeamlessImage(width: Int, height: Int, invert: Bool = false, in3dSpace: Bool = false, skirt: Float = 0.1, normalize: Bool = true) : Image;
    public function getSeamlessImage3D(width: Int, height: Int, depth: Int, invert: Bool = false, skirt: Float = 0.1, normalize: Bool = true) : Image;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Noise;
}

abstract NoiseAbstract(Noise) from Noise to Noise {
    @:from
    public static function fromResource(resource: Resource) : NoiseAbstract {
        var noise = Noise.castFrom(resource);
        if (noise.isNull()) {
            return null;
        }
        return noise;
    } 
}