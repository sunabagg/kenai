package sunaba.core;

import sunaba.native.core.EntityNative;

class Entity extends BaseObject {
    public var entInstance(get, default): EntityNative;
    public function get_entInstance(): EntityNative {
        return cast instance;
    }
    public function new() {
        super();
        instance.free();
        instance = new EntityNative();
        if (instance == null) {
            throw "Entity.new() returned null";
        }
        pushToStack();
        entInstance = cast instance;
    }
    public static function fromInstance(instance: EntityNative): Entity {
        if (instance == null) {
            throw "Entity.fromInstance() received null instance";
        }
        var obj = new Entity();
        obj.instance = instance;
        return obj;
    }

    public var name(get, set): String;
    public function get_name(): String {
        return entInstance.name;
    }
    public function set_name(value: String): Void {
        entInstance.name = value;
    }


    public function addComponent(comp: Component, name: String): Void {
        entInstance.addComponent(comp.compInstance, name);
    }

    public function hasComponent(comp: Component): Bool {
        return entInstance.hasComponent(comp);
    }

    public function hasComponentByName(name: String): Bool {
        return entInstance.hasComponentByName(name);
    }
    public function removeComponent(comp: Component): Void {
        entInstance.removeComponent(comp.compInstance);
    }

    public function getComponent(type: Class<Component>): Component {
        return entInstance.getUserComponent(type);
    }

    public function getComponentByName(name : String) : Component {
        return entInstance.getComponentByName(name);
    }

    public function getComponentsByType(type : Class<Component>, ) : Array<Component> {
        var result = entInstance.getUserComponentsByType(type);
        return result;
    }

    public function addChild(child : Entity) : Void {
        entInstance.addChild(child.entInstance);
    }

    public function removeChild(child : Entity) : Void {
        entInstance.removeChild(child.entInstance);
    }

    public function hasChild(child : Entity) : Bool {
        return entInstance.hasChild(child.entInstance);
    }

    public function find(path : String) : Entity {
        return Entity.fromInstance(entInstance.find(path));
    }

    public function getChildCount() : Int {
        return entInstance.getChildCount();
    }

    public function getChild(index: Int) : Entity {
        return Entity.fromInstance(entInstance.getChild(index));
    }
}

abstract EntityAbstract(Entity) from Entity to Entity {
    @:from
    public static function fromBaseObject(obj : BaseObject) : EntityAbstract {
        return Entity.fromInstance(cast obj.instance);
    }

    @:from
    public static function fromInstance(instance : EntityNative) : EntityAbstract {
        return Entity.fromInstance(instance);
    }
}