#include "element.h"

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
        "find", &Element::find,
        "getParent", &Element::getParent,
        "addChild", &Element::addChild,
        "removeChild", &Element::removeChild,
        "getChildren", &Element::getChildren
    );
}

void sunaba::core::NodeProxy::_enter_tree() {
    if (element != nullptr) {
        element->enterTree();
    }
}

void sunaba::core::NodeProxy::_exit_tree() {
    if (element != nullptr) {
        element->exitTree();
    }
}

void sunaba::core::NodeProxy::_ready() {
    if (element != nullptr) {
        element->ready();
    }
}

void sunaba::core::NodeProxy::_process(double delta) {
    if (element != nullptr) {
        element->process(delta);
    }
}

void sunaba::core::NodeProxy::_physics_process(double delta) {
    if (element != nullptr) {
        element->physicsProcess(delta);
    }
}

void sunaba::core::NodeProxy::_input(const Ref<InputEvent>& event) {
    if (element != nullptr) {
        element->input(event);
    }
}

void sunaba::core::NodeProxy::_unhandled_input(const Ref<InputEvent>& event) {
    if (element != nullptr) {
        element->unhandledInput(event);
    }
}

void sunaba::core::NodeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
    if (element != nullptr) {
        element->unhandledKeyInput(event);
    }
}

void sunaba::core::NodeProxy::_shortcut_input(const Ref<InputEvent>& event) {
    if (element != nullptr) {
        element->shortcutInput(event);
    }
}