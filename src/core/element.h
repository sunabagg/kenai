#ifndef ELEMENT_H
#define ELEMENT_H

#include <godot_cpp/classes/node.hpp>
#include <sol/sol.hpp>

#include "base_object.h"
#include "../input/input_event.h"
#include "event.h"

#include "stl_function_wrapper.h"

using namespace sunaba::core;
using namespace godot;

namespace sunaba::desktop {
    class Viewport;
    class Window;
}

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
        void connectElementSignals() {
            std::function<Variant(std::vector<Variant>)> childEntertedTreeFunc = 
            [this](std::vector<Variant> args) {
                Node* child = Object::cast_to<Node>(args[0].operator Object*());
                Array argsArray;
                argsArray.append(new Element(child));
                if (this->childEnteredTree != nullptr) {
                    this->childEnteredTree->emit(argsArray);
                }
                return Variant();
            };
            Callable childEnteredTreeCallable = StlFunctionWrapper::create_callable_from_cpp_function(childEntertedTreeFunc);
            this->node->connect("child_entered_tree", childEnteredTreeCallable);
            std::function<Variant(std::vector<Variant>)> childExitedTreeFunc =
            [this](std::vector<Variant> args) {
                Node* child = Object::cast_to<Node>(args[0].operator Object*());
                Array argsArray;
                argsArray.append(new Element(child));
                if (this->childExitedTree != nullptr) {
                    this->childExitedTree->emit(argsArray);
                }
                return Variant();
            };
            Callable childExitedTreeCallable = StlFunctionWrapper::create_callable_from_cpp_function(childExitedTreeFunc);
            this->node->connect("child_exited_tree", childExitedTreeCallable);
            std::function<Variant(std::vector<Variant>)> childOrderChangedFunc =
            [this](std::vector<Variant> args) {
                Array argsArray;
                if (this->childOrderChanged != nullptr) {
                    this->childOrderChanged->emit(argsArray);
                }
                return Variant();
            };
            Callable childOrderChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(childOrderChangedFunc);
            this->node->connect("child_order_changed", childOrderChangedCallable);
            std::function<Variant(std::vector<Variant>)> renamedFunc =
            [this](std::vector<Variant> args) {
                Array argsArray;
                if (this->renamed != nullptr) {
                    this->renamed->emit(argsArray);
                }
                return Variant();
            };
            Callable renamedCallable = StlFunctionWrapper::create_callable_from_cpp_function(renamedFunc);
            this->node->connect("renamed", renamedCallable);
            std::function<Variant(std::vector<Variant>)> replacingByFunc =
            [this](std::vector<Variant> args) {
                Node* node = Object::cast_to<Node>(args[0].operator Object*());
                Array argsArray;
                argsArray.append(new Element(node));
                if (this->replacingBy != nullptr) {
                    this->replacingBy->emit(argsArray);
                }
                return Variant();
            };
            Callable replacingByCallable = StlFunctionWrapper::create_callable_from_cpp_function(replacingByFunc);
            this->node->connect("replacing_by", replacingByCallable);
            std::function<Variant(std::vector<Variant>)> treeEnteredFunc =
            [this](std::vector<Variant> args) {
                Array argsArray;
                if (this->treeEntered != nullptr) {
                    this->treeEntered->emit(argsArray);
                }
                return Variant();
            };
            Callable treeEnteredCallable = StlFunctionWrapper::create_callable_from_cpp_function(treeEnteredFunc);
            this->node->connect("tree_entered", treeEnteredCallable);
            std::function<Variant(std::vector<Variant>)> treeExitedFunc =
            [this](std::vector<Variant> args) {
                Array argsArray;
                if (this->treeExited != nullptr) {
                    this->treeExited->emit(argsArray);
                }
                return Variant();
            };
            Callable treeExitedCallable = StlFunctionWrapper::create_callable_from_cpp_function(treeExitedFunc);
            this->node->connect("tree_exited", treeExitedCallable);
            std::function<Variant(std::vector<Variant>)> treeExitingFunc =
            [this](std::vector<Variant> args) {
                Array argsArray;
                if (this->treeExiting != nullptr) {
                    this->treeExiting->emit(argsArray);
                }
                return Variant();
            };
            Callable treeExitingCallable = StlFunctionWrapper::create_callable_from_cpp_function(treeExitingFunc);
            this->node->connect("tree_exiting", treeExitingCallable);
        }
    public:
        sol::table scriptInstance = sol::lua_nil;

        bool isRootNode = false; // Flag to indicate if this is the root node

        Event* childEnteredTree;
        Event* childExitedTree;
        Event* childOrderChanged;
        Event* renamed;
        Event* replacingBy;
        Event* treeEntered;
        Event* treeExited;
        Event* treeExiting;

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

        Element* find(const std::string& name) {
            NodePath path = NodePath(name.c_str());
            auto node = getNode()->get_node<Node>(path);
            if (node != nullptr) {
                return new Element(node);
            }
            return nullptr;
        }

        Element* getParent() {
            if (isRootNode) {
                return nullptr; // If this is the root node, it has no parent
            }
            return new Element(getNode()->get_parent());
        }

        void addChild(Element* child) {
            if (child != nullptr) {
                if (node != nullptr) {
                    node->add_child(child->getNode());
                }
            }
        }

        void addSibling(Element* sibling) {
            auto parent = getParent();
            if (sibling != nullptr && parent != nullptr) {
                parent->addChild(sibling);
            }
        }

        void removeChild(Element* child) {
            if (node != nullptr) {
                node->remove_child(child->getNode());
            }
        }

        std::vector<Element*> getChildren() {
            auto childrenNodes = node->get_children();
            std::vector<Element*> result;
            for (int i = 0; i < childrenNodes.size(); ++i) {
                Node* childNode = Object::cast_to<Node>(childrenNodes[i].operator Object*());
                if (childNode != nullptr) {
                    Element* childElement = new Element(childNode);
                    result.push_back(childElement);
                }
            }
            return result;
        }

        virtual void onInit() {
            // Initialization logic for the element
        }

        void setNode(NodeProxy* p_node) {
            node = p_node;
            connectElementSignals();
            p_node->element = this;
            setProxyDb(node);
        }

        void setNode(Node* p_node) {
            node = p_node;
            connectElementSignals();
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
        }

        bool isNull() {
            return node == nullptr;
        }
    };
}

#endif // WIDGET_H