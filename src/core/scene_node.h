#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>

#include "scene_system.h"

using namespace godot;
namespace lucidfx::core {
    
    class SceneNode : public godot::Node {
        GDCLASS(SceneNode, Node)
    protected:
        static void _bind_methods() {}
    private:
        Scene* scene;
    public:

        Scene* getScene() {
            return scene;
        }

        SceneNode();
        ~SceneNode();

        void _ready() override ;
        void _process(double delta) override;
        void _physics_process(double delta) override;
        void _input(const Ref<InputEvent>& event) override;
        void _unhandled_input(const Ref<InputEvent>& event) override;
        void _unhandled_key_input(const Ref<InputEvent>& event) override;
        void _shortcut_input(const Ref<InputEvent>& event) override;
    };
}
#endif