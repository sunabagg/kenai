#include "scene_system.h"

using namespace sunaba::core;

void sunaba::core::bindSceneSystem(sol::state& lua)
{
    lua.new_usertype<NativeReference<BaseObject>>(
        "NativeReference", 
        sol::constructors<NativeReference<BaseObject*>()>(), 
        "free", [](NativeReference<BaseObject> b) { 
            b->free(); 
        }
    );
    lua.new_usertype<NativeReference<Scene>>(
        "Scene", 
        sol::no_constructor,
        sol::base_classes, sol::bases<NativeReference<BaseObject>>(),
        "addEntity", [](NativeReference<Scene> s, NativeReference<Entity> e) { 
            s->addEntity(e.ptr); 
        },
        "hasEntity", [](NativeReference<Scene> s, NativeReference<Entity> e) { 
            return s->hasEntity(e.ptr); 
        },
        "removeEntity", [](NativeReference<Scene> s, NativeReference<Entity> e) { 
            s->removeEntity(e.ptr); 
        },
        "find", [](NativeReference<Scene> s, std::string path) { 
            return s->find(path); 
        },
        "getEntityCount", [](NativeReference<Scene> s) { 
            return s->entities.size(); 
        },
        "getEntity", [](NativeReference<Scene> s, int index) { 
            return new NativeReference<Entity>(
                s->getEntity(index)
            ); 
        }
    );
    lua.new_usertype<NativeReference<Entity>>(
        "Entity", 
        sol::constructors<NativeReference<Entity>()>(),
        sol::base_classes, sol::bases<NativeReference<BaseObject>>(),
        "name",sol::property( 
            [](NativeReference<Entity> e) { 
                return e->name; 
            }, 
            [](NativeReference<Entity> e, std::string name) { 
                e->name = name;  
                if (e->getNode() != nullptr) 
                    e->getNode()->set_name(name.c_str()); 
            } 
        ),
        "addComponent", [](NativeReference<Entity> e, NativeReference<Component> c, std::string name) { 
            e->addComponent(c.ptr, name); 
        },
        "hasComponent", [](NativeReference<Entity> e, sol::table type) { 
            return e->hasComponent(type); 
        },
        "hasComponentByName", [](NativeReference<Entity> e, std::string name) { 
            return e->hasComponentByName(name); 
        },
        "removeComponent", [](NativeReference<Entity> e, NativeReference<Component> c) { 
            e->removeComponent(c.ptr); 
        },
        "removeUserComponent", [](NativeReference<Entity> e, sol::table type) { 
            e->removeUserComponent(type); 
        },
        "removeComponentByName", [](NativeReference<Entity> e, std::string name) { 
            e->removeComponentByName(name); 
        },
        "getComponent", [](NativeReference<Entity> e, sol::table type) { 
            return new NativeReference<Component>(
                e->getComponent(type)
            ); 
        },
        "getUserComponent", [](NativeReference<Entity> e, sol::table type) { 
            return e->getUserComponent(type); 
        },
        "getComponentByName", [](NativeReference<Entity> e, std::string name) { 
            return new NativeReference<Component>(
                e->getComponentByName(name)
            ); 
        },
        "getComponentsByType", [](NativeReference<Entity> e, sol::table type) { 
            auto v = e->getComponentsByType(type); 
            std::vector<NativeReference<Component>> components;
            for (auto& c : v) {
                components.push_back(NativeReference<Component>(c));
            }
            return components;
        },
        "getUserComponentsByType", [](NativeReference<Entity> e, sol::table type) { 
            return e->getUserComponentsByType(type); 
        },
        "addChild", [](NativeReference<Entity> e, NativeReference<Entity> child) { 
            e->addChild(child.ptr); 
        },
        "removeChild", [](NativeReference<Entity> e, NativeReference<Entity> child) { 
            e->removeChild(child.ptr); 
        },
        "hasChild", [](NativeReference<Entity> e, NativeReference<Entity> child) { 
            return e->hasChild(child.ptr); 
        },
        "find", [](NativeReference<Entity> e, std::string path) { 
            return new NativeReference<Entity>(
                e->find(path)
            ); 
        },
        "getChildCount", [](NativeReference<Entity> e) { 
            return e->children.size(); 
        },
        "getChild", [](NativeReference<Entity> e, int index) { 
            return new NativeReference<Entity>(
                e->getChild(index)
            ); 
        }
    );
    lua.new_usertype<NativeReference<Component>>(
        "Component", 
        sol::base_classes, sol::bases<NativeReference<BaseObject>>(),
        "entity", sol::property( 
            [](NativeReference<Component> c) { 
                return c->entity; 
            }
        ),
        "scene", sol::property( 
            [](NativeReference<Component> c) { 
                return c->entity->scene; 
            }
        ),
        "setScriptType", [](NativeReference<Component> c, sol::table type) { 
            c->setScriptType(type); 
        },
        "setScriptInstance", [](NativeReference<Component> c, sol::table instance) { 
            c->setScriptInstance(instance); 
        }
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