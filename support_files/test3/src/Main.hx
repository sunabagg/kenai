import sunaba.core.*;
import sunaba.spatial.Camera;
import sunaba.spatial.SpatialTransform;
import sunaba.spatial.mesh.MeshRenderer;
import sunaba.spatial.mesh.Box;
import support_files.test3.src.RotateComponent;

class Main {
    public static function main() {
        var scene : Scene = untyped __lua__("createScene()");
        var entity1 = new Entity();
        entity1.name = "Entity1";
        var e1transform = new SpatialTransform();
        e1transform.setScriptType(SpatialTransform);
        e1transform.setScriptInstance(e1transform);
        entity1.addComponent(e1transform, ObjectUtils.getName(SpatialTransform));
        scene.addEntity(entity1);
        e1transform.position = new Vector3(1, 2, 3);
        var child1 = new Entity();
        child1.name = "Child1";
        var c1transform = new SpatialTransform();
        c1transform.setScriptType(SpatialTransform);
        c1transform.setScriptInstance(c1transform);
        child1.addComponent(c1transform, ObjectUtils.getName(SpatialTransform));
        entity1.addChild(child1);
        c1transform.position = new Vector3(4, 5, 6);
        var entity2 = new Entity();
        entity2.name = "Entity2";
        var e2transform = new SpatialTransform();
        e2transform.setScriptType(SpatialTransform);
        e2transform.setScriptInstance(e2transform);
        entity2.addComponent(e2transform, ObjectUtils.getName(SpatialTransform));
        scene.addEntity(entity2);
        e2transform.position = new Vector3(7, 8, 9);
        var entity3 = new Entity();
        entity3.name = "Camera";
        var e3transform = new SpatialTransform();
        e3transform.setScriptType(SpatialTransform);
        e3transform.setScriptInstance(e3transform);
        entity3.addComponent(e3transform, ObjectUtils.getName(SpatialTransform));
        var camera = new Camera();
        entity3.addComponent(camera, ObjectUtils.getName(Camera));
        scene.addEntity(entity3);
        e3transform.position = new Vector3(0, 0, 1);
        var entity4 = new Entity();
        entity4.name = "Box";
        var e4transform = new SpatialTransform();
        e4transform.setScriptType(SpatialTransform);
        e4transform.setScriptInstance(e4transform);
        entity4.addComponent(e4transform, ObjectUtils.getName(SpatialTransform));
        var e4mesh = new MeshRenderer();
        e4mesh.setScriptType(MeshRenderer);
        e4mesh.setScriptInstance(e4mesh);
        entity4.addComponent(e4mesh, ObjectUtils.getName(MeshRenderer));
        var e4box = new Box();
        e4box.setScriptType(Box);
        e4box.setScriptInstance(e4box);
        entity4.addComponent(e4box, ObjectUtils.getName(Box));
        e4box.size = new Vector3(1, 1, 1);
        var rotateComponent = new RotateComponent();
        entity4.addComponent(rotateComponent.component, "RotateComponent");
        scene.addEntity(entity4);
        e4transform.position = new Vector3(0, 0, -1);

        try {
            printScene(scene);
        }
        catch (e : Dynamic) {
            Sys.println("Error: " + e + " : " + e.stack);
        }
    }

    public static function printEntity(entity : Entity, indent : String = "    ") : Void {
        Sys.println(indent + "Entity: " + entity.name);
        var spatialTransform = SpatialTransform.getFromEntity(entity);
        if (spatialTransform != null) {
            var position = spatialTransform.position;
            var rotation = spatialTransform.rotation;
            var scale = spatialTransform.scale;
            var global = spatialTransform.global;
            Sys.println(indent + "    Transform: " + position.toString() + ", " + rotation.toString() + ", " + scale.toString());
            Sys.println(indent + "    GlobalTransform: " + global.toString());
        }        
        for (child in 0...entity.getChildCount()) {
            var childEntity = entity.getChild(child);
            printEntity(childEntity, indent + "    ");
        }
    }

    public static function printScene(scene : Scene) : Void {
        Sys.println("Scene: " + scene);
        for (entity in 0...scene.getEntityCount()) {
            var entity = scene.getEntity(entity);
            printEntity(entity);
        }
    }
}