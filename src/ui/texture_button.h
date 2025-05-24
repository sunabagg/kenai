#ifndef TEXTURE_BUTTON_H
#define TEXTURE_BUTTON_H

#include <godot_cpp/classes/texture_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TextureButtonNode godot::TextureButton

#include "base_button.h"
#include "../core/bit_map.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTextureButton(sol::state &lua);

    class TextureButton;

    class TextureButtonProxy : public TextureButtonNode {
        public:
            sunaba::ui::TextureButton* element = nullptr;

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

            void _pressed() override;

            void _toggled(bool button_pressed) override;
    };

    class TextureButton : public BaseButton {
        private:
            TextureButtonNode* texture_button = nullptr;

            void connectTextureButtonSignals() {
            }
        public:
            // Constructor with Node* parameter
            TextureButton(TextureButtonNode* p_node) {
                setTextureButton(p_node);
            }

            TextureButton(TextureButtonProxy* p_node) {
                setTextureButton(p_node);
            }

            // Constructor with no parameters
            TextureButton() {
                TextureButtonProxy* tbp = memnew(TextureButtonProxy);
                setTextureButton(tbp);
            }

            void setTextureButton(TextureButtonNode* p_node) {
                this->texture_button = p_node;
                connectTextureButtonSignals();
                setBaseButton(p_node);
            }

            void setTextureButton(TextureButtonProxy* p_node) {
                this->texture_button = p_node;
                p_node->element = this;
                connectTextureButtonSignals();
                setBaseButton(p_node);
            }

            bool getFlipH() const {
                return this->texture_button->is_flipped_h();
            }

            void setFlipH(bool enable) {
                this->texture_button->set_flip_h(enable);
            }

            bool getFlipV() const {
                return this->texture_button->is_flipped_v();
            }

            void setFlipV(bool enable) {
                this->texture_button->set_flip_v(enable);
            }

            bool getIgnoreTextureSize() const {
                return this->texture_button->get_ignore_texture_size();
            }

            void setIgnoreTextureSize(bool ignore) {
                this->texture_button->set_ignore_texture_size(ignore);
            }

            int getStretchMode() const {
                return this->texture_button->get_stretch_mode();
            }

            void setStretchMode(int mode) {
                this->texture_button->set_stretch_mode(static_cast<TextureButtonNode::StretchMode>(mode));
            }

            sunaba::core::BitMap* getTextureClickMask() const {
                return new sunaba::core::BitMap(this->texture_button->get_click_mask().ptr());
            }

            void setTextureClickMask(sunaba::core::BitMap* mask) {
                this->texture_button->set_click_mask(mask->getBitMap());
            }

            sunaba::core::Texture2D* getTextureDisabled() const {
                return new sunaba::core::Texture2D(this->texture_button->get_texture_disabled().ptr());
            }

            void setTextureDisabled(sunaba::core::Texture2D* texture) {
                this->texture_button->set_texture_disabled(texture->getTexture2D());
            }

            sunaba::core::Texture2D* getTextureFocused() const {
                return new sunaba::core::Texture2D(this->texture_button->get_texture_focused().ptr());
            }

            void setTextureFocused(sunaba::core::Texture2D* texture) {
                this->texture_button->set_texture_focused(texture->getTexture2D());
            }

            sunaba::core::Texture2D* getTextureHover() const {
                return new sunaba::core::Texture2D(this->texture_button->get_texture_hover().ptr());
            }

            void setTextureHover(sunaba::core::Texture2D* texture) {
                this->texture_button->set_texture_hover(texture->getTexture2D());
            }

            sunaba::core::Texture2D* getTextureNormal() const {
                return new sunaba::core::Texture2D(this->texture_button->get_texture_normal().ptr());
            }

            void setTextureNormal(sunaba::core::Texture2D* texture) {
                this->texture_button->set_texture_normal(texture->getTexture2D());
            }

            sunaba::core::Texture2D* getTexturePressed() const {
                return new sunaba::core::Texture2D(this->texture_button->get_texture_pressed().ptr());
            }

            void setTexturePressed(sunaba::core::Texture2D* texture) {
                this->texture_button->set_texture_pressed(texture->getTexture2D());
            }
    }
}