#ifndef TEXTURE_RECT_H
#define TEXTURE_RECT_H

#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TextureRectNode godot::TextureRect

#include "control.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTextureRect(sol::state &lua);

    class TextureRect;

    class TextureRectProxy : public TextureRectNode {
        public:
            sunaba::ui::TextureRect* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class TextureRect : public sunaba::ui::Control {
        private:
            TextureRectNode* texture_rect = nullptr; // Pointer to the TextureRect instance
        public:
            TextureRect() {
                setTextureRect(memnew(TextureRectProxy));
                onInit();
            }

            TextureRect(TextureRectNode* p_texture_rect) {
                setTextureRect(p_texture_rect);
            }

            TextureRectNode* getTextureRect() {
                return texture_rect;
            }
            void setTextureRect(TextureRectNode* p_texture_rect) {
                this->texture_rect = p_texture_rect;
                setControl(p_texture_rect);
            }

            void setTextureRect(TextureRectProxy* p_texture_rect) {
                this->texture_rect = p_texture_rect;
                p_texture_rect->element = this;
                setControl(p_texture_rect);
            }

            int getExpandMode() const {
                return texture_rect->get_expand_mode();
            }

            void setExpandMode(int p_expand_mode) {
                texture_rect->set_expand_mode(static_cast<TextureRectNode::ExpandMode>(p_expand_mode));
            }

            bool getFlipH() const {
                return texture_rect->is_flipped_h();
            }

            void setFlipH(bool p_enable) {
                texture_rect->set_flip_h(p_enable);
            }

            bool getFlipV() const {
                return texture_rect->is_flipped_v();
            }

            void setFlipV(bool p_enable) {
                texture_rect->set_flip_v(p_enable);
            }

            int getMouseFilter() const {
                return texture_rect->get_mouse_filter();
            }

            void setMouseFilter(int p_filter) {
                texture_rect->set_mouse_filter(static_cast<TextureRectNode::MouseFilter>(p_filter));
            }

            int getStretchMode() const {
                return texture_rect->get_stretch_mode();
            }
    };
}

#endif // TEXTURE_RECT_H