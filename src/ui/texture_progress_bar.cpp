#include "texture_progress_bar.h"

namespace kenai::ui {

    void TextureProgressBarProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextureProgressBarProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextureProgressBarProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TextureProgressBarProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TextureProgressBarProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TextureProgressBarProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TextureProgressBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TextureProgressBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TextureProgressBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TextureProgressBarProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }
    
    bool TextureProgressBarProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TextureProgressBarProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TextureProgressBarProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TextureProgressBarProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

    String TextureProgressBarProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TextureProgressBarProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool TextureProgressBarProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> TextureProgressBarProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void TextureProgressBarProxy::_value_changed(double p_new_value) {
        if (this->element != nullptr) {
            this->element->valueChanged(p_new_value);
        }
    }

    void bindTextureProgressBar(sol::state& lua) {
        lua.new_usertype<TextureProgressBar>("TextureProgressBar",
            sol::constructors<TextureProgressBar()>(),
            "new", sol::factories(
                []() { return new TextureProgressBar(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::CanvasItem, Control, Range>(),
            "fillMode", sol::property(&TextureProgressBar::getFillMode, &TextureProgressBar::setFillMode),
            "mouseFilter", sol::property(&TextureProgressBar::getMouseFilter, &TextureProgressBar::setMouseFilter),
            "ninePatchStretch", sol::property(&TextureProgressBar::getNinePatchStretch, &TextureProgressBar::setNinePatchStretch),
            "radialCenterOffset", sol::property(&TextureProgressBar::getRadialCenterOffset, &TextureProgressBar::setRadialCenterOffset),
            "radialFillDegrees", sol::property(&TextureProgressBar::getRadialFillDegrees, &TextureProgressBar::setRadialFillDegrees),
            "radialInitialAngle", sol::property(&TextureProgressBar::getRadialInitialAngle, &TextureProgressBar::setRadialInitialAngle),
            "sizeFlagsVertical", sol::property(&TextureProgressBar::getSizeFlagsVertical, &TextureProgressBar::setSizeFlagsVertical),
            "step", sol::property(&TextureProgressBar::getStep, &TextureProgressBar::setStep),
            "stretchMarginBottom", sol::property(&TextureProgressBar::getStretchMarginBottom, &TextureProgressBar::setStretchMarginBottom),
            "stretchMarginLeft", sol::property(&TextureProgressBar::getStretchMarginLeft, &TextureProgressBar::setStretchMarginLeft),
            "stretchMarginRight", sol::property(&TextureProgressBar::getStretchMarginRight, &TextureProgressBar::setStretchMarginRight),
            "stretchMarginTop", sol::property(&TextureProgressBar::getStretchMarginTop, &TextureProgressBar::setStretchMarginTop),
            "textureProgress", sol::property(&TextureProgressBar::getTextureProgress, &TextureProgressBar::setTextureProgress),
            "textureProgressOffset", sol::property(&TextureProgressBar::getTextureProgressOffset, &TextureProgressBar::setTextureProgressOffset),
            "textureUnder", sol::property(&TextureProgressBar::getTextureUnder, &TextureProgressBar::setTextureUnder), 
            "tintOver", sol::property(&TextureProgressBar::getTintOver, &TextureProgressBar::setTintOver),
            "tintProgress", sol::property(&TextureProgressBar::getTintProgress, &TextureProgressBar::setTintProgress),
            "tintUnder", sol::property(&TextureProgressBar::getTintUnder, &TextureProgressBar::setTintUnder),
            "getStretchMargin", &TextureProgressBar::getStretchMargin,
            "setStretchMargin", &TextureProgressBar::setStretchMargin,
            "cast", [](Element* element) {
                auto* ce = dynamic_cast<TextureProgressBar*>(element);
                if (ce != nullptr) {
                    return ce;
                }
                TextureProgressBarNode* node = Object::cast_to<TextureProgressBarNode>(element->getNode());
                return new TextureProgressBar(node);
            }
        );
    }

} // namespace kenai::ui