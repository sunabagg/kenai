#include "link_button.h"

namespace sunaba::ui {
    void LinkButtonProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void LinkButtonProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void LinkButtonProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void LinkButtonProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void LinkButtonProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void LinkButtonProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void LinkButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void LinkButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void LinkButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void LinkButtonProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool LinkButtonProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void LinkButtonProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant LinkButtonProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 LinkButtonProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String LinkButtonProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void LinkButtonProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool LinkButtonProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> LinkButtonProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void LinkButtonProxy::_pressed() {
        if (element != nullptr) {
            element->pressed();
        }
    }

    void LinkButtonProxy::_toggled(bool p_toggled_on) {
        if (element != nullptr) {
            element->toggled(p_toggled_on);
        }
    }

    void bindLinkButton(sol::state &lua) {
        using namespace sol;
        using namespace sunaba::ui;

        lua.new_usertype<LinkButton>("LinkButton",
            "new", sol::factories(
                []() { return new LinkButton(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, sunaba::ui::Control, sunaba::ui::BaseButton>(),
            "focusMode", sol::property(
                &LinkButton::getFocusMode,
                &LinkButton::setFocusMode
            ),
            "language", sol::property(
                &LinkButton::getLanguage,
                &LinkButton::setLanguage
            ),
            "mouseDefaultCursorShape", sol::property(
                &LinkButton::getMouseDefaultCursorShape,
                &LinkButton::setMouseDefaultCursorShape
            ),
            "structuredTextBidiOverride", sol::property(
                &LinkButton::getStructuredTextBidiOverride,
                &LinkButton::setStructuredTextBidiOverride
            ),
            "structuredTextBidiOverrideOptions", sol::property(
                &LinkButton::getStructuredTextBidiOverrideOptions,
                &LinkButton::setStructuredTextBidiOverrideOptions
            ),
            "text", sol::property(
                &LinkButton::getText,
                &LinkButton::setText
            ),
            "textDirection", sol::property(
                &LinkButton::getTextDirection,
                &LinkButton::setTextDirection
            ),
            "underline", sol::property(
                &LinkButton::getUnderline,
                &LinkButton::setUnderline
            ),
            "uri", sol::property(
                &LinkButton::getUri,
                &LinkButton::setUri
            ),
            "cast", [](Element* e) {
                LinkButtonNode* control = Object::cast_to<LinkButtonNode>(e->getNode());
                return new LinkButton(control);
            }
        );
    }
}