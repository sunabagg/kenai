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
        sol::base_classes, sol::bases<BaseObject>(),
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
        sol::base_classes, sol::bases<BaseObject>(),
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
        sol::base_classes, sol::bases<BaseObject>(),
        "rawEntity", sol::property( [](Component* c) { return c->entity; }, [](Component* c, Entity* e) { c->entity = e; }),
        "rawScene", sol::property( [](Component* c) { return c->scene; }, [](Component* c, Scene* s) { c->scene = s; }),
        "onInit", &Component::onInit,
        "onReady", &Component::onReady, 
        "onUpdate", &Component::onUpdate,    
        "onPhysicsUpdate", &Component::onPhysicsUpdate,
        "onFree", &Component::onFree);

}