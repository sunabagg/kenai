package sunaba.spatial.mesh;

import sunaba.core.Vector3;
import sunaba.core.Component;

@:native("Box")
extern class Box extends Component {
    public var size : Vector3;
    public var subdivideDepth : Int;
    public var subdivideWidth : Int;
    public var subdivideHeight : Int;
    public static function getFromEntity(entity : sunaba.core.Entity) : Box;
}