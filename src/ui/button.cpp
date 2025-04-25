#include "button.h"

namespace sunaba::ui {
    void bindButton(sol::state &lua) {
        using namespace sol;
        using namespace sunaba::ui;

        lua.new_usertype<Button>("Button",
            sol::constructors<Button()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, sunaba::ui::Control, sunaba::ui::BaseButton>(),
            "alignment", sol::property(
                &Button::getAlignment,
                &Button::setAlignment
            ),
            "autowrapMode", sol::property(
                &Button::getAutowrapMode,
                &Button::setAutowrapMode
            ),
            "clipText", sol::property(
                &Button::getClipText,
                &Button::setClipText
            ),
            "expandIcon", sol::property(
                &Button::isExpandIcon,
                &Button::setExpandIcon
            ),
            "flat", sol::property(
                &Button::isFlat,
                &Button::setFlat
            ),
            "icon", sol::property(
                &Button::getIcon,
                &Button::setIcon
            ),
            "iconAlignment", sol::property(
                &Button::getIconAlignment,
                &Button::setIconAlignment
            ),
            "language", sol::property(
                &Button::getLanguage,
                &Button::setLanguage
            ),
            "text", sol::property(
                &Button::getText,
                &Button::setText
            ),
            "textDirection", sol::property(
                &Button::getTextDirection,
                &Button::setTextDirection
            ),
            "textOverrunBehavior", sol::property(
                &Button::getTextOverrunBehavior,
                &Button::setTextOverrunBehavior
            ),
            "verticalIconAlignment", sol::property(
                &Button::getVerticalIconAlignment,
                &Button::setVerticalIconAlignment
            ),
            "cast", [](sunaba::core::Resource* p_resource) {
                return new Button(godot::Object::cast_to<ButtonNode>(p_resource->getResource()));
            }
        );
    }
}