#include "scene_node.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/os.hpp>
#ifdef USE_PORTABLE_FILE_DIALOGS
#include "portable-file-dialogs.h"
#endif

namespace sunaba::core {
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
            try {
                scene->ready();
            }
            catch (const sol::error& err) {
#ifdef USE_PORTABLE_FILE_DIALOGS
                auto msgBox = pfd::message(
                    "Error", err.what(), pfd::choice::ok, pfd::icon::error
                );
                msgBox.result();
#else
                OS::get_singleton()->alert(
                    err.what(), "Error"
                );
#endif
            }
        }
    }
    void SceneNode::_process(double delta) {
        if (scene != nullptr) {
            try {
                scene->update(delta);
            }
            catch (const sol::error& err) {
#ifdef USE_PORTABLE_FILE_DIALOGS
                auto msgBox = pfd::message(
                    "Error", err.what(), pfd::choice::ok, pfd::icon::error
                );
                msgBox.result();
#else
                OS::get_singleton()->alert(
                    err.what(), "Error"
                );
#endif
            }
        }
    }
    void SceneNode::_physics_process(double delta) {
        if (scene != nullptr) {
            try {
                scene->physicsUpdate(delta);
            }
            catch (const sol::error& err) {
#ifdef USE_PORTABLE_FILE_DIALOGS
                auto msgBox = pfd::message(
                    "Error", err.what(), pfd::choice::ok, pfd::icon::error
                );
                msgBox.result();
#else
                OS::get_singleton()->alert(
                    err.what(), "Error"
                );
#endif
            }
        }
    }
    void SceneNode::_input(const Ref<InputEvent>& event) {}
    void SceneNode::_unhandled_input(const Ref<InputEvent>& event) {}
    void SceneNode::_unhandled_key_input(const Ref<InputEvent>& event) {}
    void SceneNode::_shortcut_input(const Ref<InputEvent>& event) {}

    void bindSceneManager(sol::state& lua) {
        lua.new_usertype<SceneManager>("SceneManager",
            "new", sol::factories(
                []() { return new SceneManager(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element>(),
            "scene", sol::readonly_property(
                &SceneManager::getScene
            ),
            "cast", [](Element* e) {
                SceneNode* sceneNode = Object::cast_to<SceneNode>(e->getNode());
                return new SceneManager(sceneNode);
            }
        );
    }
}