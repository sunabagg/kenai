#include "element.h"
#include "proxy_db.h"

using namespace sunaba::core;
using namespace godot;

void sunaba::core::bindElement(sol::state &lua) {
    lua.new_usertype<Element>(
        "Element",
        sol::constructors<Element()>(), // Constructor with Node* parameter
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
        "replacingBy", sol::readonly_property(
            [](Element* e) {
                return e->replacingBy;
            }
        ),
        "treeEntered", sol::readonly_property(
            [](Element* e) {
                return e->treeEntered;
            }
        ),
        "treeExited", &Element::treeExited,
        "treeExiting", &Element::treeExiting,
        "find", &Element::find,
        "getParent", &Element::getParent,
        "addChild", &Element::addChild,
        "removeChild", &Element::removeChild,
        "getChildren", &Element::getChildren,
        "isNull", &Element::isNull,
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

void sunaba::core::NodeProxy::onChildEnteredTree(Node* child) {
    if (this->element != nullptr) {
        Array args;
        args.append(new Element(child));
        this->element->childEnteredTree->emit(args);
    }
}

void sunaba::core::NodeProxy::onChildExitedTree(Node* child) {
    if (this->element != nullptr) {
        Array args;
        args.append(new Element(child));
        this->element->childExitedTree->emit(args);
    }
}

void sunaba::core::NodeProxy::onChildOrderChanged() {
    if (this->element != nullptr) {
        this->element->childOrderChanged->emit(Array());
    }
}

void sunaba::core::NodeProxy::onRenamed() {
    if (this->element != nullptr) {
        this->element->renamed->emit(Array());
    }
}

void sunaba::core::NodeProxy::onReplacingBy(Node* node) {
    if (this->element != nullptr) {
        Array args;
        args.append(new Element(node));
        this->element->renamed->emit(args);
    }
}

void sunaba::core::NodeProxy::onTreeEntered() {
    if (this->element != nullptr) {
        this->element->treeEntered->emit(Array());
    }
}

void sunaba::core::NodeProxy::onTreeExited() {
    if (this->element != nullptr) {
        this->element->treeExited->emit(Array());
    }
}

void sunaba::core::NodeProxy::onTreeExiting() {
    if (this->element != nullptr) {
        this->element->treeExiting->emit(Array());
    }
}

void sunaba::core::NodeProxy::_bind_methods() {
    sunaba::core::NodeProxy::bindElementMethods();
}

void sunaba::core::NodeProxy::bindElementMethods() {
    ClassDB::bind_method(D_METHOD("onChildEnteredTree"), &NodeProxy::onChildEnteredTree);
    ClassDB::bind_method(D_METHOD("onChildExitedTree"), &NodeProxy::onChildExitedTree);
    ClassDB::bind_method(D_METHOD("onChildOrderChanged"), &NodeProxy::onChildOrderChanged);
    ClassDB::bind_method(D_METHOD("onRenamed"), &NodeProxy::onRenamed);
    ClassDB::bind_method(D_METHOD("onReplacingBy"), &NodeProxy::onReplacingBy);
    ClassDB::bind_method(D_METHOD("onTreeEntered"), &NodeProxy::onTreeEntered);
    ClassDB::bind_method(D_METHOD("onTreeExited"), &NodeProxy::onTreeExited);
    ClassDB::bind_method(D_METHOD("onTreeExiting"), &NodeProxy::onTreeExiting);
}