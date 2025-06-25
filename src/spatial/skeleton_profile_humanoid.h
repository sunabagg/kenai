#ifndef SKELETON_PROFILE_HUMANOID_H
#define SKELETON_PROFILE_HUMANOID_H

#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSkeletonProfile godot::SkeletonProfile

#include "../core/base_object.h"
#include "skeleton_profile.h"

using namespace godot;


namespace lucidware::spatial {
    void bindSkeletonProfileHumanoid(sol::state_view& lua);

    class SkeletonProfileHumanoid : public SkeletonProfile {
    private:
        GodotSkeletonProfile* skeletonProfile = nullptr;
    public:
        SkeletonProfileHumanoid() {
            setSkeletonProfileHumanoid(memnew(GodotSkeletonProfile));
        }

        SkeletonProfileHumanoid(GodotSkeletonProfile* sp) {
            setSkeletonProfileHumanoid(sp);
        }

        GodotSkeletonProfile* getSkeletonProfile() {
            return skeletonProfile;
        }

        void setSkeletonProfileHumanoid(GodotSkeletonProfile* sp) {
            skeletonProfile = sp;
            skeletonProfile->reference();
            setSkeletonProfile(skeletonProfile);
        }

        int getBoneSize() {
            return skeletonProfile->get_bone_size();
        }

        void setBoneSize(int size) {
            skeletonProfile->set_bone_size(size);
        }

        int getGroupSize() {
            return skeletonProfile->get_group_size();
        }

        void setGroupSize(int size) {
            skeletonProfile->set_group_size(size);
        }

        std::string getRootBone() {
            return String(skeletonProfile->get_root_bone()).utf8().get_data();
        }

        void setRootBone(std::string name) {
            skeletonProfile->set_root_bone(String(name.c_str()));
        }

        std::string getScaleBaseBone() {
            return String(skeletonProfile->get_scale_base_bone()).utf8().get_data();
        }

        void setScaleBaseBone(std::string name) {
            skeletonProfile->set_scale_base_bone(String(name.c_str()));
        }
    };
}

#endif // SKELETON_PROFILE_HUMANOID_H