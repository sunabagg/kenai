#include "button_group.h"
#include "base_button.h"

void sunaba::ui::bindButtonGroup(sol::state &lua) {
    using namespace sol;
    using namespace sunaba::ui;

    lua.new_usertype<ButtonGroup>("ButtonGroup",
        "new", sol::factories(
            []() { return new ButtonGroup(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
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

std::vector<sunaba::ui::BaseButton*> sunaba::ui::ButtonGroup::getButtons() {
    std::vector<sunaba::ui::BaseButton*> buttons;
    auto buttonList = button_group->get_buttons();
    for (int i = 0; i < buttonList.size(); ++i) {
        Object* obj = buttonList[i];
        if (obj != nullptr) {
            sunaba::ui::BaseButton* button = new sunaba::ui::BaseButton(Object::cast_to<BaseButtonNode>(obj));
            if (button->getNode() != nullptr) {
                buttons.push_back(button);
            }
        }
    }
    return buttons;
}

sunaba::ui::BaseButton* sunaba::ui::ButtonGroup::getPressedButton() {
    Object* obj = button_group->get_pressed_button();
    if (obj != nullptr) {
        return new sunaba::ui::BaseButton(Object::cast_to<BaseButtonNode>(obj));
    }
    return nullptr;
}