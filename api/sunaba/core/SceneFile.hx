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
}