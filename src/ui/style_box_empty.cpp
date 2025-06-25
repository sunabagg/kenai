#include "style_box_empty.h"

void lucidfx::ui::bindStyleBoxEmpty(sol::state &lua) {
    using namespace sol;
    using namespace lucidfx::ui;

    lua.new_usertype<StyleBoxEmpty>("StyleBoxEmpty",
        "new", sol::factories(
            []() { return new StyleBoxEmpty(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::ui::StyleBox>(),
        "cast", [](lucidfx::core::Resource* p_resource) {
            return new StyleBoxEmpty(godot::Object::cast_to<GodotStyleBoxEmpty>(p_resource->getResource()));
        }
    );
}