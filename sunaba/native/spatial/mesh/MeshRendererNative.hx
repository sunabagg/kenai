package sunaba.native.spatial.mesh;

import sunaba.native.spatial.IGeometryInstanceNative;
import sunaba.native.core.EntityNative;

@:native("MeshRenderer")
extern class MeshRendererNative extends IGeometryInstanceNative {
    public function createConvexCollision() : Void;
    public function createDebugTangents() : Void;
    public function createTrimeshCollision() : Void;
    public function findBlendShapeByName(name : String) : Int;
    public function getBlendShapeCount() : Int;
    public function getBlendShapeValue(index : Int) : Float;
    public function getSurfaceOverrideCount() : Int;
    public function setBlendShapeValue(index : Int, value : Float) : Void;
    public static function getFromEntity(entity : EntityNative) : MeshRendererNative;
}