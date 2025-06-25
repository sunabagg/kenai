#include "scene_node.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace lucidware::core {
    SceneNode::SceneNode() {
        scene = new Scene();
        scene->root = this;
    }
    
    SceneNode::~SceneNode() {
        if (scene != nullptr) {
            delete scene;
        }
    }

    void SceneNode::_ready() {
        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }
        if (scene != nullptr) {
            scene->ready();
        }
    }
    void SceneNode::_process(double delta) {
        if (scene != nullptr) {
            scene->update(delta);
        }
    }
    void SceneNode::_physics_process(double delta) {
        if (scene != nullptr) {
            scene->physicsUpdate(delta);
        }
    }
    void SceneNode::_input(const Ref<InputEvent>& event) {}
    void SceneNode::_unhandled_input(const Ref<InputEvent>& event) {}
    void SceneNode::_unhandled_key_input(const Ref<InputEvent>& event) {}
    void SceneNode::_shortcut_input(const Ref<InputEvent>& event) {}
}