package support_files.test2.src;

import lucidware.core.*;
import support_files.test2.src.DeltaTimePrinter;

class Main {
    public static function main() {
        Sys.println("Hello, World!");

        var scene : Scene = untyped __lua__("createScene()");
        var entity : Entity = new Entity();
        entity.name = "Entity";
        scene.addEntity(entity);
        var deltaTimePrinter : DeltaTimePrinter = new DeltaTimePrinter();
        entity.addComponent(deltaTimePrinter.component, "DeltaTimePrinter");
    }
}