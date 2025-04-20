#ifndef ELEMENT_H
#define ELEMENT_H

#include <godot_cpp/classes/node.hpp>
#include <sol/sol.hpp>

#include "base_object.h"
#include "../input/input_event.h"


using namespace sunaba::core;
using namespace godot;

namespace sunaba::core {
    void bindElement(sol::state &lua);

    class Element; // Forward declaration

    class NodeProxy : public Node {
    public:
        Element* element = nullptr;

        void _enter_tree() override;
        void _exit_tree() override;
        void _ready() override ;
        void _process(double delta) override;
        void _physics_process(double delta) override;
        void _input(const Ref<InputEvent>& event) override;
        void _unhandled_input(const Ref<InputEvent>& event) override;
        void _unhandled_key_input(const Ref<InputEvent>& event) override;
        void _shortcut_input(const Ref<InputEvent>& event) override;
    };
    
    class Element : public BaseObject {    
    private:
        Node* node = nullptr; // Pointer to the Node instance

        std::vector<Element*> children; // List of child elements
        Element* parent = nullptr; // Pointer to the parent element
        
    protected:
        void setParent(Element* p_parent) {
            parent = p_parent;
            if (node != nullptr && p_parent != nullptr && p_parent->getNode() != nullptr) {
                // Add this node as a child of the parent node
                node->add_child(p_parent->getNode());
            }
        }
    public:
        sol::table scriptInstance = sol::lua_nil;

        Element() {
            setNode(memnew(NodeProxy));
            node->set_name("Element");
            onInit();
        }

        // Protected constructor to prevent direct instantiation
        Element(Node* p_node) {
            setNode(p_node);
            onInit();
        }

        void setProxyDb(Node* p_node);

        void enterTree() {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["enterTree"].get<sol::function>();
                if (func) {
                    func(scriptInstance);
                }
            }
        }

        void exitTree() {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["exitTree"].get<sol::function>();
                if (func) {
                    func(scriptInstance);
                }
            }
        }

        void ready() {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["ready"].get<sol::function>();
                if (func) {
                    func(scriptInstance);
                }
            }
        }

        void process(double delta) {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["process"].get<sol::function>();
                if (func) {
                    sol::object deltaObj = sol::make_object(scriptInstance.lua_state(), delta);
                    func(scriptInstance, deltaObj);
                }
            }
        }

        void physicsProcess(double delta) {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["physicsProcess"].get<sol::function>();
                if (func) {
                    sol::object deltaObj = sol::make_object(scriptInstance.lua_state(), delta);
                    func(scriptInstance, deltaObj);
                }
            }
        }

        void input(const Ref<InputEvent>& event) {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["input"].get<sol::function>();
                if (func) {
                    sunaba::input::InputEvent* eventObj = new sunaba::input::InputEvent(event.ptr());
                    func(scriptInstance, eventObj);
                }
            }
        }

        void unhandledInput(const Ref<InputEvent>& event) {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["unhandledInput"].get<sol::function>();
                if (func) {
                    sunaba::input::InputEvent* eventObj = new sunaba::input::InputEvent(event.ptr());
                    func(scriptInstance, eventObj);
                }
            }
        }

        void unhandledKeyInput(const Ref<InputEvent>& event) {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["unhandledKeyInput"].get<sol::function>();
                if (func) {
                    sunaba::input::InputEvent* eventObj = new sunaba::input::InputEvent(event.ptr());
                    func(scriptInstance, eventObj);
                }
            }
        }

        void shortcutInput(const Ref<InputEvent>& event) {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["shortcutInput"].get<sol::function>();
                if (func) {
                    sunaba::input::InputEvent* eventObj = new sunaba::input::InputEvent(event.ptr());
                    func(scriptInstance, eventObj);
                }
            }
        }

        Element* findE(PackedStringArray & p_array, int p_index) {
            if (p_index >= 0 && p_index < p_array.size()) {
                String name = p_array[p_index];
                for (Element* child : children) {
                    if (child != nullptr) {
                        if (child->getName().c_str() == name) {
                            return child;
                        } else {
                            Element* found = child->findE(p_array, p_index + 1);
                            if (found != nullptr) {
                                return found;
                            }
                        }
                    }
                    
                }
            }
            return nullptr;
        }
        
        Element* find(const std::string& name) {
            String name_str = String(name.c_str());
            PackedStringArray name_array = name_str.split("/");
            return findE(name_array, 0);
        }

        template<typename T>
        T* findT(const std::string& name) {
            Element* found = find(name);
            if (found != nullptr) {
                return static_cast<T*>(found);
            }
            return nullptr;
        }

        Element* getParent() {
            return parent;
        }

        void addChild(Element* child) {
            if (child != nullptr) {
                children.push_back(child);
                child->setParent(this);
                if (node != nullptr) {
                    node->add_child(child->getNode());
                }
            }
        }

        void addSibling(Element* sibling) {
            if (sibling != nullptr && parent != nullptr) {
                parent->addChild(sibling);
            }
        }

        void removeChild(Element* child) {
            auto it = std::find(children.begin(), children.end(), child);
            if (it != children.end()) {
                children.erase(it);
                child->setParent(nullptr);
                if (node != nullptr) {
                    node->remove_child(child->getNode());
                }
            }
        }

        std::vector<Element*> getChildren() {
            std::vector<Element*> result;
            for (Element* child : children) {
                if (child != nullptr) {
                    result.push_back(child);
                }
            }
            return result;
        }

        virtual void onInit() {
            // Initialization logic for the element
        }

        void setNode(NodeProxy* p_node) {
            node = p_node;
            p_node->element = this;
            setProxyDb(node);
        }

        void setNode(Node* p_node) {
            node = p_node;
            setProxyDb(node);
        }

        Node* getNode() const {
            return node;
        }

        std::string getName() {
            return String(node->get_name()).utf8().get_data();
        }

        void setName(const std::string& name) {
            node->set_name(name.c_str());
        }

        void onFree() override {
            // Freeing logic for the element
            if (node != nullptr) {
                node->queue_free();
                node = nullptr;
            }
            if (parent != nullptr) {
                parent->removeChild(this);
                parent = nullptr;
            }
            for (Element* child : children) {
                if (child != nullptr) {
                    child->onFree();
                }
            }
            children.clear();
        }

        bool isNull() {
            return node == nullptr;
        }
    };
}

#endif // WIDGET_H