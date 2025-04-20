#ifndef CONTROL_H
#define CONTROL_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ControlNode godot::Control

#include "../core/canvas_item.h"
#include "../core/font.h"
#include "theme.h"

namespace sunaba::ui {
    void bindControl(sol::state &lua);

    class Control;

    class ControlProxy : public ControlNode, public CanvasItemProxy {
        public:
            sunaba::ui::Control* control_element = nullptr;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class Control : public sunaba::core::CanvasItem {
        private:
            ControlNode* control = nullptr; // Pointer to the Control instance
        public:
            // Constructor with Node* parameter
            Control(ControlNode* p_node) {
                setControl(p_node);
            }

            Control(ControlProxy* p_node) {
                setControl(p_node);
            }
        
            // Constructor with no parameters
            Control() {
                setControl(memnew(ControlNode));
                onInit();
            }

            // Getter for the Control node
            ControlNode* getControl() {
                return control;
            }

            // Setter for the Control node
            void setControl(ControlNode* p_node) {
                control = p_node;
                setCanvasItem(control);
            }

            void setControl(ControlProxy* p_node) {
                control = p_node;
                p_node->control_element = this;
                setCanvasItem(p_node);
            }

            float getAnchorBottom() {
                return control->get_anchor(SIDE_BOTTOM);
            }

            void setAnchorBottom(float value) {
                control->set_anchor(SIDE_BOTTOM, value);
            }

            float getAnchorLeft() {
                return control->get_anchor(SIDE_LEFT);
            }

            void setAnchorLeft(float value) {
                control->set_anchor(SIDE_LEFT, value);
            }

            float getAnchorRight() {
                return control->get_anchor(SIDE_RIGHT);
            }

            void setAnchorRight(float value) {
                control->set_anchor(SIDE_RIGHT, value);
            }

            float getAnchorTop() {
                return control->get_anchor(SIDE_TOP);
            }

            void setAnchorTop(float value) {
                control->set_anchor(SIDE_TOP, value);
            }

            bool isAutoTranslating() {
                return control->is_auto_translating();
            }

            void setAutoTranslate(bool value) {
                control->set_auto_translate(value);
            }

            bool isClippingContents() {
                return control->is_clipping_contents();
            }

            void setClipContents(bool value) {
                control->set_clip_contents(value);
            }

            Vector2 getCustomMinimumSize() {
                return control->get_custom_minimum_size();
            }

            void setCustomMinimumSize(Vector2 size) {
                control->set_custom_minimum_size(size);
            }

            int getFocusMode() {
                return control->get_focus_mode();
            }

            void setFocusMode(int mode) {
                control->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            std::string getFocusNeighborBottom() {
                return String(control->get_focus_neighbor(SIDE_BOTTOM)).utf8().get_data();
            }

            void setFocusNeighborBottom(std::string name) {
                control->set_focus_neighbor(SIDE_BOTTOM, String(name.c_str()));
            }

            std::string getFocusNeighborLeft() {
                return String(control->get_focus_neighbor(SIDE_LEFT)).utf8().get_data();
            }

            void setFocusNeighborLeft(std::string name) {
                control->set_focus_neighbor(SIDE_LEFT, String(name.c_str()));
            }

            std::string getFocusNeighborRight() {
                return String(control->get_focus_neighbor(SIDE_RIGHT)).utf8().get_data();
            }

            void setFocusNeighborRight(std::string name) {
                control->set_focus_neighbor(SIDE_RIGHT, String(name.c_str()));
            }

            std::string getFocusNeighborTop() {
                return String(control->get_focus_neighbor(SIDE_TOP)).utf8().get_data();
            }

            void setFocusNeighborTop(std::string name) {
                control->set_focus_neighbor(SIDE_TOP, String(name.c_str()));
            }

            std::string getFocusNext() {
                return String(control->get_focus_next()).utf8().get_data();
            }

            void setFocusNext(std::string name) {
                control->set_focus_next(String(name.c_str()));
            }

            std::string getFocusPrevious() {
                return String(control->get_focus_previous()).utf8().get_data();
            }

            void setFocusPrevious(std::string name) {
                control->set_focus_previous(String(name.c_str()));
            }

            Vector2 getGlobalPosition() {
                return control->get_global_position();
            }

            void setGlobalPosition(Vector2 position) {
                control->set_global_position(position);
            }

            int getGrowHorizontal() {
                return control->get_h_grow_direction();
            }

            void setGrowHorizontal(int direction) {
                control->set_h_grow_direction(static_cast<godot::Control::GrowDirection>(direction));
            }

            int getGrowVertical() {
                return control->get_v_grow_direction();
            }

            void setGrowVertical(int direction) {
                control->set_v_grow_direction(static_cast<godot::Control::GrowDirection>(direction));
            }

            int getLayoutDirection() {
                return control->get_layout_direction();
            }

            void setLayoutDirection(int direction) {
                control->set_layout_direction(static_cast<godot::Control::LayoutDirection>(direction));
            }

            bool isLocalizingNumeralSystem() {
                return control->is_localizing_numeral_system();
            }
            
            void setLocalizeNumeralSystem(bool value) {
                control->set_localize_numeral_system(value);
            }

            int getMouseDefaultCursorShape() {
                return control->get_default_cursor_shape();
            }

            void setMouseDefaultCursorShape(int shape) {
                control->set_default_cursor_shape(static_cast<godot::Control::CursorShape>(shape));
            }

            int getMouseFilter() {
                return control->get_mouse_filter();
            }

            void setMouseFilter(int filter) {
                control->set_mouse_filter(static_cast<godot::Control::MouseFilter>(filter));
            }

            bool getMouseForcePassScrollEvents() {
                return control->is_force_pass_scroll_events();
            }

            void setMouseForcePassScrollEvents(bool value) {
                control->set_force_pass_scroll_events(value);
            }

            float getOffsetBottom() {
                return control->get_offset(SIDE_BOTTOM);
            }

            void setOffsetBottom(float value) {
                control->set_offset(SIDE_BOTTOM, value);
            }

            float getOffsetLeft() {
                return control->get_offset(SIDE_LEFT);
            }

            void setOffsetLeft(float value) {
                control->set_offset(SIDE_LEFT, value);
            }

            float getOffsetRight() {
                return control->get_offset(SIDE_RIGHT);
            }

            void setOffsetRight(float value) {
                control->set_offset(SIDE_RIGHT, value);
            }

            float getOffsetTop() {
                return control->get_offset(SIDE_TOP);
            }

            void setOffsetTop(float value) {
                control->set_offset(SIDE_TOP, value);
            }

            int getPhysicsInterpolationMode() {
                return control->get_physics_interpolation_mode();
            }

            void setPhysicsInterpolationMode(int mode) {
                control->set_physics_interpolation_mode(static_cast<godot::Control::PhysicsInterpolationMode>(mode));
            }

            Vector2 getPivotOffset() {
                return control->get_pivot_offset();
            }

            void setPivotOffset(Vector2 offset) {
                control->set_pivot_offset(offset);
            }

            Vector2 getPosition() {
                return control->get_position();
            }

            void setPosition(Vector2 position) {
                control->set_position(position);
            }

            float getRotation() {
                return control->get_rotation();
            }

            void setRotation(float rotation) {
                control->set_rotation(rotation);
            }

            float getRotationDegrees() {
                return control->get_rotation_degrees();
            }

            void setRotationDegrees(float rotation) {
                control->set_rotation_degrees(rotation);
            }

            Vector2 getScale() {
                return control->get_scale();
            }

            void setScale(Vector2 scale) {
                control->set_scale(scale);
            }

            Element* getShortcutContext() {
                return new Element(control->get_shortcut_context());
            }

            Vector2 getSize() {
                return control->get_size();
            }

            void setSize(Vector2 size) {
                control->set_size(size);
            }

            int getSizeFlagsHorizontal() {
                return control->get_h_size_flags();
            }

            void setSizeFlagsHorizontal(int flags) {
                control->set_h_size_flags(static_cast<godot::Control::SizeFlags>(flags));
            }

            float getSizeFlagsStretchRatio() {
                return control->get_stretch_ratio();
            }

            void setSizeFlagsStretchRatio(float ratio) {
                control->set_stretch_ratio(ratio);
            }

            int getSizeFlagsVertical() {
                return control->get_v_size_flags();
            }

            void setSizeFlagsVertical(int flags) {
                control->set_v_size_flags(static_cast<godot::Control::SizeFlags>(flags));
            }

            Theme* getTheme() {
                return new Theme(control->get_theme().ptr());
            }

            void setTheme(Theme* theme) {
                control->set_theme(theme->getTheme());
            }

            std::string getThemeTypeVariation() {
                return String(control->get_theme_type_variation()).utf8().get_data();
            }

            void setThemeTypeVariation(std::string variation) {
                control->set_theme_type_variation(String(variation.c_str()));
            }

            int getToolTipAutoTranslateMode() {
                return control->get_tooltip_auto_translate_mode();
            }

            void setToolTipAutoTranslateMode(int mode) {
                control->set_tooltip_auto_translate_mode(static_cast<godot::Control::AutoTranslateMode>(mode));
            }

            std::string getToolTipText() {
                return String(control->get_tooltip_text()).utf8().get_data();
            }

            void setToolTipText(std::string text) {
                control->set_tooltip_text(String(text.c_str()));
            }

            void acceptEvent() {
                control->accept_event();
            }

            void addThemeColorOverride(String name, Color color) {
                control->add_theme_color_override(name, color);
            }

            void addThemeConstantOverride(String name, Variant constant) {
                control->add_theme_constant_override(name, constant);
            }

            void addThemeFontOverride(String name, sunaba::core::Font* font) {
                Ref<godot::Font> fontRef = Ref<godot::Font>(font->getFont());
                control->add_theme_font_override(name, fontRef);
            }

            void addThemeFontSizeOverride(String name, int size) {
                control->add_theme_font_size_override(name, size);
            }

            void addThemeIconOverride(String name, sunaba::core::Texture2D* texture) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                control->add_theme_icon_override(name, textureRef);
            }

            void addThemeStyleboxOverride(String name, sunaba::ui::StyleBox* styleBox) {
                Ref<godot::StyleBox> styleBoxRef = Ref<godot::StyleBox>(styleBox->getStyleBox());
                control->add_theme_stylebox_override(name, styleBoxRef);
            }

            void beginBulkThemeOveride() {
                control->begin_bulk_theme_override();
            }

            void endBulkThemeOveride() {
                control->end_bulk_theme_override();
            }

            Control* findNextValidFocus() {
                return new Control(control->find_next_valid_focus());
            }

            Control* findPrevValidFocus() {
                return new Control(control->find_prev_valid_focus());
            }

            Control* findValidFocusNeighbor(int slide) {
                return new Control(control->find_valid_focus_neighbor(static_cast<godot::Side>(slide)));
            }

            void forceDrag(Variant &data, Control* preview) {
                control->force_drag(data, preview->getControl());
            }

            float getAnchor(int side) {
                return control->get_anchor(static_cast<godot::Side>(side));
            }

            Vector2 getBegin() {
                return control->get_begin();
            }

            Vector2 getCombinedMinimumSize() {
                return control->get_combined_minimum_size();
            }

            int getCursorShape(Vector2 position) {
                return control->get_cursor_shape(position);
            }

            Vector2 getEnd() {
                return control->get_end();
            }

            std::string getFocusNeighbor(int side) {
                return String(control->get_focus_neighbor(static_cast<godot::Side>(side))).utf8().get_data();
            }

            Rect2 getGlobalRect() {
                return control->get_global_rect();
            }

            Vector2 getMinimumSize() {
                return control->get_minimum_size();
            }

            float getOffset(int side) {
                return control->get_offset(static_cast<godot::Side>(side));
            }

            Vector2 getParentAreaMinimumSize() {
                return control->get_parent_area_minimum_size();
            }
    };
}

#endif // CONTROL_H