#include "canvas_item.h"

namespace sunaba::core {
    void CanvasItemProxy::_draw() {
        if (canvas_item_element != nullptr) {
            canvas_item_element->draw();
        }
    }

    void bindCanvasItem(sol::state& lua) {
        lua.new_usertype<CanvasItem>(
            "CanvasItem",
            sol::constructors<CanvasItem()>(),
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
                CanvasItemNode* canvas_item = Object::cast_to<CanvasItemNode>(e->getNode());
                if (canvas_item == nullptr) {
                    return new CanvasItem(canvas_item);
                }
                return static_cast<CanvasItem*>(nullptr);
            }
        );
    }
}