#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <vector>
#include <sol/sol.hpp>
//#include <godot_cpp/templates/safe_refcount.hpp>
#include <godot_cpp/templates/self_list.hpp>

#include "../core/scene_system.h"

using namespace sunaba::core;
using namespace godot;

namespace sunaba::spatial
{
    void bindSpatialTransform( sol::state& lua );

    
    class SpatialTransform : public Component
    {
    protected:
        Node3D* node;

    public:
        Basis getBasis() {
            return node->get_basis();
        }
        void setBasis(Basis b) {
            node->set_basis(b);
        }

        Vector3 getPosition() {
            return node->get_position();
        }
        void setPosition(Vector3 p) {
        /**
         * Sets the position of the node.
         *
         * @param p The desired position as a Vector3.
         */
            node->set_position(p);
        }

        Vector3 getRotationDegrees() {
            return node->get_rotation_degrees();
        }
        void setRotationDegrees(Vector3 r) {
            node->set_rotation_degrees(r);
        }

        Vector3 getRotation() {
            return node->get_rotation();
        }
        void setRotation(Vector3 r) {
            node->set_rotation(r);
        }

        Vector3 getScale() {
            return node->get_scale();
        }
        void setScale(Vector3 s) {
            node->set_scale(s);
        }

        Quaternion getQuaternion() {
            return node->get_quaternion();
        }

        void setQuaternion(Quaternion q) {
            node->set_quaternion(q);
        }

        int getRotationOrder() {
            return node->get_rotation_order();
        }

        void setRotationOrder(int order) {
            node->set_rotation_order(static_cast<EulerOrder>(order));
        }

        Transform3D getTransform() {
            return node->get_transform();
        }

        void setTransform(Transform3D t) {
            node->set_transform(t);
        }

        Vector3 getGlobalPosition() {
            return node->get_global_position();
        }
        void setGlobalPosition(Vector3 p) {
            node->set_global_position(p);
        }

        Vector3 getGlobalRotation() {
            return node->get_global_rotation();
        }    
        void setGlobalRotation(Vector3 r) {
            node->set_global_rotation(r);
        }

        Vector3 getGlobalRotationDegrees() {
            return node->get_global_rotation_degrees();
        }

        void setGlobalRotationDegrees(Vector3 r) {
            node->set_global_rotation_degrees(r);
        }

        Basis getGlobalBasis() {
            return node->get_global_basis();
        }

        void setGlobalBasis(Basis b) {
            node->set_global_basis(b);
        }

        Transform3D getGlobalTransform() {
            return node->get_global_transform();
        }

        void setGlobalTransform(Transform3D t) {
            node->set_global_transform(t);
        }

        bool isTopLevel() {
            return node->is_set_as_top_level();
        }

        void setNode(Node3D* n) {
            Transform3D t = node->get_transform();
            n->set_transform(t);
            node = n;
            entity->setNode(n);
        }

        godot::Node* getNode() {
            return node;
        }

        void forceUpdate() {
            node->force_update_transform();
        }

        std::shared_ptr<SpatialTransform> getParentTransform() {
            auto parentNode = node->get_parent();
            std::shared_ptr<Entity> parentEntity = entity->parent;
            if (parentEntity->getNode() == parentNode) {
                std::shared_ptr<SpatialTransform> parentTransform = parentEntity->getComponentByT<SpatialTransform>();
                if (parentTransform) {
                    return parentTransform;
                }
            }
            return nullptr;
        }

        void GlobalRotate(Vector3 axis, float angle) {
            node->global_rotate(axis, angle);
        }

        void GlobalTranslate(Vector3 offset) {
            node->global_translate(offset);
        }

        void globalScale(Vector3 scale) {
            node->global_scale(scale);
        }

        void hide() {
            node->hide();
        }

        bool isScaleDisabled() {
            return node->is_scale_disabled();
        }

        bool isVisibleInTree() {
            return node->is_visible_in_tree();
        }

        void lookAt(Vector3 target, Vector3 up = Vector3(0, 1, 0), bool useModelFront = false) {
            node->look_at(target, up, useModelFront);
        }

        void lookAtFromPosition(Vector3 position, Vector3 target, Vector3 up = Vector3(0, 1, 0), bool useModelFront = false) {
            node->look_at_from_position(position, target, up, useModelFront);
        }

        void orthonormalize() {
            node->orthonormalize();
        }

        void rotate(Vector3 axis, float angle) {
            node->rotate(axis, angle);
        }

        void rotateObjectLocal(Vector3 axis, float angle) {
            node->rotate_object_local(axis, angle);
        }

        void rotateX(float angle) {
            node->rotate_x(angle);
        }

        void rotateY(float angle) {
            node->rotate_y(angle);
        }

        void rotateZ(float angle) {
            node->rotate_z(angle);
        }

        void scaleObjectLocal(Vector3 scale) {
            node->scale_object_local(scale);
        }

        void setDisableScale(bool disable) {
            node->set_disable_scale(disable);
        }

        void setIdentity() {
            node->set_identity();
        }

        void show() {
            node->show();
        }

        Vector3 toGlobal(Vector3 local) {
            return node->to_global(local);
        }

        Vector3 toLocal(Vector3 global) {
            return node->to_local(global);
        }

        void translate(Vector3 offset) {
            node->translate(offset);
        }

        void translateObjectLocal(Vector3 offset) {
            node->translate_object_local(offset);
        }

        void onInit() override {
            node = memnew(Node3D);
            node->set_name(entity->name.c_str());
            entity->setNode(node);
        }

        void onFree() override {
            Component::onFree();
            if (node != nullptr) {
                node->queue_free();
                entity->setNode(nullptr);
            }
        }
    };
}

#endif // TRANSFORM_H