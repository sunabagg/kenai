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
                var userCompType = std.Type.typeof(userComp);
                var userCompName = userCompType.getName();
            }
            data.components.set(name, compData);
        }

        for (i in 0...entity.getChildCount()) {
            var child = entity.getChild(i);
            var childData = fromEntity(child);
            data.children.push(childData);
        }

        return data;
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
        components = data.get("Components");

        var childrenData: ArrayList = data.get("children");
        for (i in 0...childrenData.size()) {
            var childDict : Dictionary = childrenData.get(i);
            var childData = new EntityData();
            childData.setData(childDict);
            children.push(childData);
        }
    }
}