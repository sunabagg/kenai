package lucidfx.spatial;

import lucidfx.core.Transform3D;
import lucidfx.core.Resource;

@:native("Skin")
extern class Skin extends Resource {
    public function addBind(bone: Int, pose: Transform3D): Void;
    public function addNamedBind(name: String, pose: Transform3D): Void;
    public function clearBinds(): Void;
    public function getBindBone(index: Int): Int;
    public function getBindCount(): Int;
    public function getBindName(index: Int): String;
    public function getBindPose(index: Int): Transform3D;
    public function setBindBone(index: Int, bone: Int): Void;
    public function setBindCount(count: Int): Void;
    public function setBindName(index: Int, name: String): Void;
    public function setBindPose(index: Int, pose: Transform3D): Void;
    @:native("cast")
    public static function castFrom(type: Dynamic): Skin;
}

abstract SkinAbstract(Skin) from Skin to Skin {
    @:from
    public static function fromResource(resource: Resource): SkinAbstract {
        var skin = Skin.castFrom(resource);
        if (skin.isNull()) {
            return null;
        }
        return skin;
    } 
} // end package lucidfx.spatial