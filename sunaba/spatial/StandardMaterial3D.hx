package lucidware.spatial;

import lucidware.core.Material;

@:native("StandardMaterial3D")
extern class StandardMaterial3D extends Material {
    @:native("cast")
    public static function castFrom(type: Dynamic): StandardMaterial3D;
}

abstract StandardMaterial3DAbstract(StandardMaterial3D) from StandardMaterial3D to StandardMaterial3D {
    @:from
    public static function fromResource(resource: Resource): StandardMaterial3DAbstract {
        var standardMaterial = StandardMaterial3D.castFrom(resource);
        if (standardMaterial.isNull()) {
            return null;
        }
        return standardMaterial;
    } 
} // end package lucidware.spatial