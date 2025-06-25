package lucidware.spatial.mesh;

import lucidware.spatial.IGeometryInstance;
import lucidware.core.Entity;

@:native("MeshRenderer")
extern class MeshRenderer extends IGeometryInstance {
    public function createConvexCollision() : Void;
    public function createDebugTangents() : Void;
    public function createTrimeshCollision() : Void;
    public function findBlendShapeByName(name : String) : Int;
    public function getBlendShapeCount() : Int;
    public function getBlendShapeValue(index : Int) : Float;
    public function getSurfaceOverrideCount() : Int;
    public function setBlendShapeValue(index : Int, value : Float) : Void;
    public static function getFromEntity(entity : Entity) : MeshRenderer;
}