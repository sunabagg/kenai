#include "skeleton_profile_humanoid.h"
#include "../core/resource.h"
#include "../core/base_object.h"

void lucidfx::spatial::bindSkeletonProfileHumanoid(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::SkeletonProfileHumanoid>("SkeletonProfileHumanoid",
        "new", sol::factories(
            []() { return new lucidfx::spatial::SkeletonProfileHumanoid(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, SkeletonProfile>(),
        "boneSize", sol::property(&SkeletonProfileHumanoid::getBoneSize, &SkeletonProfileHumanoid::setBoneSize),
        "groupSize", sol::property(&SkeletonProfileHumanoid::getGroupSize, &SkeletonProfileHumanoid::setGroupSize),
        "rootBone", sol::property(&SkeletonProfileHumanoid::getRootBone, &SkeletonProfileHumanoid::setRootBone),
        "scaleBaseBone", sol::property(&SkeletonProfileHumanoid::getScaleBaseBone, &SkeletonProfileHumanoid::setScaleBaseBone),
        "cast", [](lucidfx::core::Resource* instance) {
            return new SkeletonProfileHumanoid(godot::Object::cast_to<GodotSkeletonProfile>(instance->getResource()));
        }
    );
}