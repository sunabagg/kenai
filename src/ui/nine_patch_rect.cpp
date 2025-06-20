#include "nine_patch_rect.h"

namespace sunaba::ui {
    void NinePatchRectProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void NinePatchRectProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void NinePatchRectProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void NinePatchRectProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void NinePatchRectProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void NinePatchRectProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void NinePatchRectProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void NinePatchRectProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void NinePatchRectProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void NinePatchRectProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool NinePatchRectProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void NinePatchRectProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant NinePatchRectProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 NinePatchRectProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String NinePatchRectProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void NinePatchRectProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool NinePatchRectProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> NinePatchRectProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindNinePatchRect(sol::state &lua) {
        lua.new_usertype<NinePatchRect>("NinePatchRect",
            "new", sol::factories(
                []() { return new NinePatchRect(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "axisStretchHorizontal", sol::property(
                &NinePatchRect::getAxisStretchHorizontal,
                &NinePatchRect::setAxisStretchHorizontal
            ),
            "axisStretchVertical", sol::property(
                &NinePatchRect::getAxisStretchVertical,
                &NinePatchRect::setAxisStretchVertical
            ),
            "drawCenter", sol::property(
                &NinePatchRect::isDrawCenterEnabled,
                &NinePatchRect::setDrawCenter
            ),
            "mouseFilter", sol::property(
                &NinePatchRect::getMouseFilter,
                &NinePatchRect::setMouseFilter
            ),
            "patchMarginBottom", sol::property(
                &NinePatchRect::getPatchMarginBottom,
                &NinePatchRect::setPatchMarginBottom
            ),
            "patchMarginLeft", sol::property(
                &NinePatchRect::getPatchMarginLeft,
                &NinePatchRect::setPatchMarginLeft
            ),
            "patchMarginRight", sol::property(
                &NinePatchRect::getPatchMarginRight,
                &NinePatchRect::setPatchMarginRight
            ),
            "patchMarginTop", sol::property(
                &NinePatchRect::getPatchMarginTop,
                &NinePatchRect::setPatchMarginTop
            ),
            "regionRect", sol::property(
                &NinePatchRect::getRegionRect,
                &NinePatchRect::setRegionRect
            ),
            "texture", sol::property(
                &NinePatchRect::getTexture,
                &NinePatchRect::setTexture
            ),
            "textureChanged", sol::property(
                &NinePatchRect::getTextureChangedEvent,
                &NinePatchRect::setTextureChangedEvent
            ),
            "getPatchMargin", &NinePatchRect::getPatchMargin,
            "setPatchMargin", &NinePatchRect::setPatchMargin,
            "cast", [](Element* e) {
                NinePatchRectNode* ninePatchRect = Object::cast_to<NinePatchRectNode>(e->getNode());
                return new NinePatchRect(ninePatchRect);
            }
        );
    }
}