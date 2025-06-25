package lucidware.spatial;

import lucidware.core.Resource;
import lucidware.core.Texture;
import lucidware.core.Image;

@:native("Texture3D")
extern class Texture3D extends Texture {
    public function createPlaceholder(): Resource;
    public function getData(): lua.Table<Int, Image>;
    public function getDepth(): Int;
    public function getFormat(): Int;
    public function getHeight(): Int;
    public function getWidth(): Int;
    public function hasMipmaps(): Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic): Texture3D;
}

abstract Texture3DAbstract(Texture3D) from Texture3D to Texture3D {
    @:from
    public static function fromResource(resource: Resource): Texture3DAbstract {
        var texture = Texture3D.castFrom(resource);
        if (texture.isNull()) {
            return null;
        }
        return texture;
    } 
} // end package lucidware.spatial