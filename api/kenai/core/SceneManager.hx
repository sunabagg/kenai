package kenai.core;

@:native("SceneManager")
extern class SceneManager extends Element {
    public final scene: Scene;
    @:native("cast")
    public static function toSceneManager(obj:Any): SceneManager;
}

abstract SceneManagerAbstract(SceneManager) from SceneManager to SceneManager {
    @:from
    public static function fromElement(e:Element): SceneManagerAbstract {
        var manager = SceneManager.toSceneManager(e);
        if (manager.isNull()) {
            return null;
        }
        return manager;
    }
}