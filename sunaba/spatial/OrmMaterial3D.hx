package lucidware.spatial;

@:native("OrmMaterial3D")
extern class OrmMaterial3D extends BaseMaterial3D {
    @:native("cast")
    public static function castFrom(type: Dynamic): OrmMaterial3D;
}

abstract OrmMaterial3DAbstract(OrmMaterial3D) from OrmMaterial3D to OrmMaterial3D {
    @:from
    public static function fromResource(resource: Resource): OrmMaterial3DAbstract {
        var ormMaterial3D = OrmMaterial3D.castFrom(resource);
        if (ormMaterial3D.isNull()) {
            return null;
        }
        return ormMaterial3D;
    } 
} // end package lucidware.spatial