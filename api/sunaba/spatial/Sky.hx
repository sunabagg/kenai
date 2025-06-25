package sunaba.spatial;

import sunaba.core.Resource;
import sunaba.core.Material;

@:native("Sky")
extern class Sky extends Resource {
    public var processMode: Int;
    public var radianceSize: Int;
    public var skyMaterial: Material;
    @:native("cast")
    public static function castFrom(type: Dynamic): Sky;
}

abstract SkyAbstract(Sky) from Sky to Sky {
    @:from
    public static function fromResource(resource: Resource): SkyAbstract {
        var sky = Sky.castFrom(resource);
        if (sky.isNull()) {
            return null;
        }
        return sky;
    } 
} // end package sunaba.spatial