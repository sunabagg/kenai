#include "style_box.h"

void lucidfx::ui::bindStyleBox(sol::state &lua) {
    using namespace sol;
    using namespace lucidfx::ui;

    lua.new_usertype<StyleBox>("StyleBox",
        sol::constructors<StyleBox()>(),
        "new", sol::factories(
            []() { return new StyleBox(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "contentMarginTop", sol::property(&StyleBox::getContentMarginTop, &StyleBox::setContentMarginTop),
        "contentMarginBottom", sol::property(&StyleBox::getContentMarginBottom, &StyleBox::setContentMarginBottom),
        "contentMarginLeft", sol::property(&StyleBox::getContentMarginLeft, &StyleBox::setContentMarginLeft),
        "contentMarginRight", sol::property(&StyleBox::getContentMarginRight, &StyleBox::setContentMarginRight),
        "getContentMargin", &StyleBox::getContentMargin,
        "getMargin", &StyleBox::getMargin,
        "getMinimumSize", &StyleBox::getMinimumSize,
        "getOffset", &StyleBox::getOffset,
        "setContentMargin", &StyleBox::setContentMargin,
        "setContentMarginAll", &StyleBox::setContentMarginAll,
        "cast", [](lucidfx::core::Resource* p_resource) {
            return new StyleBox(godot::Object::cast_to<GodotStyleBox>(p_resource->getResource()));
        }
    );
}