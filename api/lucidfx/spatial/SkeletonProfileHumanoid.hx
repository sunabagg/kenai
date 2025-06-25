package lucidfx.spatial;

@:native("SkeletonProfileHumanoid")
extern class SkeletonProfileHumanoid extends SkeletonProfile {
    public var boneSize: Int;
    public var groupSize: Int;
    public var rootBone: String;
    public var scaleBaseBone: String;
    @:native("cast")
    public static function castFrom(type: Dynamic): SkeletonProfileHumanoid;
}

abstract SkeletonProfileHumanoidAbstract(SkeletonProfileHumanoid) from SkeletonProfileHumanoid to SkeletonProfileHumanoid {
    @:from
    public static function fromResource(resource: Resource): SkeletonProfileHumanoidAbstract {
        var skeletonProfile = SkeletonProfileHumanoid.castFrom(resource);
        if (skeletonProfile.isNull()) {
            return null;
        }
        return skeletonProfile;
    } 
} // end package lucidfx.spatial