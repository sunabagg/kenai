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
            data.components.set(name, compData);
        }

        for (i in 0...entity.getChildCount()) {
            var child = entity.getChild(i);
            var childData = fromEntity(child);
            data.children.push(childData);
        }

        return data;
    }
}