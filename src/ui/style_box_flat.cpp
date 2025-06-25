#include "style_box_flat.h"

void lucidware::ui::bindStyleBoxFlat(sol::state_view& lua) {
    lua.new_usertype<StyleBoxFlat>("StyleBoxFlat",
        "new", sol::factories(
            []() { return new StyleBoxFlat(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::ui::StyleBox>(),
        "antiAliasing", sol::property(&StyleBoxFlat::getAntiAliasing, &StyleBoxFlat::setAntiAliasing),
        "antiAliasingSize", sol::property(&StyleBoxFlat::getAntiAliasingSize, &StyleBoxFlat::setAntiAliasingSize),
        "bgColor", sol::property(&StyleBoxFlat::getBgColor, &StyleBoxFlat::setBgColor),
        "borderColor", sol::property(&StyleBoxFlat::getBorderColor, &StyleBoxFlat::setBorderColor),
        "borderWidthBottom", sol::property(&StyleBoxFlat::getBorderWidthBottom, &StyleBoxFlat::setBorderWidthBottom),
        "borderWidthLeft", sol::property(&StyleBoxFlat::getBorderWidthLeft, &StyleBoxFlat::setBorderWidthLeft),
        "borderWidthRight", sol::property(&StyleBoxFlat::getBorderWidthRight, &StyleBoxFlat::setBorderWidthRight),
        "borderWidthTop", sol::property(&StyleBoxFlat::getBorderWidthTop, &StyleBoxFlat::setBorderWidthTop),
        "getBorderWidth", &StyleBoxFlat::getBorderWidth,
        "getBorderWidthMin", &StyleBoxFlat::getBorderWidthMin,
        "cornerDetail", sol::property(&StyleBoxFlat::getCornerDetail, &StyleBoxFlat::setCornerDetail),
        "cornerRadiusBottomLeft", sol::property(&StyleBoxFlat::getCornerRadiusBottomLeft, &StyleBoxFlat::setCornerRadiusBottomLeft),
        "cornerRadiusBottomRight", sol::property(&StyleBoxFlat::getCornerRadiusBottomRight, &StyleBoxFlat::setCornerRadiusBottomRight),
        "cornerRadiusTopLeft", sol::property(&StyleBoxFlat::getCornerRadiusTopLeft, &StyleBoxFlat::setCornerRadiusTopLeft),
        "cornerRadiusTopRight", sol::property(&StyleBoxFlat::getCornerRadiusTopRight, &StyleBoxFlat::setCornerRadiusTopRight),
        "getCornerRadius", &StyleBoxFlat::getCornerRadius,
        "expandMarginBottom", sol::property(&StyleBoxFlat::getExpandMarginBottom, &StyleBoxFlat::setExpandMarginBottom),
        "expandMarginLeft", sol::property(&StyleBoxFlat::getExpandMarginLeft, &StyleBoxFlat::setExpandMarginLeft),
        "expandMarginRight", sol::property(&StyleBoxFlat::getExpandMarginRight, &StyleBoxFlat::setExpandMarginRight),
        "expandMarginTop", sol::property(&StyleBoxFlat::getExpandMarginTop, &StyleBoxFlat::setExpandMarginTop),
        "getExpandMargin", &StyleBoxFlat::getExpandMargin,
        "setExpandMarginAll", &StyleBoxFlat::setExpandMarginAll,
        "shadowColor", sol::property(&StyleBoxFlat::getShadowColor, &StyleBoxFlat::setShadowColor),
        "shadowSize", sol::property(&StyleBoxFlat::getShadowSize, &StyleBoxFlat::setShadowSize),
        "shadowOffset", sol::property(&StyleBoxFlat::getShadowOffset, &StyleBoxFlat::setShadowOffset),
        "skew", sol::property(&StyleBoxFlat::GetSkew, &StyleBoxFlat::SetSkew),
        "cast", [](lucidware::core::Resource* p_resource) {
            return new StyleBoxFlat(godot::Object::cast_to<GodotStyleBoxFlat>(p_resource->getResource()));
        }
    );
}