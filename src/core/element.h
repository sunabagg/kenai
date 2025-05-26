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

    class NodeSignalWrapper : public Object {
        GDCLASS(NodeSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            Element* element = nullptr;

            NodeSignalWrapper() = default;
            ~NodeSignalWrapper() = default;

            void child_entered_tree(Node* child);

            void child_exited_tree(Node* child);

            void child_order_changed();

            void renamed();
            
            void replacing_by(Node* node);

            void tree_entered();
    };

    class Viewport;

    class Element : public BaseObject {
    private:
        Node* node = nullptr; // Pointer to the Node instance

        NodeSignalWrapper *nodeSignalWrapper = nullptr;
        void connectElementSignals() {

            if (this->nodeSignalWrapper == nullptr) {
                this->nodeSignalWrapper = memnew(NodeSignalWrapper);
                this->nodeSignalWrapper->element = this;
            }
            this->node->connect("child_entered_tree", Callable(this->nodeSignalWrapper, "child_entered_tree"));
            this->node->connect("child_exited_tree", Callable(this->nodeSignalWrapper, "child_exited_tree"));
            this->node->connect("child_order_changed", Callable(this->nodeSignalWrapper, "child_order_changed"));
            this->node->connect("renamed", Callable(this->nodeSignalWrapper, "renamed"));
            this->node->connect("replacing_by", Callable(this->nodeSignalWrapper, "replacing_by"));
            
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

        void _delete() {
            if (isRootNode) {
                // If this is the root node, we should not delete it
                return;
            }
            // Freeing logic for the element
            if (node != nullptr) {
                node->queue_free();
                node = nullptr;
            }
        }

        void onFree() override {
            
        }

        bool isNull() {
            return node == nullptr;
        }

        Viewport* getViewport();

        sunaba::desktop::Window* getWindow();
    };
}

#endif // WIDGET_H