#include "scene_system.h"

using namespace sunaba_core;

void sunaba_core::bindSceneSystem(sol::state& lua)
{
    lua.new_usertype<BaseObject>(
        "BaseObject", 
        sol::constructors<BaseObject()>(), 
        "onFree", &BaseObject::onFree,
        "free", &BaseObject::free
    );
    lua.new_usertype<Scene>(
        "Scene", 
        sol::base_classes, sol::bases<BaseObject>(),
        "addEntity", &Scene::addEntity, 
        "hasEntity", &Scene::hasEntity, 
        "removeEntity", &Scene::removeEntity,
        "update", &Scene::update, 
        "physicsUpdate", &Scene::physicsUpdate, 
        "start", &Scene::start,
        "ready", &Scene::ready, 
        "onFree", &Scene::onFree,
        "find", &Scene::find,
        "getEntityCount", &Scene::getEntityCount,
        "getEntity", &Scene::getEntity);
    lua.new_usertype<Entity>(
        "Entity", 
        sol::constructors<Entity()>(),
        sol::base_classes, sol::bases<BaseObject>(),
        "name",sol::property( [](Entity* e) { return e->name; }, [](Entity* e, std::string name) { e->name = name; }),
        "addComponent", &Entity::addComponent, 
        "hasComponent", &Entity::hasComponent, 
        "hasComponentByName", &Entity::hasComponentByName,
        "removeComponent", &Entity::removeComponent,
        "removeComponentByName", &Entity::removeComponentByName,
        "getComponent", &Entity::getComponent,
        "getUserComponent", &Entity::getUserComponent,
        "getComponentByName", &Entity::getComponentByName,
        "getComponentsByType", &Entity::getComponentsByType,
        "getUserComponentsByType", &Entity::getUserComponentsByType,
        "addChild", &Entity::addChild, 
        "removeChild", &Entity::removeChild,
        "onFree", &Entity::onFree,
        "find", &Entity::find,
        "getChildCount", &Entity::getChildCount,
        "getChild", &Entity::getChild);
    lua.new_usertype<Component>(
        "Component", 
        sol::base_classes, sol::bases<BaseObject>(),
        "entity", sol::property( 
            [](Component* c) { 
                return c->entity; 
            }
        ),
        "scene", sol::property( 
            [](Component* c) { 
                return c->scene; 
            }
        ),
        "onInit", &Component::onInit,
        "onReady", &Component::onReady, 
        "onUpdate", &Component::onUpdate,    
        "onPhysicsUpdate", &Component::onPhysicsUpdate,
        "onFree", &Component::onFree);
}

// hacky way to get around the fact that 
// we can't use the scene removeEntity function in the header file
void sunaba_core::Entity::removeFromScene() {
    scene->removeEntity(this);
}