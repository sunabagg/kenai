package sunaba.core;

@:native("SceneManager")
extern class SceneManager extends Element {
    public final scene: Scene;
    @:native("cast")
    public static function toSceneManager(obj:Any): SceneManager;
}