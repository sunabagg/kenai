#include "element.h"
#include "proxy_db.h"
#include "stl_function_wrapper.h"
#include "viewport.h"
#include "../desktop/window.h"

using namespace lucidfx::core;
using namespace godot;

void lucidfx::core::bindElement(sol::state &lua) {
    lua.new_usertype<Element>(
        "Element",
        "new", sol::factories(
            []() { return new Element(); }
        ),
        sol::base_classes, sol::bases<BaseObject>(),
        sol::meta_function::garbage_collect, sol::destructor([](Element* e) {  }),
        "name", sol::property(
            [](Element* e) {
                return e->getName().c_str();
            },
            [](Element* e, const std::string& name) {
                e->setName(name);
                if (e->getNode() != nullptr)
                    e->getNode()->set_name(name.c_str());
            }
        ),
        "childEnteredTree", sol::property(
            [](Element* e) {
                return e->childEnteredTree;
            },
            [](Element* e, Event* event) {
                e->childEnteredTree = event;
            }
        ),
        "childExitedTree", sol::property(
            [](Element* e) {
                return e->childExitedTree;
            },
            [](Element* e, Event* event) {
                e->childExitedTree = event;
            }
        ),
        "childOrderChanged", sol::property(
            [](Element* e) {
                return e->childOrderChanged;
            },
            [](Element* e, Event* event) {
                e->childOrderChanged = event;
            }
        ),
        "renamed", sol::property(
            [](Element* e) {
                return e->renamed;
            },
            [](Element* e, Event* event) {
                e->renamed = event;
            }
        ),
        "replacingBy", sol::property(
            [](Element* e) {
                return e->replacingBy;
            },
            [](Element* e, Event* event) {
                e->replacingBy = event;
            }
        ),
        "treeEntered", sol::property(
            [](Element* e) {
                return e->treeEntered;
            },
            [](Element* e, Event* event) {
                e->treeEntered = event;
            }
        ),
        "treeExited", sol::property(
            [](Element* e) {
                return e->treeExited;
            },
            [](Element* e, Event* event) {
                e->treeExited = event;
            }
        ),
        "treeExiting", sol::property(
            [](Element* e) {
                return e->treeExiting;
            },
            [](Element* e, Event* event) {
                e->treeExiting = event;
            }
        ),
        "isElementType", []() {
                return true;
        },
        "find", &Element::find,
        "getParent", &Element::getParent,
        "addChild", &Element::addChild,
        "removeChild", &Element::removeChild,
        "getChildren", &Element::getChildren,
        "isNull", &Element::isNull,
        "getViewport", &Element::getViewport,
        "getWindow", &Element::getWindow,
        "delete", &Element::_delete,
        "cast", [](Element* e) {
            return new Element(Object::cast_to<Node>(e->getNode()));
        }
    );
}

void lucidfx::core::Element::setProxyDb(Node* p_node) {
    node = p_node;
    ProxyDb::addElement(node, this);
}

void lucidfx::core::NodeProxy::_enter_tree() {
    if (this->element != nullptr) {
        this->element->enterTree();
    }
}

void lucidfx::core::NodeProxy::_exit_tree() {
    if (this->element != nullptr) {
        this->element->exitTree();
    }
}

void lucidfx::core::NodeProxy::_ready() {
    if (this->element != nullptr) {
        this->element->ready();
    }
}

void lucidfx::core::NodeProxy::_process(double delta) {
    if (this->element != nullptr) {
        this->element->process(delta);
    }
}

void lucidfx::core::NodeProxy::_physics_process(double delta) {
    if (this->element != nullptr) {
        this->element->physicsProcess(delta);
    }
}

void lucidfx::core::NodeProxy::_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->input(event);
    }
}

void lucidfx::core::NodeProxy::_unhandled_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->unhandledInput(event);
    }
}

void lucidfx::core::NodeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->unhandledKeyInput(event);
    }
}

void lucidfx::core::NodeProxy::_shortcut_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->shortcutInput(event);
    }
}

lucidfx::core::Viewport* lucidfx::core::Element::getViewport() {
    if (node == nullptr) {
        return nullptr;
    }
    godot::Viewport* viewport = Object::cast_to<godot::Viewport>(node->get_viewport());
    if (viewport == nullptr) {
        return nullptr;
    }
    return new Viewport(viewport);
}

lucidfx::desktop::Window* lucidfx::core::Element::getWindow() {
    if (node == nullptr) {
        return nullptr;
    }
    godot::Window* window = Object::cast_to<godot::Window>(node->get_window());
    if (window == nullptr) {
        return nullptr;
    }
    return new lucidfx::desktop::Window(window);
}

namespace lucidfx::core {
    void NodeSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("child_entered_tree", "child"), &NodeSignalWrapper::child_entered_tree);
        ClassDB::bind_method(D_METHOD("child_exited_tree", "child"), &NodeSignalWrapper::child_exited_tree);
        ClassDB::bind_method(D_METHOD("child_order_changed"), &NodeSignalWrapper::child_order_changed);
        ClassDB::bind_method(D_METHOD("renamed"), &NodeSignalWrapper::renamed);
        ClassDB::bind_method(D_METHOD("replacing_by", "node"), &NodeSignalWrapper::replacing_by);
        ClassDB::bind_method(D_METHOD("tree_entered"), &NodeSignalWrapper::tree_entered);
        ClassDB::bind_method(D_METHOD("tree_exited"), &NodeSignalWrapper::tree_exited);
        ClassDB::bind_method(D_METHOD("tree_exiting"), &NodeSignalWrapper::tree_exiting);
    }

    void NodeSignalWrapper::child_entered_tree(Node* child) {
        if (element->childEnteredTree != nullptr) {
            Array args;
            args.append(child);
            element->childEnteredTree->emit(args);
        }
    }

    void NodeSignalWrapper::child_exited_tree(Node* child) {
        if (element->childExitedTree != nullptr) {
            Array args;
            args.append(child);
            element->childExitedTree->emit(args);
        }
    }

    void NodeSignalWrapper::child_order_changed() {
        if (element->childOrderChanged != nullptr) {
            Array args;
            element->childOrderChanged->emit(args);
        }
    }

    void NodeSignalWrapper::renamed() {
        if (element->renamed != nullptr) {
            Array args;
            element->renamed->emit(args);
        }
    }

    void NodeSignalWrapper::replacing_by(Node* node) {
        if (element->replacingBy != nullptr) {
            Array args;
            args.append(node);
            element->replacingBy->emit(args);
        }
    }

    void NodeSignalWrapper::tree_entered() {
        if (element->treeEntered != nullptr) {
            Array args;
            element->treeEntered->emit(args);
        }
    }

    void NodeSignalWrapper::tree_exited() {
        if (element->treeExited != nullptr) {
            Array args;
            element->treeExited->emit(args);
        }
    }

    void NodeSignalWrapper::tree_exiting() {
        if (element->treeExiting != nullptr) {
            Array args;
            element->treeExiting->emit(args);
        }
    }
}
