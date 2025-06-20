#include "skeleton_profile.h"

void sunaba::spatial::bindSkeletonProfile(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::SkeletonProfile>("SkeletonProfile",
        "new", sol::factories(
            []() { return new sunaba::spatial::SkeletonProfile(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "boneSize", sol::property(&SkeletonProfile::getBoneSize, &SkeletonProfile::setBoneSize),
        "groupSize", sol::property(&SkeletonProfile::getGroupSize, &SkeletonProfile::setGroupSize),
        "rootBone", sol::property(&SkeletonProfile::getRootBone, &SkeletonProfile::setRootBone),
        "scaleBaseBone", sol::property(&SkeletonProfile::getScaleBaseBone, &SkeletonProfile::setScaleBaseBone),
        "findBone", &SkeletonProfile::findBone,
        "getBoneName", &SkeletonProfile::getBoneName,
        "getBoneParent", &SkeletonProfile::getBoneParent,
        "getBoneTail", &SkeletonProfile::getBoneTail,
        "getGroup", &SkeletonProfile::getGroup,
        "getGroupName", &SkeletonProfile::getGroupName,
        "getHandleOffset", &SkeletonProfile::getHandleOffset,
        "getReferencePose", &SkeletonProfile::getReferencePose,
        "getTailDirection", &SkeletonProfile::getTailDirection,
        "getTexture", &SkeletonProfile::getTexture,
        "isRequired", &SkeletonProfile::isRequired,
        "setBoneName", &SkeletonProfile::setBoneName,
        "setBoneParent", &SkeletonProfile::setBoneParent,
        "setBoneTail", &SkeletonProfile::setBoneTail,
        "setGroup", &SkeletonProfile::setGroup,
        "setGroupName", &SkeletonProfile::setGroupName,
        "setHandleOffset", &SkeletonProfile::setHandleOffset,
        "setReferencePose", &SkeletonProfile::setReferencePose,
        "setTailDirection", &SkeletonProfile::setTailDirection,
        "setTexture", &SkeletonProfile::setTexture,
        "cast", [](sunaba::core::Resource* instance) {
            return new SkeletonProfile(godot::Object::cast_to<GodotSkeletonProfile>(instance->getResource()));
        }
    );
}