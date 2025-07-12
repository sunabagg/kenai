#include "texture_button.h"

namespace kenai::ui {

    void TextureButtonProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextureButtonProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextureButtonProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TextureButtonProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TextureButtonProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TextureButtonProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TextureButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TextureButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TextureButtonProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TextureButtonProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TextureButtonProxy::_can_drop_data(const Vector2& at_position, const Variant& data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TextureButtonProxy::_drop_data(const Vector2& at_position, const Variant& data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TextureButtonProxy::_get_drag_data(const Vector2& at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TextureButtonProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->_getMinimumSize();
        }
        return Vector2();
    }

    String TextureButtonProxy::_get_tooltip(const Vector2& at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TextureButtonProxy::_gui_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool TextureButtonProxy::_has_point(const Vector2& point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> TextureButtonProxy::_structured_text_parser(const Array& args, const String& text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void TextureButtonProxy::_pressed() {
        if (this->element != nullptr) {
            this->element->pressed();
        }
    }

    void TextureButtonProxy::_toggled(bool button_pressed) {
        if (this->element != nullptr) {
            this->element->toggled(button_pressed);
        }
    }

    void bindTextureButton(sol::state& lua) {
        lua.new_usertype<TextureButton>("TextureButton",
            "new", sol::factories(
                []() { return new TextureButton(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::CanvasItem, Control, BaseButton>(),
            "flipH", sol::property(&TextureButton::getFlipH, &TextureButton::setFlipH),
            "flipV", sol::property(&TextureButton::getFlipV, &TextureButton::setFlipV),
            "ignoreTextureSize", sol::property(
                &TextureButton::getIgnoreTextureSize,
                &TextureButton::setIgnoreTextureSize
            ),
            "stretchMode", sol::property(
                &TextureButton::getStretchMode,
                &TextureButton::setStretchMode
            ),
            "textureClickMask", sol::property(
                &TextureButton::getTextureClickMask,
                &TextureButton::setTextureClickMask
            ),
            "textureDisabled", sol::property(
                &TextureButton::getTextureDisabled,
                &TextureButton::setTextureDisabled
            ),
            "textureFocused", sol::property(
                &TextureButton::getTextureFocused,
                &TextureButton::setTextureFocused
            ),
            "textureHover", sol::property(
                &TextureButton::getTextureHover,
                &TextureButton::setTextureHover
            ),
            "textureNormal", sol::property(
                &TextureButton::getTextureNormal,
                &TextureButton::setTextureNormal
            ),
            "texturePressed", sol::property(
                &TextureButton::getTexturePressed,
                &TextureButton::setTexturePressed
            ),
            "cast", [](Element* element) {
                auto* ce = dynamic_cast<TextureButton*>(element);
                if (ce != nullptr) {
                    return ce;
                }
                TextureButtonNode* node = Object::cast_to<TextureButtonNode>(element->getNode());
                return new TextureButton(node);
            }
        );
    }

} // namespace kenai::ui