#include "canvas_item.h"
#include "proxy_db.h"

namespace kenai::core {

    void kenai::core::CanvasItemProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
    
    void kenai::core::CanvasItemProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
    
    void kenai::core::CanvasItemProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
    
    void kenai::core::CanvasItemProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
    
    void kenai::core::CanvasItemProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
    
    void kenai::core::CanvasItemProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }
    
    void kenai::core::CanvasItemProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }
    
    void kenai::core::CanvasItemProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }
    
    void kenai::core::CanvasItemProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void CanvasItemProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    void CanvasItemSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("draw"), &CanvasItemSignalWrapper::draw);
        ClassDB::bind_method(D_METHOD("hidden"), &CanvasItemSignalWrapper::hidden);
        ClassDB::bind_method(D_METHOD("item_rect_changed"), &CanvasItemSignalWrapper::item_rect_changed);
        ClassDB::bind_method(D_METHOD("visibility_changed"), &CanvasItemSignalWrapper::visibility_changed);
    }

    void CanvasItemSignalWrapper::draw() {
        if (element != nullptr) {
            element->draw->emit(godot::Array());
        }
    }

    void CanvasItemSignalWrapper::hidden() {
        if (element != nullptr) {
            element->hidden->emit(godot::Array());
        }
    }

    void CanvasItemSignalWrapper::item_rect_changed() {
        if (element != nullptr) {
            element->itemRectChanged->emit(godot::Array());
        }
    }

    void CanvasItemSignalWrapper::visibility_changed() {
        if (element != nullptr) {
            element->visibilityChanged->emit(godot::Array());
        }
    }

    void bindCanvasItem(sol::state& lua) {
        lua.new_usertype<CanvasItem>(
            "CanvasItem",
            "new", sol::factories(
                []() { return new CanvasItem(); }
            ),
            sol::base_classes,  sol::bases<BaseObject, Element>(),
            sol::meta_function::garbage_collect, sol::destructor([](CanvasItem* c) { }),
            "clipChildren", sol::property(
                &CanvasItem::getClipChildren,
                &CanvasItem::setClipChildren
            ),
            "lightMask", sol::property(
                &CanvasItem::getLightMask,
                &CanvasItem::setLightMask
            ),
            "material", sol::property(
                &CanvasItem::getMaterial,
                &CanvasItem::setMaterial
            ),
            "modulate", sol::property(
                &CanvasItem::getModulate,
                &CanvasItem::setModulate
            ),
            "selfModulate", sol::property(
                &CanvasItem::getSelfModulate,
                &CanvasItem::setSelfModulate
            ),
            "showBehindParent", sol::property(
                &CanvasItem::getShowBehindParent,
                &CanvasItem::setShowBehindParent
            ),
            "textureFilter", sol::property(
                &CanvasItem::getTextureFilter,
                &CanvasItem::setTextureFilter
            ),
            "textureRepeat", sol::property(
                &CanvasItem::getTextureRepeat,
                &CanvasItem::setTextureRepeat
            ),
            "topLevel", sol::property(
                &CanvasItem::isTopLevel,
                &CanvasItem::setTopLevel
            ),
            "useParentMaterial", sol::property(
                &CanvasItem::getUsesParentMaterial,
                &CanvasItem::setUseParentMaterial
            ),
            "visibilityLayer", sol::property(
                &CanvasItem::getVisibilityLayer,
                &CanvasItem::setVisibilityLayer
            ),
            "visible", sol::property(
                &CanvasItem::isVisible,
                &CanvasItem::setVisible
            ),
            "ySortEnabled", sol::property(
                &CanvasItem::getYSortEnabled,
                &CanvasItem::setYSortEnabled
            ),
            "zAsRelative", sol::property(
                &CanvasItem::isZAsRelative,
                &CanvasItem::setZAsRelative
            ),
            "zIndex", sol::property(
                &CanvasItem::getZIndex,
                &CanvasItem::setZIndex
            ),
            "draw", sol::property(
                [](CanvasItem* c) {
                    return c->draw;
                },
                [](CanvasItem* c, Event* event) {
                    c->draw = event;
                }
            ),
            "hidden", sol::property(
                [](CanvasItem* c) {
                    return c->hidden;
                },
                [](CanvasItem* c, Event* event) {
                    c->hidden = event;
                }
            ),
            "itemRectChanged", sol::property(
                [](CanvasItem* c) {
                    return c->itemRectChanged;
                },
                [](CanvasItem* c, Event* event) {
                    c->itemRectChanged = event;
                }
            ),
            "visibilityChanged", sol::property(
                [](CanvasItem* c) {
                    return c->visibilityChanged;
                },
                [](CanvasItem* c, Event* event) {
                    c->visibilityChanged = event;
                }
            ),
            "drawAnimationSlice", &CanvasItem::drawAnimationSlice,
            "drawArc", &CanvasItem::drawArc,
            "drawChar", &CanvasItem::drawChar,
            "drawCharOutline", &CanvasItem::drawCharOutline,
            "drawCircle", &CanvasItem::drawCircle,
            "drawColoredPolygon", &CanvasItem::drawColoredPolygon,
            "drawLine", &CanvasItem::drawLine,
            "drawDashedLine", &CanvasItem::drawDashedLine,
            "drawEndAnimation", &CanvasItem::drawEndAnimation,
            "drawLcdTextureRectRegion", &CanvasItem::drawLcdTextureRectRegion,
            "drawMsdfTextureRectRegion", &CanvasItem::drawMsdfTextureRectRegion,
            "drawMultiline", &CanvasItem::drawMultiline,
            "drawMultilineColors", &CanvasItem::drawMultilineColors,
            "drawMultilineString", &CanvasItem::drawMultilineString,
            "drawMultilineStringOutline", &CanvasItem::drawMultilineStringOutline,
            "drawPolygon", &CanvasItem::drawPolygon,
            "drawPolyline", &CanvasItem::drawPolyline,
            "drawPolylineColors", &CanvasItem::drawPolylineColors,
            "drawPrimitive", &CanvasItem::drawPrimitive,
            "drawRect", &CanvasItem::drawRect,
            "drawRect", &CanvasItem::drawRect,
            "drawSetTransformMatrix", &CanvasItem::drawSetTransformMatrix,
            "drawString", &CanvasItem::drawString,
            "drawStringOutline", &CanvasItem::drawStringOutline,
            "drawStyleBox", &CanvasItem::drawStyleBox,
            "drawTexture", &CanvasItem::drawTexture,
            "drawTextureRect", &CanvasItem::drawTextureRect,
            "drawTextureRectRegion", &CanvasItem::drawTextureRectRegion,
            "forceUpdateTransform", &CanvasItem::forceUpdateTransform,
            "getCanvasTransform", &CanvasItem::getCanvasTransform,
            "getGlobalMousePosition", &CanvasItem::getGlobalMousePosition,
            "getGlobalTransform", &CanvasItem::getGlobalTransform,
            "getGlobalTransformWithCanvas", &CanvasItem::getGlobalTransformWithCanvas,
            "getLocalMousePosition", &CanvasItem::getLocalMousePosition,
            "getScreenTransform", &CanvasItem::getScreenTransform,
            "getTransform", &CanvasItem::getTransform,
            "getViewportRect", &CanvasItem::getViewportRect,
            "getViewportTransform", &CanvasItem::getViewportTransform,
            "getVisibilityLayerBit", &CanvasItem::getVisibilityLayerBit,
            "hide", &CanvasItem::hide,
            "isLocalTransformNotificationEnabled", &CanvasItem::isLocalTransformNotificationEnabled,
            "isTransformNotificationEnabled", &CanvasItem::isTransformNotificationEnabled,
            "isVisibleInTree", &CanvasItem::isVisibleInTree,
            "makeCanvasPositionLocal", &CanvasItem::makeCanvasPositionLocal,
            "makeInputLocal", &CanvasItem::makeInputLocal,
            "moveToFront", &CanvasItem::moveToFront,
            "queueRedraw", &CanvasItem::queueRedraw,
            "setNotifyLocalTransform", &CanvasItem::setNotifyLocalTransform,
            "setNotifyTransform", &CanvasItem::setNotifyTransform,
            "show", &CanvasItem::show,
            "cast", [](Element* e) {
                auto* ci = dynamic_cast<CanvasItem*>(e);
                if (ci != nullptr) {
                    return ci;
                }
                auto* node = Object::cast_to<CanvasItemNode>(e->getNode());
                return new CanvasItem(node);
            }
        );
    }
}