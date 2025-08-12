package;

import sunaba.core.io.IoManager;
import sunaba.ui.StyleBoxFlat;
import sunaba.App;
import sunaba.core.SceneFile;
import sunaba.core.Scene;
import sunaba.core.Entity;
import sunaba.spatial.Camera;
import sunaba.spatial.SpatialTransform;
import sunaba.spatial.mesh.MeshRenderer;
import sunaba.spatial.mesh.Box;
import sunaba.core.SceneManager;


class Main extends App {
    public static function main() {
        new Main();
    }

    override function init() {
        var sceneFile = new SceneFile();
        var scenejson = io.loadVariant("app://TestScene.scnj");
        trace(scenejson);
        trace(scenejson == null);
        trace(io.loadText("app://TestScene.scnj"));
        sceneFile.setData(scenejson.toDictionary()); 
        trace(sceneFile.getData());
    }

    public static function printEntity(entity : Entity, indent : String = "    ") : Void {
        Sys.println(indent + "Entity: " + entity.name);
        /*var spatialTransform = SpatialTransform.getFromEntity(entity);
        if (spatialTransform != null) {
            var position = spatialTransform.position;
            var rotation = spatialTransform.rotation;
            var scale = spatialTransform.scale;
            var global = spatialTransform.global;
            Sys.println(indent + "    Transform: " + position.toString() + ", " + rotation.toString() + ", " + scale.toString());
            Sys.println(indent + "    GlobalTransform: " + global.toString());
        }*/        
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