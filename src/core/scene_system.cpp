#include "scene_system.h"

using namespace sunaba::core;

void sunaba::core::bindSceneSystem(sol::state& lua)
{
    lua.new_usertype<BaseObject>(
        "BaseObject", 
        "new", sol::factories(
            []() { return new BaseObject(); }
        ),
        sol::meta_function::garbage_collect, sol::destructor([](BaseObject* b) {  }),
        "onFree", &BaseObject::onFree,
        "free", &BaseObject::free
    );
    lua.new_usertype<Scene>(
        "Scene", 
        sol::base_classes, sol::bases<BaseObject>(),
        sol::meta_function::garbage_collect, sol::destructor([](Scene* s) {  }),
        "addEntity", &Scene::addEntity, 
        "hasEntity", &Scene::hasEntity, 
        "removeEntity", &Scene::removeEntity, 
        "onFree", &Scene::onFree,
        "find", &Scene::find,
        "getEntityCount", &Scene::getEntityCount,
        "getEntity", &Scene::getEntity
    );
    lua.new_usertype<Entity>(
        "Entity", 
        "new", sol::factories(
            []() { return new Entity(); }
        ),
        sol::base_classes, sol::bases<BaseObject>(),
        sol::meta_function::garbage_collect, sol::destructor([](Entity* e) {  }),
        "name",sol::property( 
            [](Entity* e) { 
                return e->name; 
            }, 
            [](Entity* e, std::string name) { 
                e->name = name;  
                if (e->getNode() != nullptr) 
                    e->getNode()->set_name(name.c_str()); 
            } 
        ),
        "addComponent", &Entity::addComponent,
        "hasComponent", &Entity::hasComponent,
        "hasComponentByName", &Entity::hasComponentByName,
        "removeComponent", &Entity::removeComponent,
        "removeUserComponent", &Entity::removeUserComponent,
        "removeComponentByName", &Entity::removeComponentByName,
        "getComponent", &Entity::getComponent,
        "getUserComponent", &Entity::getUserComponent,
        "getComponentByName", &Entity::getComponentByName,
        "getComponentsByType", &Entity::getComponentsByType,
        "getUserComponentsByType", &Entity::getUserComponentsByType,
        "addChild", &Entity::addChild,
        "removeChild", &Entity::removeChild,
        "hasChild", &Entity::hasChild,
        "onFree", &Entity::onFree,
        "find", &Entity::find,
        "getChildCount", &Entity::getChildCount,
        "getChild", &Entity::getChild
    );
    lua.new_usertype<Component>(
        "Component", 
        sol::base_classes, sol::bases<BaseObject>(),
        sol::meta_function::garbage_collect, sol::destructor([](Component* c) {  
        }),
        "entity", sol::property( 
            [](Component* c) { 
                return c->entity; 
            }
        ),
        "scene", sol::property( 
            [](Component* c) { 
                return c->entity->scene; 
            }
        ),
        "onInit", &Component::onInit,
        "onReady", &Component::onReady, 
        "onUpdate", &Component::onUpdate,    
        "onPhysicsUpdate", &Component::onPhysicsUpdate,
        "onFree", &Component::onFree,
        "getData", &Component::getData,
        "setData", &Component::setData,
        "setScriptType", &Component::setScriptType,
        "setScriptInstance", &Component::setScriptInstance
    );
}

// hacky way to get around the fact that 
// we can't use the scene removeEntity function in the header file
void sunaba::core::Entity::removeFromScene() {
    scene->removeEntity(this);
}

void sunaba::core::Component::onFree()  {
    if (entity != nullptr) {
        entity->removeComponent(this);
    }
}