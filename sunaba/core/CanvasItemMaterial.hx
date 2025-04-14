package sunaba.core;

@:native("CanvasItemMaterial")
extern class CanvasItemMaterial extends Material {
    public var blendMode: Int;
    public var lightMode: Int;
    public var particlesAnimHFrames: Int;
    public var particlesAnimLoop: Bool;
    public var particlesAnimVFrames: Int;
    public var particlesAnimation: Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic): CanvasItemMaterial;
}

abstract CanvasItemMaterialAbstract(CanvasItemMaterial) from CanvasItemMaterial to CanvasItemMaterial {
    @:from
    public static function fromResource(resource: Resource): CanvasItemMaterialAbstract {
        var canvasItemMaterial = CanvasItemMaterial.castFrom(resource);
        if (canvasItemMaterial.isNull()) {
            return null;
        }
        return canvasItemMaterial;
    } 
} // end package sunaba.core