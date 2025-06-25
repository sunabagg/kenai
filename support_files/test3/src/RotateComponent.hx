package;

import lucidware.core.Behavior;
import lucidware.spatial.SpatialTransform;
import haxe.Exception;

class RotateComponent extends Behavior {
    public var transform : SpatialTransform;
    public override function onInit() {
        transform = getComponent(SpatialTransform);
    }

    public override function onUpdate(deltaTime : Float) {
        var rotation = -0.5 * deltaTime;
        transform.rotateY(rotation);
    }
}