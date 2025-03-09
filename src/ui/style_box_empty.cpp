#include "style_box_empty.h"

void sunaba::ui::bindStyleBoxEmpty(sol::state &lua) {
    using namespace sol;
    using namespace sunaba::ui;

    lua.new_usertype<StyleBoxEmpty>("StyleBoxEmpty",
        sol::constructors<StyleBoxEmpty()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::ui::StyleBox>(),
        "cast", [](Resource* p_resource) {
            return new StyleBoxEmpty(godot::Object::cast_to<GodotStyleBoxEmpty>(p_resource->getResource()));
        }
    );
}