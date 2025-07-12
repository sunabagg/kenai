#include "style_box.h"

void kenai::ui::bindStyleBox(sol::state &lua) {
    using namespace sol;
    using namespace kenai::ui;

    lua.new_usertype<StyleBox>("StyleBox",
        sol::constructors<StyleBox()>(),
        "new", sol::factories(
            []() { return new StyleBox(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
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
        "cast", [](kenai::core::Resource* p_resource) {
            return new StyleBox(godot::Object::cast_to<GodotStyleBox>(p_resource->getResource()));
        }
    );
}