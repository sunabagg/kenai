#include "label_settings.h"

void lucidware::core::bindLabelSettings(sol::state &lua) {
    lua.new_usertype<LabelSettings>("LabelSettings",
        "new", sol::factories(
            []() { return new LabelSettings(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "font", sol::property(&LabelSettings::getFont, &LabelSettings::setFont),
        "fontColor", sol::property(&LabelSettings::getFontColor, &LabelSettings::setFontColor),
        "fontSize", sol::property(&LabelSettings::getFontSize, &LabelSettings::setFontSize),
        "lineSpacing", sol::property(&LabelSettings::getLineSpacing, &LabelSettings::setLineSpacing),
        "outlineColor", sol::property(&LabelSettings::getOutlineColor, &LabelSettings::setOutlineColor),
        "outlineSize", sol::property(&LabelSettings::getOutlineSize, &LabelSettings::setOutlineSize),
        "shadowColor", sol::property(&LabelSettings::getShadowColor, &LabelSettings::setShadowColor),
        "shadowOffset", sol::property(&LabelSettings::getShadowOffset, &LabelSettings::setShadowOffset),
        "shadowSize", sol::property(&LabelSettings::getShadowSize, &LabelSettings::setShadowSize)
    );
}