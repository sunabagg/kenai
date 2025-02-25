#ifndef CANVAS_ITEM_H
#define CANVAS_ITEM_H

#include <godot_cpp/classes/canvas_item.hpp>

#define CanvasItemNode godot::CanvasItem

#include "element.h"

namespace sunaba::ui {
    void bindElement(sol::state &lua);

    class CanvasItem : public Element {
    private:
        CanvasItemNode* canvas_item = nullptr; // Pointer to the CanvasItem instance
    public:
        // Constructor with Node* parameter
        CanvasItem(CanvasItemNode* p_node) : Element(p_node), canvas_item(p_node) {
            onInit();
        }
    
        // Constructor with no parameters
        CanvasItem() : Element(new CanvasItemNode()) {
            canvas_item = static_cast<CanvasItemNode*>(getNode());
            onInit();
        }

        // Getter for the CanvasItem node
        CanvasItemNode* getCanvasItem() {
            return canvas_item;
        }

        // Setter for the CanvasItem node
        void setCanvasItem(CanvasItemNode* p_node) {
            canvas_item = p_node;
            setNode(canvas_item);
        }

        int getLightMask() {
            return canvas_item->get_light_mask();
        }

        void setLightMask(int mask) {
            canvas_item->set_light_mask(mask);
        }

        Color getModulate() {
            return canvas_item->get_modulate();
        }

        void setModulate(Color color) {
            canvas_item->set_modulate(color);
        }

        Color getSelfModulate() {
            return canvas_item->get_self_modulate();
        }

        void setSelfModulate(Color color) {
            canvas_item->set_self_modulate(color);
        }

        int getTextureFilter() {
            return canvas_item->get_texture_filter();
        }

        void setTextureFilter(int filter) {
            canvas_item->set_texture_filter(static_cast<CanvasItemNode::TextureFilter>(filter));
        }

        int getTextureRepeat() {
            return canvas_item->get_texture_repeat();
        }

        void setTextureRepeat(int repeat) {
            canvas_item->set_texture_repeat(static_cast<CanvasItemNode::TextureRepeat>(repeat));
        }

        bool isTopLevel() {
            return canvas_item->is_set_as_top_level();
        }

        void setTopLevel(bool top_level) {
            canvas_item->set_as_top_level(top_level);
        }

        bool getUsesParentMaterial() {
            return canvas_item->get_use_parent_material();
        }

        void setUseParentMaterial(bool use_parent_material) {
            canvas_item->set_use_parent_material(use_parent_material);
        }

        int getVisibilityLayer() {
            return canvas_item->get_visibility_layer();
        }

        void setVisibilityLayer(int layer) {
            canvas_item->set_visibility_layer(layer);
        }

        bool isVisible() {
            return canvas_item->is_visible();
        }

        void setVisible(bool visible) {
            canvas_item->set_visible(visible);
        }

        bool ySortEnabled() {
            return canvas_item->is_y_sort_enabled();
        }

        void setYSortEnabled(bool enabled) {
            canvas_item->set_y_sort_enabled(enabled);
        }

        bool isZAsRelative() {
            return canvas_item->is_z_relative();
        }

        void setZAsRelative(bool relative) {
            canvas_item->set_z_as_relative(relative);
        }

        int getZIndex() {
            return canvas_item->get_z_index();
        }

        void setZIndex(int index) {
            canvas_item->set_z_index(index);
        }

        void drawAnimationSlice(float animationLength, float sliceBegin, float sliceEnd, float offset = 0.0f) {
            canvas_item->draw_animation_slice(animationLength, sliceBegin, sliceEnd, offset);
        }

        void drawArc(Vector2 center, float radius, float startAngle, float endAngle, int pointCount, Color color, float width = 1.0f, bool antiAliased = false) {
            canvas_item->draw_arc(center, radius, startAngle, endAngle, pointCount, color, width, antiAliased);
        }
        
        void drawCircle(Vector2 center, float radius, Color color, float width = 1.0f, bool antiAliased = false) {
            canvas_item->draw_circle(center, radius, color, width, antiAliased);
        }

        /*void drawColoredPolygon(const std::vector<Vector2>& points,  Color color, const std::vector<Vector2> uvs, ) {
            PackedVector2Array pointArray;
            for (const auto& point : points) {
                pointArray.push_back(point);
            }
            PackedVector2Array uvArray;
            for (const auto& uv : uvs) {
                uvArray.push_back(uv);
            }
            canvas_item->draw_colored_polygon(pointArray, radius, color, uvArray);
        }*/
    };
}

#endif // ELEMENT_H