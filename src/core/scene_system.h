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
        Entity* entity;
        Scene* scene;

        Component() {}

        virtual ~Component() = default;

        virtual void onInit() {}

        virtual void onReady() {}

        virtual void onUpdate(float delta) {}

        virtual void onPhysicsUpdate(float delta) {}
    };

    class Entity : public BaseObject
    {
    public:
        std::string name;
        std::unordered_map<std::string, std::unique_ptr<Component>> components;
        std::vector<std::unique_ptr<Entity>> children;
        Entity* parent;
        Scene* scene;

        Entity() {
            parent = nullptr;
            scene = nullptr;
        }

        void addComponent(Component* component, std::string name) {
            auto comp = std::unique_ptr<Component>(component);
            comp->entity = this;
            comp->scene = this->scene;
            comp->onInit();
            components[name] = std::move(comp);
        };

        Component* getComponent(std::string name) {
            if (components.find(name) != components.end()) {
                return components[name].get();
            }
            return nullptr;
        }

        void removeComponent(std::string name) {
            components.erase(name);
        }

        bool hasComponent(std::string name) {
            return components.find(name) != components.end();
        }

        template<typename T>
        std::vector<Component*> getComponentsByType() {
            std::vector<Component*> result;
            for (auto& comp : components) {
                if (typeid(T) == typeid(*comp.second.get())) {
                    result.push_back(comp.second.get());
                }
            }
            return result;
        }

        void addChild(Entity* entity) {
            auto ent = std::unique_ptr<Entity>(entity);
            ent->parent = this;
            ent->scene = this->scene;
            children.push_back(std::move(ent));
        }

        void removeChild(Entity* entity) {
            for (auto it = children.begin(); it != children.end(); ++it) {
                if (it->get() == entity) {
                    it->get()->parent = nullptr;
                    it->get()->scene = nullptr;
                    children.erase(it);
                    break;
                }
            }
        }

        bool hasChild(Entity* entity) {
            for (auto& child : children) {
                if (child.get() == entity) {
                    return true;
                }
            }
            return false;
        }

        void ready() {
            for (auto& component : components) {
                component.second->onReady();
            }
            for (auto& child : children) {
                child->ready();
            }
        }

        void update(float delta) {
            for (auto& component : components) {
                component.second->onUpdate(delta);
            }
            for (auto& child : children) {
                child->update(delta);
            }
        }

        void physicsUpdate(float delta) {
            for (auto& component : components) {
                component.second->onPhysicsUpdate(delta);
            }
            for (auto& child : children) {
                child->physicsUpdate(delta);
            }
        }

        void onFree() override {
            for (auto& component : components) {
                component.second->onFree();
            }
            for (auto& child : children) {
                child->onFree();
            }
        }

    };

    class Scene : public BaseObject {
    public:
        std::vector<std::unique_ptr<Entity>> entities;

        void addEntity(Entity* entity) {
            auto ent = std::unique_ptr<Entity>(entity);
            ent->scene = this;
            entities.push_back(std::move(ent));
        }

        void removeEntity(Entity* entity) {
            for (auto it = entities.begin(); it != entities.end(); ++it) {
                if (it->get() == entity) {
                    it->get()->scene = nullptr;
                    entities.erase(it);
                    break;
                }
            }
        }

        bool hasEntity(Entity* entity) {
            for (auto& ent : entities) {
                if (ent.get() == entity) {
                    return true;
                }
            }
            return false;
        }

        void ready() {
            for (auto& entity : entities) {
                entity->ready();
            }
        }

        void update(float delta) {
            for (auto& entity : entities) {
                entity->update(delta);
            }
        }

        void physicsUpdate(float delta) {
            for (auto& entity : entities) {
                entity->physicsUpdate(delta);
            }
        }

        void onFree() override {
            for (auto& entity : entities) {
                entity->onFree();
            }
        }

        Scene() {}
    };
}

#endif //SCENE_SYSTEM_H
