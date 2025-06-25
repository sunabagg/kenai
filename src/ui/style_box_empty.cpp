#include "style_box_empty.h"

void lucidware::ui::bindStyleBoxEmpty(sol::state &lua) {
    using namespace sol;
    using namespace lucidware::ui;

    lua.new_usertype<StyleBoxEmpty>("StyleBoxEmpty",
        "new", sol::factories(
            []() { return new StyleBoxEmpty(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::ui::StyleBox>(),
        "cast", [](lucidware::core::Resource* p_resource) {
            return new StyleBoxEmpty(godot::Object::cast_to<GodotStyleBoxEmpty>(p_resource->getResource()));
        }
    );
}