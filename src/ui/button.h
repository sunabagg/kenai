#ifndef BUTTON_H
#define BUTTON_H

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ButtonNode godot::Button

#include "base_button.h"
#include "../core/texture2d.h"

namespace sunaba::ui {
    void bindButton(sol::state& lua);

    class Button;

    class ButtonProxy : public ButtonNode {
        GDCLASS(ButtonProxy, ButtonNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to ButtonProxy
            }
        public:
            sunaba::ui::Button* element = nullptr;

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

            void _toggled(bool p_toggled_on) override;
    };

    class Button : public sunaba::ui::BaseButton {
        private:
            ButtonNode* button = nullptr;

        public:
            // Constructor with Node* parameter
            Button(ButtonNode* p_node) {
                setButton(p_node);
            }

            // Constructor with no parameters
            Button() {
                setButton(memnew(ButtonNode));
                onInit();
            }

            // Getter for the Button node
            ButtonNode* getButton() {
                return button;
            }

            // Setter for the Button node
            void setButton(ButtonNode* p_node) {
                button = p_node;
                setBaseButton(button);
            }

            void setButton(ButtonProxy* p_node) {
                button = p_node;
                p_node->element = this;
                setBaseButton(button);
            }

            int getAlignment() {
                return button->get_text_alignment();
            }

            void setAlignment(int alignment) {
                button->set_text_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            int getAutowrapMode() {
                return button->get_autowrap_mode();
            }

            void setAutowrapMode(int mode) {
                button->set_autowrap_mode(static_cast<godot::TextServer::AutowrapMode>(mode));
            }

            bool getClipText() {
                return button->get_clip_text();
            }

            void setClipText(bool enabled) {
                button->set_clip_text(enabled);
            }

            bool isExpandIcon() {
                return button->is_expand_icon();
            }

            void setExpandIcon(bool enabled) {
                button->set_expand_icon(enabled);
            }

            bool isFlat() {
                return button->is_flat();
            }

            void setFlat(bool enabled) {
                button->set_flat(enabled);
            }

            sunaba::core::Texture2D* getIcon() {
                return new sunaba::core::Texture2D(button->get_button_icon().ptr());
            }

            void setIcon(sunaba::core::Texture2D* texture) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                button->set_button_icon(textureRef);
            }

            int getIconAlignment() {
                return button->get_icon_alignment();
            }

            void setIconAlignment(int alignment) {
                button->set_icon_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            std::string getLanguage() {
                return String(button->get_language()).utf8().get_data();
            }

            void setLanguage(std::string language) {
                button->set_language(String(language.c_str()));
            }

            std::string getText() {
                return String(button->get_text()).utf8().get_data();
            }

            void setText(std::string text) {
                button->set_text(String(text.c_str()));
            }

            int getTextDirection() {
                return button->get_text_direction();
            }

            void setTextDirection(int direction) {
                button->set_text_direction(static_cast<godot::Control::TextDirection>(direction));
            }

            int getTextOverrunBehavior() {
                return button->get_text_overrun_behavior();
            }

            void setTextOverrunBehavior(int behavior) {
                button->set_text_overrun_behavior(static_cast<godot::TextServer::OverrunBehavior>(behavior));
            }

            int getVerticalIconAlignment() {
                return button->get_vertical_icon_alignment();
            }

            void setVerticalIconAlignment(int alignment) {
                button->set_vertical_icon_alignment(static_cast<godot::VerticalAlignment>(alignment));
            }
    };
}

#endif // BUTTON_H