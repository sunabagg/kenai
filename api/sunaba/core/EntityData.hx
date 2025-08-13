package sunaba.core;

import sunaba.core.Dictionary;

class EntityData extends ScriptableObject {
    public var name: String;
    public var components: Dictionary = new Dictionary();
    public var children: Array<EntityData> = new Array();

    public static function fromEntity(entity: Entity) {
        var data = new EntityData();
        data.name = entity.name;

        var componentNameVector = entity.getComponentNames();
        var componentNames = componentNameVector.toArray();
        for (name in componentNames) {
            var component = entity.getComponentByName(name);
            var compData = component.getData();
            var comDict = new Dictionary();
            comDict.set("data", compData);
            var isUserType = component.isUserType();
            comDict.set("isUserType", isUserType);
            if (isUserType) {
                var userComp = component.getScriptInstance();
                var userCompClass = std.Type.getClass(userComp);
                var userCompName = std.Type.getClassName(userCompClass);
                comDict.set("type", userCompName);
            }
            else {
                var metatable = untyped __lua__("getmetatable(component)");
                var compName = ObjectUtils.getName(metatable);
                comDict.set("type", compName);
            }
            data.components.set(name, comDict);
        }

        for (i in 0...entity.getChildCount()) {
            var child = entity.getChild(i);
            var childData = fromEntity(child);
            data.children.push(childData);
        }

        return data;
    }

    public function toEntity(): Entity {
        var entity = new Entity();
        entity.name = name;

        for (i in 0...components.size()) {
            var compname: String = components.keys().get(i);
            var compDict : Dictionary = components.get(compname);
            var isUserType : Bool = compDict.get("isUserType");
            var compType : String = compDict.get("type");
            var compData: Dictionary = compDict.get("data");
            if (isUserType == true) {
                trace(compType);
                var typeClass = std.Type.resolveClass(compType);
                trace(typeClass == null);
                var instance = std.Type.createInstance(typeClass, []);
                trace(instance == null);
                var behavior: Behavior = cast instance;
                entity.addComponent(behavior.component, compname);
                behavior.setData(compData);
            }
            else if (isUserType == false) {
                var typeArr = compname.split("::");
                var typeNameUser = typeArr[typeArr.length - 1];
                var typeName = StringTools.replace(typeNameUser, ".user", "");
                trace(typeName);
                var typeMetatable = untyped __lua__("_G[typeName]");
                trace(typeMetatable == null);
                var typeInstance: Component = untyped __lua__("typeMetatable.new()");
                trace(typeInstance == null);
                entity.addComponent(typeInstance, compname);
                typeInstance.setData(compData);
            }
        }

        for (childData in children) {
            var child = childData.toEntity();
            entity.addChild(child);
        }

        return entity;
    }

    public override function getData(): Dictionary {
        var data = new Dictionary();

        data.set("name", name);
        data.set("components", components);

        var childrenData = new ArrayList();
        for (child in children) {
            var childData = child.getData();
            childrenData.append(childData);
        }

        data.set("children", childrenData);

        return data;
    }

    public override function setData(data: Dictionary): Void {
        name = data.get("name");
        components = data.get("components");

        var childrenData: ArrayList = data.get("children");
        for (i in 0...childrenData.size()) {
            var childDict : Dictionary = childrenData.get(i);
            var childData = new EntityData();
            childData.setData(childDict);
            children.push(childData);
        }
    }
}