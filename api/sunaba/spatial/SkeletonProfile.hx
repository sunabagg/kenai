package sunaba.spatial;

import sunaba.core.Texture2D;
import sunaba.core.Vector2;
import sunaba.core.Transform3D;
import sunaba.core.Resource;

@:native("SkeletonProfile")
extern class SkeletonProfile extends Resource {
    public var boneSize: Int;
    public var groupSize: Int;
    public var rootBone: String;
    public var scaleBaseBone: String;
    public function findBone(name: String): Int;
    public function getBoneName(index: Int): String;
    public function getBoneParent(index: Int): String;
    public function getBoneTail(index: Int): String;
    public function getGroup(index: Int): String;
    public function getGroupName(index: Int): String;
    public function getHandleOffset(index: Int): Vector2;
    public function getReferencePose(index: Int): Transform3D;
    public function getTailDirection(index: Int): Int;
    public function getTexture(groupIndex: Int): Texture2D;
    public function isRequired(boneIdx: Int): Bool;
    public function setBoneName(index: Int, name: String): Void;
    public function setBoneParent(index: Int, name: String): Void;
    public function setBoneTail(index: Int, name: String): Void;
    public function setGroup(index: Int, name: String): Void;
    public function setGroupName(index: Int, name: String): Void;
    public function setHandleOffset(index: Int, offset: Vector2): Void;
    public function setReferencePose(index: Int, pose: Transform3D): Void;
    public function setRequired(bondIdx: Int, value: Bool): Void;
    public function setTexture(groupIndex: Int, texture: Texture2D): Void;
    @:native("cast")
    public static function castFrom(type: Dynamic): SkeletonProfile;
}

abstract SkeletonProfileAbstract(SkeletonProfile) from SkeletonProfile to SkeletonProfile {
    @:from
    public static function fromResource(resource: Resource): SkeletonProfileAbstract {
        var skeletonProfile = SkeletonProfile.castFrom(resource);
        if (skeletonProfile.isNull()) {
            return null;
        }
        return skeletonProfile;
    } 
} // end package sunaba.spatial