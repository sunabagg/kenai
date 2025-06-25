package lucidfx.core;

@:native("Material")
extern class Material extends Resource {
    public var nextPass: Material;
    public var renderPriority: Int;
    public function createPlaceholder(): Resource;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Material;
}

abstract MaterialAbstract(Material) from Material to Material {
    @:from
    public static function fromResource(resource: Resource) : MaterialAbstract {
        var material = Material.castFrom(resource);
        if (material.isNull()) {
            return null;
        }
        return material;
    } 
}