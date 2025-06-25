#include "button_group.h"
#include "base_button.h"

void lucidfx::ui::bindButtonGroup(sol::state &lua) {
    using namespace sol;
    using namespace lucidfx::ui;

    lua.new_usertype<ButtonGroup>("ButtonGroup",
        "new", sol::factories(
            []() { return new ButtonGroup(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
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
        "cast", [](lucidfx::core::Resource* p_resource) {
            return new ButtonGroup(godot::Object::cast_to<GodotButtonGroup>(p_resource->getResource()));
        }
    );
}

std::vector<lucidfx::ui::BaseButton*> lucidfx::ui::ButtonGroup::getButtons() {
    std::vector<lucidfx::ui::BaseButton*> buttons;
    auto buttonList = button_group->get_buttons();
    for (int i = 0; i < buttonList.size(); ++i) {
        Object* obj = buttonList[i];
        if (obj != nullptr) {
            lucidfx::ui::BaseButton* button = new lucidfx::ui::BaseButton(Object::cast_to<BaseButtonNode>(obj));
            if (button->getNode() != nullptr) {
                buttons.push_back(button);
            }
        }
    }
    return buttons;
}

lucidfx::ui::BaseButton* lucidfx::ui::ButtonGroup::getPressedButton() {
    Object* obj = button_group->get_pressed_button();
    if (obj != nullptr) {
        return new lucidfx::ui::BaseButton(Object::cast_to<BaseButtonNode>(obj));
    }
    return nullptr;
}