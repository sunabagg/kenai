package;

import sunaba.input.InputEvent;
import sunaba.App;
import sunaba.core.Scene;
import sunaba.core.SceneManager;
import sunaba.core.Entity;

class Main extends App{
    public static function main() {
        new Main();
    }

    override function init() {
        try {
            //var aWidget = new AdvancedWidget();
            //rootElement.addChild(aWidget.rootElement);
            var sceneManager = new SceneManager();
            rootElement.addChild(sceneManager);
            var scene : Scene = sceneManager.scene;
            var entity : Entity = new Entity();
            entity.name = "Entity";
            scene.addEntity(entity);
            var inputTest = new InputTest();
            entity.addComponent(inputTest.component, "InputTest");
            //var deltaTimePrinter : DeltaTimePrinter = new DeltaTimePrinter();
            //entity.addComponent(deltaTimePrinter.component, "DeltaTimePrinter");
        }
        catch( e: Dynamic) {
            trace(e);
        }
    }
}