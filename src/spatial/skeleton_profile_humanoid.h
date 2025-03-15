#ifndef SKELETON_PROFILE_H
#define SKELETON_PROFILE_H

#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSkeletonProfile godot::SkeletonProfile

#include "../core/base_object.h"
#include "skeleton_profile.h"

using namespace godot;

#define BaseObject sunaba::core::BaseObject

namespace sunaba::spatial {
    void bindSkeletonProfileHumanoid(sol::state_view& lua);

    // class multi-inherits from SkeletonProfile and BaseObject even though it doesn't need to
    // but GCC has forced my hand and won't stop bitching unless we do this stupid fucking workaround
    // stupid fucking incompetent GNU dickheads
    class SkeletonProfileHumanoid : public SkeletonProfile, public BaseObject {
    private:
        GodotSkeletonProfile* skeletonProfile = nullptr;
    public:
        SkeletonProfileHumanoid() {
            setSkeletonProfile(memnew(GodotSkeletonProfile));
        }

        SkeletonProfileHumanoid(GodotSkeletonProfile* sp) {
            setSkeletonProfile(sp);
        }

        GodotSkeletonProfile* getSkeletonProfile() {
            return skeletonProfile;
        }

        void setSkeletonProfile(GodotSkeletonProfile* sp) {
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

#endif // SKELETON_PROFILE_H