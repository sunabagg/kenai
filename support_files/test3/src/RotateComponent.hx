package support_files.test3.src;

import sunaba.core.Behavior;
import sunaba.spatial.SpatialTransform;
import haxe.Exception;

class RotateComponent extends Behavior {
    public var transform : SpatialTransform;
    public override function onInit() {
        Sys.println("RotateComponent: onInit called");
        Sys.println("RotateComponent: entity name: " + component.entity.name);
    }

    public override function onReady() {
        Sys.println("RotateComponent: onReady called");
        Sys.println("RotateComponent: entity name: " + component.entity.name);
        try {
            var t : SpatialTransform = getComponent(SpatialTransform);
            if (t == null) {
                Sys.println("RotateComponent: transform is null");
            }
            else {
                Sys.println("RotateComponent: transform is not null");
            }
            transform = t;
            if (transform != null) {
                Sys.println("RotateComponent: transform position: " + transform.position);
                Sys.println("RotateComponent: transform rotation: " + transform.rotation);
                Sys.println("RotateComponent: transform scale: " + transform.scale);
            }
            else {
                Sys.println("RotateComponent: transform is null");
            }
        }
        catch (e : Exception) {
            Sys.println("RotateComponent: onReady error: " + e + " : " + e.stack);
        }
    }
}