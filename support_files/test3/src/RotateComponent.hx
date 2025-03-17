package support_files.test3.src;

import sunaba.core.Component;
import sunaba.spatial.SpatialTransform;
import haxe.Exception;

class RotateComponent extends Component {
    public var transform : SpatialTransform;
    public override function onInit() {
        transform = getComponent(SpatialTransform);
    }

    public override function onUpdate(deltaTime : Float) {
        var rotation = -0.5 * deltaTime;
        transform.rotateY(rotation);
    }
}