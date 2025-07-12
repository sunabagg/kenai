#include "style_box_empty.h"

void kenai::ui::bindStyleBoxEmpty(sol::state &lua) {
    using namespace sol;
    using namespace kenai::ui;

    lua.new_usertype<StyleBoxEmpty>("StyleBoxEmpty",
        "new", sol::factories(
            []() { return new StyleBoxEmpty(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::ui::StyleBox>(),
        "cast", [](kenai::core::Resource* p_resource) {
            return new StyleBoxEmpty(godot::Object::cast_to<GodotStyleBoxEmpty>(p_resource->getResource()));
        }
    );
}