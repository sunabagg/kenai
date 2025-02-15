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

#include "base_object.h"

namespace newhaven_core
{
    void bindSceneSystem(sol::state& lua);
    
    // Forward declare Scene
    class Scene;
    class Entity;

    class Component : public BaseObject
    {
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

        virtual void onInit() {}

        virtual void onEnterTree() {}

        virtual void onReady() {}

        virtual void onUpdate(double delta) {}

        virtual void onPhysicsUpdate(double delta) {}

        virtual void onExitTree() {}

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
    public:
        std::string name;
        std::unordered_map<std::string, Component*> components;
        std::vector<Entity*> children;
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

        Component* getComponent(std::string name) {
            if (components.find(name) != components.end()) {
                return components[name];
            }
            return nullptr;
        }

        void removeComponent(std::string name) {
            components.erase(name);
        }

        bool hasComponent(std::string _name) {
            return components.find(_name) != components.end();
        }

        template<typename T>
        std::vector<Component*> getComponentsByType() {
            std::vector<Component*> result;
            for (auto& comp : components) {
                if (typeid(T) == typeid(*comp.second)) {
                    result.push_back(comp.second);
                }
            }
            return result;
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
            for (auto& component : components) {
                component.second->onReady();
            }
            for (auto& child : children) {
                child->ready();
            }
        }

        void update(double delta) {
            for (auto& component : components) {
                component.second->onUpdate(delta);
            }
            for (auto& child : children) {
                child->update(delta);
            }
        }

        void physicsUpdate(double delta) {
            for (auto& component : components) {
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

        void ready() {
            for (auto& entity : entities) {
                entity->ready();
            }
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
