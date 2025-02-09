#include "scene_system.h"

using namespace newhaven_core;

void newhaven_core::bindSceneSystem(sol::state& lua)
{
    lua.new_usertype<BaseObject>(
        "BaseObject", 
        sol::constructors<BaseObject()>(), 
        "onFree", &BaseObject::onFree,
        "free", &BaseObject::free
    );
    lua.new_usertype<Scene>(
        "Scene", 
        sol::constructors<Scene()>(),
        "addEntity", &Scene::addEntity, 
        "hasEntity", &Scene::hasEntity, 
        "removeEntity", &Scene::removeEntity,
        "update", &Scene::update, 
        "physicsUpdate", &Scene::physicsUpdate, 
        "ready", &Scene::ready, 
        "onFree", &Scene::onFree,
        "find", &Scene::find,
        "getEntityCount", &Scene::getEntityCount,
        "getEntity", &Scene::getEntity);
    lua.new_usertype<Entity>(
        "Entity", 
        sol::constructors<Entity()>(), 
        "name",sol::property( [](Entity* e) { return e->name; }, [](Entity* e, std::string name) { e->name = name; }),
        "addComponent", &Entity::addComponent, 
        "hasComponent", &Entity::hasComponent, 
        "removeComponent", &Entity::removeComponent,
        "addChild", &Entity::addChild, 
        "removeChild", &Entity::removeChild,
        "onFree", &Entity::onFree,
        "find", &Entity::find,
        "getChildCount", &Entity::getChildCount,
        "getChild", &Entity::getChild);
    lua.new_usertype<Component>(
        "Component", 
        sol::constructors<Component()>(), 
        "onInit", &Component::onInit, 
        "onReady", &Component::onReady, 
        "onUpdate", &Component::onUpdate,    
        "onPhysicsUpdate", &Component::onPhysicsUpdate,
        "onFree", &Component::onFree);

}