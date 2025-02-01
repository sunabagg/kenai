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

#include "base_object.h"

namespace newhaven_core
{
    // Forward declare Scene
    class Scene;

    class Component : public BaseObject
    {
    public:
        virtual ~Component() = default;
    };

    // Example Component (Transform)
    class TransformComponent : public Component {
    public:
        float x = 0,
              y = 0,
              z = 0;

        TransformComponent(float x = 0,
                           float y = 0,
                           float z = 0) :
                                 x(x),
                                 y(y),
                                 z(z) {}
    };

    class Entity : public BaseObject
    {
    public:
        std::string name;
        std::unordered_map<std::string, std::unique_ptr<Component>> components;
        std::unordered_map<std::string, std::unique_ptr<Entity>> children;

        template <typename T, typename... Args>
        void addComponent(Args&&... args) {
            components[typeid(T).name()] = std::make_unique<T>(std::forward<Args>(args)...);
        }

        template <typename T>
        T* getComponent() {
            auto it = components.find(typeid(T).name());
            return it != components.end() ? dynamic_cast<T*>(it->second.get()) : nullptr;
        }
    };

    class Scene : public BaseObject {
    public:
        std::unordered_map<std::string, std::unique_ptr<Entity>> entities;

        Scene() {}

        Entity* createEntity(const std::string& name) {
            auto entity = std::make_unique<Entity>(name);
            Entity* ptr = entity.get();
            entities[name] = std::move(entity);
            return ptr;
        }

        Entity* getEntity(const std::string& name) {
            auto it = entities.find(name);
            return it != entities.end() ? it->second.get() : nullptr;
        }
    };
}

#endif //SCENE_SYSTEM_H
