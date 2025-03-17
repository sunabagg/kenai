package sunaba.core;

import sunaba.native.core.SceneNative;

class Scene extends BaseObject {
    public var scnInstance(get, default) : SceneNative;
    public function get_scnInstance() : SceneNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new SceneNative();
        if (instance == null) {
            throw "Scene.new() returned null";
        }
        pushToStack();
    }

    public static function fromInstance(instance : SceneNative) : Scene {
        if (instance == null) {
            throw "Scene.fromInstance() received null instance";
        }
        var obj = new Scene();
        obj.instance = instance;
        return obj;
    }

    public function addEntity(ent: Entity): Void {
        scnInstance.addEntity(ent.entInstance);
    }

    public function removeEntity(ent: Entity): Void {
        scnInstance.removeEntity(ent.entInstance);
    }

    public function hasEntity(ent : Entity) : Bool {
        return scnInstance.hasEntity(ent.entInstance);
    }

    public function getEntityCount() : Int {
        return scnInstance.getEntityCount();
    }

    public function find(path : String) : Entity {
        return Entity.fromInstance(scnInstance.find(path));
    }

    public function getEntity(index: Int) : Entity {
        return Entity.fromInstance(scnInstance.getEntity(index));
    }
}

abstract SceneAbstract(Scene) from Scene to Scene {
    @:from
    public static function fromObj(scene : BaseObject) : SceneAbstract {
        return Scene.fromInstance(cast scene.instance);
    }

    @:from
    public static function fromInstance(instance: SceneNative) : SceneAbstract {
        return Scene.fromInstance(instance);
    }
}