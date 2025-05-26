#ifndef CANVAS_ITEM_H
#define CANVAS_ITEM_H

#include <godot_cpp/classes/canvas_item.hpp>

#define CanvasItemNode godot::CanvasItem

#include "element.h"
#include "material.h"
#include "font.h"
#include "texture2d.h"
#include "../ui/style_box.h"
#include "../input/input_event.h"
#include "stl_function_wrapper.h"

namespace sunaba::core {
    void bindCanvasItem(sol::state &lua);

    class CanvasItem;

    class CanvasItemProxy : public CanvasItemNode {
        public:
            sunaba::core::CanvasItem* element = nullptr;  
    
            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;
    };

    class CanvasItemSignalWrapper : public Object {
        GDCLASS(CanvasItemSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::core::CanvasItem* element = nullptr;

            CanvasItemSignalWrapper() = default;
            ~CanvasItemSignalWrapper() = default;

            void draw();
            void hidden();
            void item_rect_changed();
            void visibility_changed();
    };

    class CanvasItem : public Element {
    private:
        CanvasItemNode* canvas_item = nullptr; // Pointer to the CanvasItem instance

        CanvasItemSignalWrapper* canvas_item_signal_wrapper = nullptr;
        void connectCanvasItemSignals() {
            if (this->canvas_item_signal_wrapper == nullptr) {
                this->canvas_item_signal_wrapper = memnew(CanvasItemSignalWrapper);
                this->canvas_item_signal_wrapper->element = this;
            }
            this->canvas_item->connect("draw", Callable(this->canvas_item_signal_wrapper, "draw"));
            this->canvas_item->connect("hidden", Callable(this->canvas_item_signal_wrapper, "hidden"));
            this->canvas_item->connect("item_rect_changed", Callable(this->canvas_item_signal_wrapper, "item_rect_changed"));
            this->canvas_item->connect("visibility_changed", Callable(this->canvas_item_signal_wrapper, "visibility_changed"));
        }
    public:
        // Constructor with Node* parameter
        CanvasItem(CanvasItemNode* p_node) {
            setCanvasItem(p_node);
        }

        CanvasItem(CanvasItemProxy* p_node) {
            setCanvasItem(p_node);
        }

        void onFree() override {
            if (canvas_item_signal_wrapper) {
                memdelete(canvas_item_signal_wrapper);
                canvas_item_signal_wrapper = nullptr;
            }
            Element::onFree();
        }
    
        // Constructor with no parameters
        CanvasItem() {
            CanvasItemProxy* cip = memnew(CanvasItemProxy);
            //setCanvasItem(cip);
            onInit();
        }

        // Getter for the CanvasItem node
        CanvasItemNode* getCanvasItem() {
            return canvas_item;
        }

        // Setter for the CanvasItem node
        void setCanvasItem(CanvasItemNode* p_node) {
            canvas_item = p_node;
            connectCanvasItemSignals();
            setNode(canvas_item);
        }

        void setCanvasItem(CanvasItemProxy* p_node) {
            canvas_item = p_node;
            p_node->element = this;
            connectCanvasItemSignals();
            setNode(Object::cast_to<Node>(canvas_item));
        }

        int getClipChildren() {
            return canvas_item->get_clip_children_mode();
        }

        void setClipChildren(int enabled) {
            canvas_item->set_clip_children_mode(static_cast<CanvasItemNode::ClipChildrenMode>(enabled));
        }

        int getLightMask() {
            return canvas_item->get_light_mask();
        }

        void setLightMask(int mask) {
            canvas_item->set_light_mask(mask);
        }

        Material* getMaterial() {
            return new Material(canvas_item->get_material().ptr());
            //return new Material(nullptr); // Placeholder, implement this method to return the correct Material instance
        }

        void setMaterial(Material* material) {
            canvas_item->set_material(Ref<godot::Material>(material->getMaterial()));
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

        bool getShowBehindParent() {
            return canvas_item->is_draw_behind_parent_enabled();
        }

        void setShowBehindParent(bool show) {
            canvas_item->set_draw_behind_parent(show);
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

        bool getYSortEnabled() {
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

        Event* draw;
        Event* hidden;
        Event* itemRectChanged;
        Event* visibilityChanged;

        void drawAnimationSlice(float animationLength, float sliceBegin, float sliceEnd, float offset = 0.0f) {
            canvas_item->draw_animation_slice(animationLength, sliceBegin, sliceEnd, offset);
        }

        void drawArc(Vector2 center, float radius, float startAngle, float endAngle, int pointCount, Color color, float width = 1.0f, bool antiAliased = false) {
            canvas_item->draw_arc(center, radius, startAngle, endAngle, pointCount, color, width, antiAliased);
        }

        void drawChar(Font* font, Vector2 pos, std::string chr, int fontSize = 16, Color modulate = Color(1, 1, 1, 1)) {
            canvas_item->draw_char(font->getFont(), pos, chr.c_str(), fontSize, modulate);
        }

        void drawCharOutline(Font* font, Vector2 pos, std::string chr, int fontSize = 16, int size = -1, Color modulate = Color(1, 1, 1, 1)) {
            canvas_item->draw_char_outline(font->getFont(), pos, chr.c_str(), fontSize, size, modulate);
        }
        
        void drawCircle(Vector2 center, float radius, Color color, float width = 1.0f, bool antiAliased = false) {
            canvas_item->draw_circle(center, radius, color, width, antiAliased);
        }

        void drawColoredPolygon(std::vector<Vector2> points, Color color, std::vector<Vector2> uvs = {}, Texture2D* texture = nullptr) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            PackedVector2Array uvsArray;
            if (texture != nullptr) {
                for (const Vector2& uv : uvs) {
                    uvsArray.push_back(uv);
                }
            }
            Ref<GodotTexture2D> textureRef;
            if (texture != nullptr) {
                textureRef = texture->getTexture();
            }
            canvas_item->draw_colored_polygon(pointsArray, color, uvsArray, textureRef);
        }

        void drawDashedLine(Vector2 from, Vector2 to, Color color, float width = -1.0, float dash = 2.0, bool aligned = true, bool antialiased = false) {
            canvas_item->draw_dashed_line(from, to, color, width, dash, aligned, antialiased);
        }

        void drawEndAnimation() {
            canvas_item->draw_end_animation();
        }

        void drawLcdTextureRectRegion(Texture2D* texture, Rect2 rect, Rect2 srcRect, Color modulate = Color(1, 1, 1, 1)) {
            Ref<GodotTexture2D> textureRef = Ref<GodotTexture2D>(texture->getTexture());
            canvas_item->draw_lcd_texture_rect_region(textureRef, rect, srcRect, modulate);
        }

        void drawLine(Vector2 from, Vector2 to, Color color, float width = -1.0, bool antialiased = false) {
            canvas_item->draw_line(from, to, color, width, antialiased);
        }

        void drawMsdfTextureRectRegion(Texture2D* texture, Rect2 rect, Rect2 srcRect, Color modulate = Color(1, 1, 1, 1), float outline = 0.0, float pixelRange = 4.0, float scale = 1.0) {
            Ref<GodotTexture2D> textureRef = Ref<GodotTexture2D>(texture->getTexture());
            canvas_item->draw_msdf_texture_rect_region(textureRef, rect, srcRect, modulate, outline, pixelRange, scale);
        }

        void drawMultiline(std::vector<Vector2> points, Color color, float width = -1.0, bool antialiased = false) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            canvas_item->draw_multiline(pointsArray, color, width, antialiased);
        }

        void drawMultilineColors(std::vector<Vector2> points, std::vector<Color> colors, float width = -1.0, bool antialiased = false) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            PackedColorArray colorsArray;
            for (const Color& color : colors) {
                colorsArray.push_back(color);
            }
            canvas_item->draw_multiline_colors(pointsArray, colorsArray, width, antialiased);
        }

        void drawMultilineString(Font* font, Vector2 pos, std::string text, int alignment = 0, float width = -1, int fontSize = 16, int maxLines = -1, Color modulate = Color(1, 1, 1, 1), std::vector<int> brkFlags = {3}, std::vector<int> justificationFlags = {3}, int direction = 0, int orientation = 0) {
            BitField<TextServer::LineBreakFlag> brkFlagsBitField = NULL;
            for (int flag : brkFlags) {
                brkFlagsBitField = static_cast<TextServer::LineBreakFlag>(static_cast<int>(brkFlagsBitField) | flag);
            }
            BitField<TextServer::JustificationFlag> justificationFlagsBitField = NULL;
            for (int flag : justificationFlags) {
                justificationFlagsBitField = static_cast<TextServer::JustificationFlag>(static_cast<int>(justificationFlagsBitField) | flag);
            }
            canvas_item->draw_multiline_string(
                font->getFont(), 
                pos, 
                text.c_str(), 
                static_cast<HorizontalAlignment>(alignment), 
                width, 
                fontSize, 
                maxLines, 
                modulate, 
                brkFlagsBitField, 
                justificationFlagsBitField, 
                static_cast<TextServer::Direction>(direction), 
                static_cast<TextServer::Orientation>(orientation)
            );
        }

        void drawMultilineStringOutline(Font* font, Vector2 pos, std::string text, int alignment = 0, float width = -1, int fontSize = 16, int maxLines = -1, int size = 1, Color modulate = Color(1, 1, 1, 1), std::vector<int> brkFlags = {3}, std::vector<int> justificationFlags = {3}, int direction = 0, int orientation = 0) {
            BitField<TextServer::LineBreakFlag> brkFlagsBitField = NULL;
            for (int flag : brkFlags) {
                brkFlagsBitField = static_cast<TextServer::LineBreakFlag>(static_cast<int>(brkFlagsBitField) | flag);
            }
            BitField<TextServer::JustificationFlag> justificationFlagsBitField = NULL;
            for (int flag : justificationFlags) {
                justificationFlagsBitField = static_cast<TextServer::JustificationFlag>(static_cast<int>(justificationFlagsBitField) | flag);
            }
            canvas_item->draw_multiline_string_outline(
                font->getFont(), 
                pos, 
                text.c_str(), 
                static_cast<HorizontalAlignment>(alignment), 
                width, 
                fontSize, 
                maxLines, 
                size, 
                modulate, 
                brkFlagsBitField, 
                justificationFlagsBitField, 
                static_cast<TextServer::Direction>(direction), 
                static_cast<TextServer::Orientation>(orientation)
            );
        }

        void drawPolygon(std::vector<Vector2> points, std::vector<Color> colors, std::vector<Vector2> uvs = {}, Texture2D* texture = nullptr) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            PackedColorArray colorsArray;
            for (const Color& color : colors) {
                colorsArray.push_back(color);
            }
            PackedVector2Array uvsArray;
            if (texture != nullptr) {
                for (const Vector2& uv : uvs) {
                    uvsArray.push_back(uv);
                }
            }
            Ref<GodotTexture2D> textureRef;
            if (texture != nullptr) {
                textureRef = texture->getTexture();
            }
            canvas_item->draw_polygon(pointsArray, colorsArray, uvsArray, textureRef);
        }

        void drawPolyline(std::vector<Vector2> points, Color color, float width = -1.0, bool antialiased = false) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            canvas_item->draw_polyline(pointsArray, color, width, antialiased);
        }

        void drawPolylineColors(std::vector<Vector2> points, std::vector<Color> colors, float width = -1.0, bool antialiased = false) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            PackedColorArray colorsArray;
            for (const Color& color : colors) {
                colorsArray.push_back(color);
            }
            canvas_item->draw_polyline_colors(pointsArray, colorsArray, width, antialiased);
        }

        void drawPrimitive(std::vector<Vector2> points, std::vector<Color> colors, std::vector<Vector2> uvs = {}, Texture2D* texture = nullptr) {
            PackedVector2Array pointsArray;
            for (const Vector2& point : points) {
                pointsArray.push_back(point);
            }
            PackedColorArray colorsArray;
            for (const Color& color : colors) {
                colorsArray.push_back(color);
            }
            PackedVector2Array uvsArray;
            if (texture != nullptr) {
                for (const Vector2& uv : uvs) {
                    uvsArray.push_back(uv);
                }
            }
            Ref<GodotTexture2D> textureRef;
            if (texture != nullptr) {
                textureRef = texture->getTexture();
            }
            canvas_item->draw_primitive(pointsArray, colorsArray, uvsArray, textureRef);
        }

        void drawRect(Rect2 rect, Color color, bool filled = true, float width = 1.0, bool antiAliased = false) {
            canvas_item->draw_rect(rect, color, filled, width, antiAliased);
        }

        void drawSetTransform(Vector2 pos, float rotation = 0.0, Vector2 scale = Vector2(1, 1)) {
            canvas_item->draw_set_transform(pos, rotation, scale);
        }

        void drawSetTransformMatrix(Transform2D xform) {
            canvas_item->draw_set_transform_matrix(xform);
        }

        void drawString(Font* font, Vector2 pos, std::string text, int alignment = 0, float width = -1, int fontSize = 16, Color modulate = Color(1, 1, 1, 1), std::vector<int> justificationFlags = {3}, int direction = 0, int orientation = 0) {
            BitField<TextServer::JustificationFlag> justificationFlagsBitField = NULL;
            for (int flag : justificationFlags) {
                justificationFlagsBitField = static_cast<TextServer::JustificationFlag>(static_cast<int>(justificationFlagsBitField) | flag);
            }
            canvas_item->draw_string(
                font->getFont(), 
                pos, 
                text.c_str(), 
                static_cast<HorizontalAlignment>(alignment), 
                width, 
                fontSize, 
                modulate, 
                justificationFlagsBitField, 
                static_cast<TextServer::Direction>(direction), 
                static_cast<TextServer::Orientation>(orientation)
            );
        }

        void drawStringOutline(Font* font, Vector2 pos, std::string text, int alignment = 0, float width = -1, int fontSize = 16, int size = 1, Color modulate = Color(1, 1, 1, 1), std::vector<int> justificationFlags = {3}, int direction = 0, int orientation = 0) {
            BitField<TextServer::JustificationFlag> justificationFlagsBitField = NULL;
            for (int flag : justificationFlags) {
                justificationFlagsBitField = static_cast<TextServer::JustificationFlag>(static_cast<int>(justificationFlagsBitField) | flag);
            }
            canvas_item->draw_string_outline(
                font->getFont(), 
                pos, 
                text.c_str(), 
                static_cast<HorizontalAlignment>(alignment), 
                width, 
                fontSize, 
                size, 
                modulate, 
                justificationFlagsBitField, 
                static_cast<TextServer::Direction>(direction), 
                static_cast<TextServer::Orientation>(orientation)
            );
        }

        void drawStyleBox(sunaba::ui::StyleBox* styleBox, Rect2 rect) {
            canvas_item->draw_style_box(styleBox->getStyleBox(), rect);
        }

        void drawTexture(Texture2D* texture, Vector2 position, Color modulate = Color(1, 1, 1, 1)) {
            Ref<GodotTexture2D> textureRef = Ref<GodotTexture2D>(texture->getTexture());
            canvas_item->draw_texture(textureRef, position, modulate);
        }

        void drawTextureRect(Texture2D* texture, Rect2 rect, bool tile, Color modulate = Color(1, 1, 1, 1), bool transpose = false) {
            Ref<GodotTexture2D> textureRef = Ref<GodotTexture2D>(texture->getTexture());
            canvas_item->draw_texture_rect(textureRef, rect, tile, modulate, transpose);
        }

        void drawTextureRectRegion(Texture2D* texture, Rect2 rect, Rect2 srcRect, Color modulate = Color(1, 1, 1, 1), bool transpose = false, bool clipUv = true) {
            Ref<GodotTexture2D> textureRef = Ref<GodotTexture2D>(texture->getTexture());
            canvas_item->draw_texture_rect_region(textureRef, rect, srcRect, modulate, transpose, clipUv);
        }

        void forceUpdateTransform() {
            canvas_item->force_update_transform();
        }

        Transform2D getCanvasTransform() {
            return canvas_item->get_canvas_transform();
        }

        Vector2 getGlobalMousePosition() {
            return canvas_item->get_global_mouse_position();
        }

        Transform2D getGlobalTransform() {
            return canvas_item->get_global_transform();
        }

        Transform2D getGlobalTransformWithCanvas() {
            return canvas_item->get_global_transform_with_canvas();
        }

        Vector2 getLocalMousePosition() {
            return canvas_item->get_local_mouse_position();
        }

        Transform2D getScreenTransform() {
            return canvas_item->get_screen_transform();
        }

        Transform2D getTransform() {
            return canvas_item->get_transform();
        }

        Rect2 getViewportRect() {
            return canvas_item->get_viewport_rect();
        }

        Transform2D getViewportTransform() {
            return canvas_item->get_viewport_transform();
        }

        bool getVisibilityLayerBit(int bit) {
            return canvas_item->get_visibility_layer_bit(bit);
        }

        void hide() {
            canvas_item->hide();
        }

        bool isLocalTransformNotificationEnabled() {
            return canvas_item->is_local_transform_notification_enabled();
        }

        bool isTransformNotificationEnabled() {
            return canvas_item->is_transform_notification_enabled();
        }

        bool isVisibleInTree() {
            return canvas_item->is_visible_in_tree();
        }

        Vector2 makeCanvasPositionLocal(Vector2 pos) {
            return canvas_item->make_canvas_position_local(pos);
        }

        sunaba::input::InputEvent* makeInputLocal(sunaba::input::InputEvent* event) {
            return new sunaba::input::InputEvent(canvas_item->make_input_local(event->getInputEvent()).ptr());
        }

        void moveToFront() {
            canvas_item->move_to_front();
        }

        void queueRedraw() {
            canvas_item->queue_redraw();
        }

        void setNotifyLocalTransform(bool enable) {
            canvas_item->set_notify_local_transform(enable);
        }

        void setNotifyTransform(bool enable) {
            canvas_item->set_notify_transform(enable);
        }

        void show() {
            canvas_item->show();
        }

        void _draw() {
            if (scriptInstance != sol::lua_nil) {
                auto func = scriptInstance["draw"].get<sol::function>();
                if (func) {
                    func(scriptInstance);
                }
            }
        }
    };
}

#endif // ELEMENT_H