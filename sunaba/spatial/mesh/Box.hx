package lucidware.spatial.mesh;

import lucidware.core.Vector3;
import lucidware.core.Component;

@:native("Box")
extern class Box extends Component {
    public var size : Vector3;
    public var subdivideDepth : Int;
    public var subdivideWidth : Int;
    public var subdivideHeight : Int;
    public static function getFromEntity(entity : lucidware.core.Entity) : Box;
}