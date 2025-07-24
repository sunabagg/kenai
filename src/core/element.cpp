#include "element.h"
#include "proxy_db.h"
#include "stl_function_wrapper.h"
#include "viewport.h"
#include "../desktop/window.h"

using namespace sunaba::core;
using namespace godot;

void sunaba::core::bindElement(sol::state &lua) {
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
        "scriptInstance", sol::property(
            [](Element* e) {
                return e->scriptInstance;
            },
            [](Element* e, sol::table table) {
                e->scriptInstance = table;
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
        "getIndex", sol::factories(
            [](Element* e) {
                return e->getIndex();
            },
            [](Element* e, bool includeInternal) {
                return e->getIndex(includeInternal);
            }
        ),
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

void sunaba::core::Element::setProxyDb(Node* p_node) {
    node = p_node;
    ProxyDb::addElement(node, this);
}

void sunaba::core::NodeProxy::_enter_tree() {
    if (this->element != nullptr) {
        this->element->enterTree();
    }
}

void sunaba::core::NodeProxy::_exit_tree() {
    if (this->element != nullptr) {
        this->element->exitTree();
    }
}

void sunaba::core::NodeProxy::_ready() {
    if (this->element != nullptr) {
        this->element->ready();
    }
}

void sunaba::core::NodeProxy::_process(double delta) {
    if (this->element != nullptr) {
        this->element->process(delta);
    }
}

void sunaba::core::NodeProxy::_physics_process(double delta) {
    if (this->element != nullptr) {
        this->element->physicsProcess(delta);
    }
}

void sunaba::core::NodeProxy::_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->input(event);
    }
}

void sunaba::core::NodeProxy::_unhandled_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->unhandledInput(event);
    }
}

void sunaba::core::NodeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->unhandledKeyInput(event);
    }
}

void sunaba::core::NodeProxy::_shortcut_input(const Ref<InputEvent>& event) {
    if (this->element != nullptr) {
        this->element->shortcutInput(event);
    }
}

void sunaba::core::NodeProxy::_notification(int what) {
    if (this->element != nullptr) {
        this->element->notification(what);
    }
}

sunaba::core::Viewport* sunaba::core::Element::getViewport() {
    if (node == nullptr) {
        return nullptr;
    }
    godot::Viewport* viewport = Object::cast_to<godot::Viewport>(node->get_viewport());
    if (viewport == nullptr) {
        return nullptr;
    }
    return new Viewport(viewport);
}

sunaba::desktop::Window* sunaba::core::Element::getWindow() {
    if (node == nullptr) {
        return nullptr;
    }
    godot::Window* window = Object::cast_to<godot::Window>(node->get_window());
    if (window == nullptr) {
        return nullptr;
    }
    return new sunaba::desktop::Window(window);
}

namespace sunaba::core {
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

    Element* Element::getParent() {
        if (isRootElement) {
            return nullptr; // If this is the root node, it has no parent
        }
        auto* parentNode = getNode()->get_parent();
        Element* e = ProxyDb::getElement(parentNode);
        if (e == nullptr) {
            e = new Element(parentNode);
        }
        return e;
    }

    Element* Element::find(const std::string& name) {
        NodePath path = NodePath(name.c_str());
        auto node = getNode()->get_node<Node>(path);
        if (node != nullptr) {
            auto* element = ProxyDb::getElement(node);
            if (element != nullptr) {
                return element;
            }
            else {
                return new Element(node);
            }
        }
        return nullptr;
    }

    std::vector<Element*> Element::getChildren() {
        auto childrenNodes = node->get_children();
        std::vector<Element*> result;
        for (int i = 0; i < childrenNodes.size(); ++i) {
            Node* childNode = Object::cast_to<Node>(childrenNodes[i].operator Object*());
            if (childNode != nullptr) {
                Element* childElement = ProxyDb::getElement(childNode);
                if (childElement == nullptr) {
                    childElement = new Element(childNode);
                }
                result.push_back(childElement);
            }
        }
        return result;
    }
}
