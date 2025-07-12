package kenai.spatial.mesh;

import kenai.core.Vector3;
import kenai.core.Component;

@:native("Box")
extern class Box extends Component {
    public var size : Vector3;
    public var subdivideDepth : Int;
    public var subdivideWidth : Int;
    public var subdivideHeight : Int;
    public static function getFromEntity(entity : kenai.core.Entity) : Box;
}