#include "style_box_line.h"

void lucidfx::ui::bindStyleBoxLine(sol::state_view& lua) {
    lua.new_usertype<StyleBoxLine>("StyleBoxLine",
        "new", sol::factories(
            []() { return new StyleBoxLine(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::ui::StyleBox>(),
        "color", sol::property(&StyleBoxLine::getColor, &StyleBoxLine::setColor),
        "growBegin", sol::property(&StyleBoxLine::getGrowBegin, &StyleBoxLine::setGrowBegin),
        "growEnd", sol::property(&StyleBoxLine::getGrowEnd, &StyleBoxLine::setGrowEnd),
        "thickness", sol::property(&StyleBoxLine::getThickness, &StyleBoxLine::setThickness),
        "vertical", sol::property(&StyleBoxLine::isVertical, &StyleBoxLine::setVertical),
        "cast", [](lucidfx::core::Resource* p_resource) {
            return new StyleBoxLine(godot::Object::cast_to<GodotStyleBoxLine>(p_resource->getResource()));
        }
    );
}