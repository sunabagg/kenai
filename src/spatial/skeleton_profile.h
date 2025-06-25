#ifndef SKELETON_PROFILE_H
#define SKELETON_PROFILE_H

#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSkeletonProfile godot::SkeletonProfile

#include "../core/resource.h"
#include "../core/texture2d.h"

#define Texture2D lucidfx::core::Texture2D

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial {
    void bindSkeletonProfile(sol::state_view& lua);

    class SkeletonProfile : public lucidfx::core::Resource {
    private:
        GodotSkeletonProfile* skeletonProfile = nullptr;
    public:
        SkeletonProfile() {
            setSkeletonProfile(memnew(GodotSkeletonProfile));
        }

        SkeletonProfile(GodotSkeletonProfile* sp) {
            setSkeletonProfile(sp);
        }

        GodotSkeletonProfile* getSkeletonProfile() {
            return skeletonProfile;
        }

        void setSkeletonProfile(GodotSkeletonProfile* sp) {
            skeletonProfile = sp;
            skeletonProfile->reference();
            setResource(skeletonProfile);
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

        int findBone(std::string boneName) {
            return skeletonProfile->find_bone(String(boneName.c_str()));
        }

        std::string getBoneName(int boneIndex) {
            return String(skeletonProfile->get_bone_name(boneIndex)).utf8().get_data();
        }

        std::string getBoneParent(int boneIndex) {
            return String(skeletonProfile->get_bone_parent(boneIndex)).utf8().get_data();
        }

        std::string getBoneTail(int boneIndex) {
            return String(skeletonProfile->get_bone_tail(boneIndex)).utf8().get_data();
        }

        std::string getGroup(int groupIndex) {
            return String(skeletonProfile->get_group(groupIndex)).utf8().get_data();
        }

        std::string getGroupName(int groupIndex) {
            return String(skeletonProfile->get_group_name(groupIndex)).utf8().get_data();
        }

        Vector2 getHandleOffset(int boneIndex) {
            return skeletonProfile->get_handle_offset(boneIndex);
        }

        Transform3D getReferencePose(int boneIndex) {
            return skeletonProfile->get_reference_pose(boneIndex);
        }

        int getTailDirection(int boneIndex) {
            return skeletonProfile->get_tail_direction(boneIndex);
        }

        Texture2D* getTexture(int groupIdx) {
            return new Texture2D(
                skeletonProfile->get_texture(groupIdx).ptr()
            );
        }

        bool isRequired(int boneIndex) {
            return skeletonProfile->is_required(boneIndex);
        }

        void setBoneName(int boneIdx, std::string name) {
            skeletonProfile->set_bone_name(boneIdx, String(name.c_str()));
        }

        void setBoneParent(int boneIdx, std::string name) {
            skeletonProfile->set_bone_parent(boneIdx, String(name.c_str()));
        }

        void setBoneTail(int boneIdx, std::string name) {
            skeletonProfile->set_bone_tail(boneIdx, String(name.c_str()));
        }

        void setGroup(int groupIdx, std::string name) {
            skeletonProfile->set_group(groupIdx, String(name.c_str()));
        }

        void setGroupName(int groupIdx, std::string name) {
            skeletonProfile->set_group_name(groupIdx, String(name.c_str()));
        }

        void setHandleOffset(int boneIdx, Vector2 offset) {
            skeletonProfile->set_handle_offset(boneIdx, offset);
        }

        void setReferencePose(int boneIdx, Transform3D pose) {
            skeletonProfile->set_reference_pose(boneIdx, pose);
        }

        void setRequired(int boneIdx, bool required) {
            skeletonProfile->set_required(boneIdx, required);
        }

        void setTailDirection(int boneIdx, int direction) {
            skeletonProfile->set_tail_direction(boneIdx, static_cast<GodotSkeletonProfile::TailDirection>(direction));
        }

        void setTexture(int groupIdx, Texture2D* texture) {
            skeletonProfile->set_texture(groupIdx, texture->getTexture2D());
        }
    };
}

#endif // SKELETON_PROFILE_H