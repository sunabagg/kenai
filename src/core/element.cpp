#include "element.h"

using namespace sunaba::core;
using namespace godot;

void sunaba::ui::bindElement(sol::state &lua) {
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