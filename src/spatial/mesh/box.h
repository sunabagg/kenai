#ifndef BOX_H
#define BOX_H

#include <godot_cpp/classes/box_mesh.hpp>

#include "../../core/scene_system.h"
#include "mesh_renderer.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial::mesh {

    void bindBox(sol::state& lua);

    class Box : public Component {
    private:
        BoxMesh* boxMesh;
    public:
        Vector3 getSize() {
            return boxMesh->get_size();
        }

        void setSize(Vector3 size) {
            boxMesh->set_size(size);
        }

        int getSubdivideDepth() {
            return boxMesh->get_subdivide_depth();
        }

        void setSubdivideDepth(int depth) {
            boxMesh->set_subdivide_depth(depth);
        }

        int getSubdivideHeight() {
            return boxMesh->get_subdivide_height();
        }

        void setSubdivideHeight(int height) {
            boxMesh->set_subdivide_height(height);
        }

        int getSubdivideWidth() {
            return boxMesh->get_subdivide_width();
        }

        void setSubdivideWidth(int width) {
            boxMesh->set_subdivide_width(width);
        }

        void onInit() override {
            boxMesh = memnew(BoxMesh);
            MeshRenderer* meshRenderer = entity->getComponentByT<MeshRenderer>();
            meshRenderer->getNode()->set_mesh(boxMesh);
        }

        void onFree() override {
            Component::onFree();
            if (boxMesh != nullptr) {
                MeshRenderer* meshRenderer = entity->getComponentByT<MeshRenderer>();
                meshRenderer->getNode()->set_mesh(nullptr);
                boxMesh->unreference();
                boxMesh = nullptr;
            }
           
        }
    };
}

#endif // BOX_H

