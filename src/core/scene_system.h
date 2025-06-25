//
// Created by mintkat on 2/1/25.
//

#ifndef SCENE_SYSTEM_H
#define SCENE_SYSTEM_H

#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <godot_cpp/variant/transform3d.hpp>
#include <sol/sol.hpp>
#include <godot_cpp/templates/self_list.hpp>
#include <godot_cpp/classes/main_loop.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "base_object.h"

namespace lucidfx::core
{
    void bindSceneSystem(sol::state& lua);
    
    // Forward declare Scene
    class Scene;
    class Entity;

    class Component : public BaseObject
    {
    private:    
        sol::table scriptType = sol::lua_nil;

        sol::table scriptInstance = sol::lua_nil;
    public:
        enum {
		    // You can make your own, but don't use the same numbers as other notifications in other nodes.
		    NOTIFICATION_ENTER_TREE = 10,
		    NOTIFICATION_EXIT_TREE = 11,
		    NOTIFICATION_MOVED_IN_PARENT = 12,
		    NOTIFICATION_READY = 13,
		    NOTIFICATION_PAUSED = 14,
		    NOTIFICATION_UNPAUSED = 15,
		    NOTIFICATION_PHYSICS_UPDATE = 16,
		    NOTIFICATION_UPDATE = 17,
		    NOTIFICATION_PARENTED = 18,
		    NOTIFICATION_UNPARENTED = 19,
		    NOTIFICATION_SCENE_INSTANTIATED = 20,
		    NOTIFICATION_DRAG_BEGIN = 21,
		    NOTIFICATION_DRAG_END = 22,
		    NOTIFICATION_PATH_RENAMED = 23,
		    NOTIFICATION_CHILD_ORDER_CHANGED = 24,
		    NOTIFICATION_INTERNAL_PROCESS = 25,
		    NOTIFICATION_INTERNAL_PHYSICS_PROCESS = 26,
		    NOTIFICATION_POST_ENTER_TREE = 27,
		    NOTIFICATION_DISABLED = 28,
		    NOTIFICATION_ENABLED = 29,
		    NOTIFICATION_RESET_PHYSICS_INTERPOLATION = 2001, // A GodotSpace Odyssey.
		    // Keep these linked to Node.
		    NOTIFICATION_WM_MOUSE_ENTER = 1002,
		    NOTIFICATION_WM_MOUSE_EXIT = 1003,
		    NOTIFICATION_WM_WINDOW_FOCUS_IN = 1004,
		    NOTIFICATION_WM_WINDOW_FOCUS_OUT = 1005,
		    NOTIFICATION_WM_CLOSE_REQUEST = 1006,
		    NOTIFICATION_WM_GO_BACK_REQUEST = 1007,
		    NOTIFICATION_WM_SIZE_CHANGED = 1008,
		    NOTIFICATION_WM_DPI_CHANGE = 1009,
		    NOTIFICATION_VP_MOUSE_ENTER = 1010,
		    NOTIFICATION_VP_MOUSE_EXIT = 1011,

		    NOTIFICATION_OS_MEMORY_WARNING = godot::MainLoop::NOTIFICATION_OS_MEMORY_WARNING,
		    NOTIFICATION_TRANSLATION_CHANGED = godot::MainLoop::NOTIFICATION_TRANSLATION_CHANGED,
		    NOTIFICATION_WM_ABOUT = godot::MainLoop::NOTIFICATION_WM_ABOUT,
		    NOTIFICATION_CRASH = godot::MainLoop::NOTIFICATION_CRASH,
		    NOTIFICATION_OS_IME_UPDATE = godot::MainLoop::NOTIFICATION_OS_IME_UPDATE,
		    NOTIFICATION_APPLICATION_RESUMED = godot::MainLoop::NOTIFICATION_APPLICATION_RESUMED,
		    NOTIFICATION_APPLICATION_PAUSED = godot::MainLoop::NOTIFICATION_APPLICATION_PAUSED,
		    NOTIFICATION_APPLICATION_FOCUS_IN = godot::MainLoop::NOTIFICATION_APPLICATION_FOCUS_IN,
		    NOTIFICATION_APPLICATION_FOCUS_OUT = godot::MainLoop::NOTIFICATION_APPLICATION_FOCUS_OUT,
		    NOTIFICATION_TEXT_SERVER_CHANGED = godot::MainLoop::NOTIFICATION_TEXT_SERVER_CHANGED,

		    // Editor specific node notifications
		    NOTIFICATION_EDITOR_PRE_SAVE = 9001,
		    NOTIFICATION_EDITOR_POST_SAVE = 9002,
	    };

        Entity* entity;
        Scene* scene;

        Component() {}

        virtual ~Component() = default;

        virtual void onInit() {
            if (scriptInstance == sol::lua_nil) return;
            auto func = scriptInstance["onInit"].get<sol::function>();
            if (!func) return;
            func(scriptInstance);
        }

        virtual void onEnterTree() {
            if (scriptInstance == sol::lua_nil) return;
            auto func = scriptInstance["onEnterTree"].get<sol::function>();
            if (!func) return;
            func(scriptInstance);
        }

        virtual void onReady() {
            if (scriptInstance == sol::lua_nil) return;
            auto func = scriptInstance["onReady"].get<sol::function>();
            if (!func) return;
            func(scriptInstance);
        }

        virtual void onUpdate(double delta) {
            if (scriptInstance == sol::lua_nil) return;
            auto func = scriptInstance["onUpdate"].get<sol::function>();
            if (!func) return;
            
            sol::object deltaObj = sol::make_object(scriptInstance.lua_state(), delta);
            func(scriptInstance, deltaObj);
        }

        virtual void onPhysicsUpdate(double delta) {
            if (scriptInstance == sol::lua_nil) return;
            auto func = scriptInstance["onPhysicsUpdate"].get<sol::function>();
            if (!func) return;
            
            sol::object deltaObj = sol::make_object(scriptInstance.lua_state(), delta);
            func(scriptInstance, deltaObj);
        }

        virtual void onExitTree() {
            if (scriptInstance == sol::lua_nil) return;
            auto func = scriptInstance["onExitTree"].get<sol::function>();
            if (!func) return;
            func(scriptInstance);
        }

        sol::table getScriptType() {
            return scriptType;
        }

        void setScriptType(sol::table t) {
            scriptType = t;
        }

        sol::table getScriptInstance() {
            return scriptInstance;
        }

        void setScriptInstance(sol::table t) {
            scriptInstance = t;
        }

        void onFree() override;

        /*
        template<typename T>
        T* cast() {
            return static_cast<T>(this);
        }
        */
    };

    class Entity : public BaseObject
    {
    private:
        godot::Node* node = nullptr;

        void removeFromScene();

        bool started = false;

        std::vector<Entity*> children;
    public:
        std::string name;
        std::unordered_map<std::string, Component*> components;
        Entity* parent;
        
        Scene* scene;

        Entity() {
            parent = nullptr;
            scene = nullptr;
        }

        godot::Node* getNode() {
            return node;
        }
        
        void setNode(godot::Node* n) {
            if (node != nullptr) {
                godot::List<godot::Node*> c;
                for (auto i = 0; i < node->get_child_count(); i++) {
                    godot::Node* child = node->get_child(i);
                    c.push_back(child);
                    node->remove_child(child);
                }
                for (auto child : c) {
                    n->add_child(child);
                }
                
                node->queue_free();
            }
            node = n;
        }

        Entity* findEnt(godot::PackedStringArray path, int index) {
            if (index == path.size() - 1) {
                return this;
            }
            for (auto& child : children) {
                if (child->name.c_str() == path[index]) {
                    return child->findEnt(path, index + 1);
                }
            }
            return nullptr;
        }

        void setScene(Scene* s) {
            this->scene = s;
            for (auto& component : components) {
                component.second->scene = scene;
            }
            for (auto& child : children) {
                child->setScene(scene);
            }
        }

        void addComponent(Component* component, std::string n) {
            component->entity = this;
            component->scene = this->scene;
            component->onInit();
            components[n] = component;
            if (started) {
                component->onReady();
            }
        };

        void enterTree() {
            for (auto& component : components) {
                component.second->onEnterTree();
                component.second->notification(Component::NOTIFICATION_ENTER_TREE);
            }
            for (auto& child : children) {
                child->enterTree();
            }
        }

        void exitTree() {
            for (auto& component : components) {
                component.second->onExitTree();
                component.second->notification(Component::NOTIFICATION_EXIT_TREE);
            }
            for (auto& child : children) {
                child->exitTree();
            }
        }

        Component* getComponentByName(std::string name) {
            if (components.find(name) != components.end()) {
                return components[name];
            }
            return nullptr;
        }

        void removeComponentByName(std::string name) {
            components.erase(name);
        }

        bool hasComponentByName(std::string _name) {
            return components.find(_name) != components.end();
        }

        template<typename T>
        std::vector<Component*> getComponentsByT() {
            std::vector<Component*> result;
            for (auto& comp : components) {
                if (typeid(T) == typeid(*comp.second)) {
                    result.push_back(comp.second);
                }
            }
            return result;
        }

        std::vector<Component*> getComponentsByType(sol::userdata type) {
            std::vector<Component*> result;
            auto typeName = type["__name"].get<std::string>();
            for (auto& comp : components) {
                if (comp.first == typeName) {
                    result.push_back(comp.second);
                }
            }
            return result;
        }

        sol::table getUserComponentsByType(sol::table t) {
            sol::table result;
            for (auto& comp : components) {
                if (comp.second->getScriptType() == t) {
                    result[comp.first] = comp.second->getScriptInstance();
                }
            }
            return result;
        }

        sol::object getUserComponent(sol::table type) {
            std::cout << "getUserComponent: Looking for component with script type" << std::endl;
            for (auto& comp : components) {
                std::cout << "getUserComponent: Checking component " << comp.first << std::endl;
                auto scriptType = comp.second->getScriptType();
                if (scriptType == sol::lua_nil) {
                    continue;
                }
                if (scriptType == type) {
                    std::cout << "getUserComponent: Found matching component " << comp.first << std::endl;
                    return comp.second->getScriptInstance();
                }
        }
    
            std::cerr << "getUserComponent: No matching component found" << std::endl;
            return sol::lua_nil;
        }

        Component* getComponent(sol::userdata type) {
            auto typeName = type.as<sol::userdata>()["__name"].get<std::string>();
            for (auto& comp : components) {
                if (comp.first == typeName) {
                    return comp.second;
                }
            }
            return nullptr;
        }

        template<typename T>
        T* getComponentByT() {
            for (auto& comp : components) {
                if (typeid(T) == typeid(*comp.second)) {
                    return static_cast<T*>(comp.second);
                }
            }
            return nullptr;
        }

        void removeUserComponent(sol::table type) {
            for (auto& comp : components) {
                if (comp.second->getScriptType() == type) {
                    removeComponentByName(comp.first);
                }
            }
        }

        void removeComponent(Component* component) {
            for (auto& comp : components) {
                if (comp.second == component) {
                    removeComponentByName(comp.first);
                }
            }
        }

        bool hasComponent(sol::table type) {
            for (auto& comp : components) {
                if (comp.second->getScriptType() == type) {
                    return true;
                }
            }
            return false;
        }

        

        void addChild(Entity* entity) {
            entity->parent = this;
            entity->setScene(this->scene);
            children.push_back(entity);
            if (node != nullptr) {
                node->add_child(entity->node);
            }
            if (scene != nullptr)
                entity->enterTree();
            if (started)
                entity->ready();
        }

        void removeChild(Entity* entity) {
            for (auto i = 0; i < children.size(); i++) {
                Entity* ent = children[i];
                if (ent == entity) {
                    ent->parent = nullptr;
                    ent->scene = nullptr;
                    children.erase(children.begin() + i);
                    if (node != nullptr)
                        node->remove_child(entity->node);
                    if (scene != nullptr)
                        ent->exitTree();
                    break;
                }
            }
        }

        bool hasChild(Entity* entity) {
            for (auto& child : children) {
                if (child == entity) {
                    return true;
                }
            }
            return false;
        }
        
        Entity* find(std::string path) {
            godot::String gdStr = path.c_str();
            auto split = gdStr.split("/");
            return findEnt(split, 0);
        }

        size_t getChildCount() {
            return children.size();
        }

        Entity* getChild(size_t index) {
            return children[index];
        }

        void ready() {
            if (started) return;
            for (auto& component : components) {
                component.second->onReady();
            }
            for (auto& child : children) {
                child->ready();
            }
            started = true;
        }

        void update(double delta) {
            for (auto& component : components) {
                if (component.second == nullptr) {
                    godot::UtilityFunctions::printerr("Null component detected", __FILE__, __LINE__, false);
                    continue;
                }
                if (!component.second) {
                    godot::UtilityFunctions::printerr("Invalid component pointer detected", __FILE__, __LINE__, false);
                    continue;
                }
                if (component.second->freed == true) {
                    godot::UtilityFunctions::printerr("Component has been freed", __FILE__, __LINE__, false);
                    continue;
                }
                component.second->onUpdate(delta);
            }
            for (auto& child : children) {
                child->update(delta);
            }
        }

        void physicsUpdate(double delta) {
            for (auto& component : components) {
                if (component.second == nullptr) {
                    godot::UtilityFunctions::printerr("Null component detected", __FILE__, __LINE__, false);
                    continue;
                }
                if (!component.second) {
                    godot::UtilityFunctions::printerr("Invalid component pointer detected", __FILE__, __LINE__, false);
                    continue;
                }
                if (component.second->freed == true) {
                    godot::UtilityFunctions::printerr("Component has been freed", __FILE__, __LINE__, false);
                    continue;
                }
                component.second->onPhysicsUpdate(delta);
            }
            for (auto& child : children) {
                child->physicsUpdate(delta);
            }
        }

        void onFree() override {
            if (parent != nullptr) {
                parent->removeChild(this);
            }
            else if (this->scene != nullptr) {
                removeFromScene();
            }
            for (auto& component : components) {
                if (component.second == nullptr) {
                    std::cerr << "Warning: Null component detected." << std::endl;
                    continue;
                }
                if (!component.second) {
                    std::cerr << "Error: Invalid component pointer detected." << std::endl;
                    continue;
                }
                if (component.second->freed == true) {
                    std::cerr << "Error: Component has been freed." << std::endl;
                    continue;
                }
                component.second->onFree();
            }
            for (auto& child : children) {
                child->onFree();
            }
            if (node != nullptr)
                node->queue_free();
        }
    };

    class Scene : public BaseObject {
    private:
        Entity* findEnt(godot::PackedStringArray path, int index) {
    
            for (auto& child : entities) {
                if (child->name.c_str() == path[index]) {
                    return child->findEnt(path, index + 1);
                }
            }
            return nullptr;
        }

        bool started = false;
    public:
        std::vector<Entity*> entities;
        godot::Node* root;

        godot::Viewport* viewport;

        void addEntity(Entity* entity) {
            entity->setScene(this);
            entities.push_back(entity);
            if (root != nullptr) {
                root->add_child(entity->getNode());
            }
            entity->enterTree();
            if (started) {
                entity->ready();
            }
        }

        void removeEntity(Entity* entity) {
            for (auto i = 0; i < entities.size(); i++) {
                Entity* ent = entities[i];
                if (ent == entity) {
                    ent->scene = nullptr;
                    entities.erase(entities.begin() + i);
                    if (root != nullptr)
                        root->remove_child(entity->getNode());
                    ent->exitTree();
                    break;
                }
            }
        }

        bool hasEntity(Entity* entity) {
            for (auto& ent : entities) {
                if (ent == entity) {
                    return true;
                }
            }
            return false;
        }

        Entity* find(std::string path) {
            godot::String gdStr = path.c_str();
            auto split = gdStr.split("/");
            return findEnt(split, 0);
        }

        size_t getEntityCount() {
            return entities.size();
        }

        Entity* getEntity(size_t index) {
            return entities[index];
        }

        void start() {
            ready();
        }

        void ready() {
            if (started) return;
            for (auto& entity : entities) {
                entity->ready();
            }
            started = true;
        }

        void update(double delta) {
            for (auto& entity : entities) {
                entity->update(delta);
            }
        }

        void physicsUpdate(double delta) {
            for (auto& entity : entities) {
                entity->physicsUpdate(delta);
            }
        }

        void onFree() override {
            for (auto& entity : entities) {
                entity->onFree();
            }
        }

        Scene() : root(memnew(godot::Node)) {};
    };
}

#endif //SCENE_SYSTEM_H
