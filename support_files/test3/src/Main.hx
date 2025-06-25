import lucidfx.core.*;
import lucidfx.spatial.Camera;
import lucidfx.spatial.SpatialTransform;
import lucidfx.spatial.mesh.MeshRenderer;
import lucidfx.spatial.mesh.Box;
import RotateComponent;

class Main {
    public static function main() {
        var scene : Scene = untyped __lua__("createScene()");
        var entity1 = new Entity();
        entity1.name = "Entity1";
        var e1transform = new SpatialTransform();
        entity1.addComponent(e1transform, ObjectUtils.getName(SpatialTransform));
        scene.addEntity(entity1);
        e1transform.position = new Vector3(1, 2, 3);
        var child1 = new Entity();
        child1.name = "Child1";
        var c1transform = new SpatialTransform();
        child1.addComponent(c1transform, ObjectUtils.getName(SpatialTransform));
        entity1.addChild(child1);
        c1transform.position = new Vector3(4, 5, 6);
        var entity2 = new Entity();
        entity2.name = "Entity2";
        var e2transform = new SpatialTransform();
        entity2.addComponent(e2transform, ObjectUtils.getName(SpatialTransform));
        scene.addEntity(entity2);
        e2transform.position = new Vector3(7, 8, 9);
        var entity3 = new Entity();
        entity3.name = "Camera";
        var e3transform = new SpatialTransform();
        entity3.addComponent(e3transform, ObjectUtils.getName(SpatialTransform));
        var camera = new Camera();
        entity3.addComponent(camera, ObjectUtils.getName(Camera));
        scene.addEntity(entity3);
        e3transform.position = new Vector3(0, 0, 1);
        var entity4 = new Entity();
        entity4.name = "Box";
        var e4transform = new SpatialTransform();
        entity4.addComponent(e4transform, ObjectUtils.getName(SpatialTransform));
        var e4mesh = new MeshRenderer();
        entity4.addComponent(e4mesh, ObjectUtils.getName(MeshRenderer));
        var e4box = new Box();
        entity4.addComponent(e4box, ObjectUtils.getName(Box));
        e4box.size = new Vector3(1, 1, 1);
        var rotateComponent = new RotateComponent();
        entity4.addComponent(rotateComponent.component, "RotateComponent");
        scene.addEntity(entity4);
        e4transform.position = new Vector3(0, 0, -1);

        GlobalObjectStack.initSingleton();

        var globalObjectStack = GlobalObjectStack.getSingleton();
        globalObjectStack.stack.push(new StackHandle(scene));
        globalObjectStack.stack.push(new StackHandle(entity1));
        globalObjectStack.stack.push(new StackHandle(child1));
        globalObjectStack.stack.push(new StackHandle(entity2));
        globalObjectStack.stack.push(new StackHandle(entity3));
        globalObjectStack.stack.push(new StackHandle(entity4));
        globalObjectStack.stack.push(new StackHandle(e1transform));
        globalObjectStack.stack.push(new StackHandle(c1transform));
        globalObjectStack.stack.push(new StackHandle(e2transform));
        globalObjectStack.stack.push(new StackHandle(e3transform));
        globalObjectStack.stack.push(new StackHandle(camera));
        globalObjectStack.stack.push(new StackHandle(e4transform));
        globalObjectStack.stack.push(new StackHandle(e4mesh));
        globalObjectStack.stack.push(new StackHandle(e4box));
        globalObjectStack.stack.push(new StackHandle(rotateComponent.component));
        globalObjectStack.stack.push(new StackHandle(rotateComponent));

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