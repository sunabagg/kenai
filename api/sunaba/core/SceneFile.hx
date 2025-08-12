package sunaba.core;

class SceneFile extends ScriptableObject {
    public var entities: Array<EntityData> = new Array();

    public static function fromScene(scene: Scene) {
        var data = new SceneFile();
        
        for (i in 0...scene.getEntityCount()) {
            var entity = scene.getEntity(i);
            var entityData = EntityData.fromEntity(entity);
            data.entities.push(entityData);
        }

        return data;
    }

    public function toScene(): SceneManager {
        var sceneManager = new SceneManager();
        var scene = sceneManager.scene;

        for (entData in entities) {
            var entity = entData.toEntity();
            scene.addEntity(entity);
        }

        return sceneManager;
    }

    public override function getData(): Dictionary {
        var data = new Dictionary();

        var entArray = new ArrayList();
        for (entity in entities) {
            var entData = entity.getData();
            entArray.append(entData);
        }
        data.set("entities", entArray);

        return data;
    }

    public override function setData(data: Dictionary) {
        var entArray: ArrayList = data.get("entities");

        for (i in 0...entArray.size()) {
            var entData = entArray.get(i);
            var entity = new EntityData();
            entity.setData(entData);
            entities.push(entity);
        }
    }
}