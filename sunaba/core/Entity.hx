package sunaba.core;

import sunaba.native.core.EntityNative;

class Entity extends BaseObject {
    public var entInstance(get, default): EntityNative;
    public function get_entInstance(): EntityNative {
        return cast instance;
    }
    public function new() {
        instance = new EntityNative();
        if (instance == null) {
            throw "Entity.new() returned null";
        }
        pushToStack();
        entInstance = instance;
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

    public function getUserComponent(type: Class<Component>): Component {
        return Component.fromInstance(entInstance.getUserComponent(type));
    }

    public function getComponentByName(name : String) : Component {
        return Component.fromInstance(entInstance.getComponentByName(name));
    }

    public function getComponentsByType(type : Class<Component>, ) : Array<Component> {
        var arr = entInstance.getUserComponentsByType(type);
        var result = new Array<Component>();
        for (comp in arr) {
            result.push(comp);
        }
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