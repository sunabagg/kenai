#include "button_group.h"

void sunaba::ui::bindButtonGroup(sol::state &lua) {
    using namespace sol;
    using namespace sunaba::ui;

    lua.new_usertype<ButtonGroup>("ButtonGroup",
        sol::constructors<ButtonGroup()>(),
        sol::base_classes, sol::bases<sunaba::core::Resource>(),
        "allowUnpress", sol::property(
            &ButtonGroup::isAllowUnpress,
            &ButtonGroup::setAllowUnpress
        ),
        "pressed", sol::property(
            [](ButtonGroup* bg) { return bg->pressed; },
            [](ButtonGroup* bg, Event* e) { bg->pressed = e; }
        ),
        "getButtons", &ButtonGroup::getButtons,
        "getPressedButton", &ButtonGroup::getPressedButton,
        "cast", [](sunaba::core::Resource* p_resource) {
            return new ButtonGroup(godot::Object::cast_to<GodotButtonGroup>(p_resource->getResource()));
        }
    );
}