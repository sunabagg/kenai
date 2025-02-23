#include "scene_system.h"

using namespace sunaba::core;

void sunaba::core::bindSceneSystem(sol::state& lua)
{
    lua.new_usertype<NativeReferenceBase>(
        "BaseObject", 
        sol::constructors<NativeReferenceBase()>(), 
        "free", [](NativeReferenceBase& b) { 
            b->free(); 
        }
    );
    lua.new_usertype<SceneReference>(
        "Scene", 
        sol::no_constructor,
        sol::base_classes, sol::bases<NativeReferenceBase>(),
        "addEntity", [](SceneReference& s, EntityReference& e) { 
            NativeReference<Scene>(s).ptr->addEntity(NativeReference<Entity>(e).ptr); 
        },
        "hasEntity", [](SceneReference& s, EntityReference& e) { 
            return NativeReference<Scene>(s)->hasEntity(NativeReference<Entity>(e).ptr); 
        },
        "removeEntity", [](SceneReference& s, EntityReference& e) { 
            NativeReference<Scene>(s)->removeEntity(NativeReference<Entity>(e).ptr); 
        },
        "find", [](SceneReference& s, std::string path) { 
            return NativeReference<Scene>(s)->find(path); 
        },
        "getEntityCount", [](SceneReference& s) { 
            return NativeReference<Scene>(s)->entities.size(); 
        },
        "getEntity", [](SceneReference& s, int index) { 
            return new EntityReference(
                NativeReference<Scene>(s)->getEntity(index)
            ); 
        }
    );
    lua.new_usertype<EntityReference>(
        "Entity", 
        sol::constructors<EntityReference()>(),
        sol::base_classes, sol::bases<NativeReferenceBase>(),
        "name",sol::property( 
            [](EntityReference& e) { 
                return NativeReference<Entity>(e)->name; 
            }, 
            [](EntityReference& e, std::string name) { 
                NativeReference<Entity>(e)->name = name;  
                if (NativeReference<Entity>(e)->getNode() != nullptr) 
                NativeReference<Entity>(e)->getNode()->set_name(name.c_str()); 
            } 
        ),
        "addComponent", [](EntityReference& e, ComponentReference c, std::string name) { 
            NativeReference<Entity>(e)->addComponent(NativeReference<Component>(c).ptr, name); 
        },
        "hasComponent", [](EntityReference& e, sol::table type) { 
            return NativeReference<Entity>(e)->hasComponent(type); 
        },
        "hasComponentByName", [](EntityReference& e, std::string name) { 
            return NativeReference<Entity>(e)->hasComponentByName(name); 
        },
        "removeComponent", [](EntityReference& e, ComponentReference c) { 
            NativeReference<Entity>(e)->removeComponent(NativeReference<Component>(c).ptr); 
        },
        "removeUserComponent", [](EntityReference& e, sol::table type) { 
            NativeReference<Entity>(e)->removeUserComponent(type); 
        },
        "removeComponentByName", [](EntityReference& e, std::string name) { 
            NativeReference<Entity>(e)->removeComponentByName(name); 
        },
        "getComponent", [](EntityReference& e, sol::table type) { 
            return new ComponentReference(
                NativeReference<Entity>(e)->getComponent(type)
            ); 
        },
        "getUserComponent", [](EntityReference& e, sol::table type) { 
            return NativeReference<Entity>(e)->getUserComponent(type); 
        },
        "getComponentByName", [](EntityReference& e, std::string name) { 
            return new ComponentReference(
                NativeReference<Entity>(e)->getComponentByName(name)
            ); 
        },
        "getComponentsByType", [](EntityReference& e, sol::table type) { 
            auto v = NativeReference<Entity>(e)->getComponentsByType(type); 
            std::vector<ComponentReference> components;
            for (auto& c : v) {
                components.push_back(ComponentReference(c));
            }
            return components;
        },
        "getUserComponentsByType", [](EntityReference& e, sol::table type) { 
            return NativeReference<Entity>(e)->getUserComponentsByType(type); 
        },
        "addChild", [](EntityReference& e, EntityReference& child) { 
            NativeReference<Entity>(e)->addChild(NativeReference<Entity>(child).ptr); 
        },
        "removeChild", [](EntityReference& e, EntityReference& child) { 
            NativeReference<Entity>(e)->removeChild(NativeReference<Entity>(child).ptr); 
        },
        "hasChild", [](EntityReference& e, EntityReference& child) { 
            return NativeReference<Entity>(e)->hasChild(NativeReference<Entity>(child).ptr); 
        },
        "find", [](EntityReference& e, std::string path) { 
            return new EntityReference(
                NativeReference<Entity>(e)->find(path)
            ); 
        },
        "getChildCount", [](EntityReference& e) { 
            return NativeReference<Entity>(e)->children.size(); 
        },
        "getChild", [](EntityReference& e, int index) { 
            return new EntityReference(
                NativeReference<Entity>(e)->getChild(index)
            ); 
        }
    );
    lua.new_usertype<ComponentReference>(
        "Component", 
        sol::base_classes, sol::bases<NativeReferenceBase>(),
        "entity", sol::property( 
            [](ComponentReference& c) { 
                return NativeReference<Component>(c)->entity; 
            }
        ),
        "scene", sol::property( 
            [](ComponentReference& c) { 
                return NativeReference<Component>(c)->entity->scene; 
            }
        ),
        "setScriptType", [](ComponentReference& c, sol::table type) { 
            NativeReference<Component>(c)->setScriptType(type); 
        },
        "setScriptInstance", [](ComponentReference& c, sol::table instance) { 
            NativeReference<Component>(c)->setScriptInstance(instance); 
        }
    );
}

// hacky way to get around the fact that 
// we can't use the scene removeEntity function in the header file
void sunaba::core::Entity::removeFromScene() {
    scene->removeEntity(this);
}

void sunaba::core::Component::onFree()  {
    if (scriptInstance == sol::nil) return;
    auto func = scriptInstance["onFree"].get<sol::function>();
    if (!func) return;
    func(scriptInstance);
    if (entity != nullptr) {
        entity->removeComponent(this);
    }
}