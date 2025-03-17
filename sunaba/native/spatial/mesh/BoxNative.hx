package sunaba.native.spatial.mesh;

import sunaba.core.Vector3
import sunaba.native.core.ComponentNative;
import sunaba.native.core.EntityNative;

@:native("Box")
extern class BoxNative extends ComponentNative {
    public var size : Vector3;
    public var subdivideDepth : Int;
    public var subdivideWidth : Int;
    public var subdivideHeight : Int;
    public static function getFromEntity(entity : EntityNative) : BoxNative;
}