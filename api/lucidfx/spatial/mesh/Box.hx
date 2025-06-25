package lucidfx.spatial.mesh;

import lucidfx.core.Vector3;
import lucidfx.core.Component;

@:native("Box")
extern class Box extends Component {
    public var size : Vector3;
    public var subdivideDepth : Int;
    public var subdivideWidth : Int;
    public var subdivideHeight : Int;
    public static function getFromEntity(entity : lucidfx.core.Entity) : Box;
}