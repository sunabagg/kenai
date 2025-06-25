#ifndef LINK_BUTTON_H
#define LINK_BUTTON_H

#include <godot_cpp/classes/link_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define LinkButtonNode godot::LinkButton

#include "base_button.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindLinkButton(sol::state &lua);

    class LinkButton;

    class LinkButtonProxy : public LinkButtonNode {
        GDCLASS(LinkButtonProxy, LinkButtonNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to LinkButtonProxy
            }
        public:
            lucidware::ui::LinkButton* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

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

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;

            void _pressed() override;

            void _toggled(bool p_toggled_on) override;
    };

    class LinkButton : public BaseButton {
        private:
            LinkButtonNode* link_button = nullptr;

            void connectLinkButtonSignals() {
                // Connect signals for the LinkButton
            }

        public:
            LinkButton() {
                setLinkButtonNode(memnew(LinkButtonNode));
                onInit();
            }

            LinkButton(LinkButtonNode* p_node) {
                setLinkButtonNode(p_node);
            }

            LinkButtonNode* getLinkButtonNode() {
                return link_button;
            }

            void setLinkButtonNode(LinkButtonNode* p_node) {
                link_button = p_node;
                connectLinkButtonSignals();
                setCanvasItem(p_node);
            }

            void setLinkButtonNode(LinkButtonProxy* p_node) {
                link_button = p_node;
                p_node->element = this;
                connectLinkButtonSignals();
                setCanvasItem(p_node);
            }

            int getFocusMode() {
                return link_button->get_focus_mode();
            }

            void setFocusMode(int mode) {
                link_button->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            std::string getLanguage() {
                return String(link_button->get_language()).utf8().get_data();
            }

            void setLanguage(std::string language) {
                link_button->set_language(String(language.c_str()));
            }

            int getMouseDefaultCursorShape() {
                return link_button->get_default_cursor_shape();
            }

            void setMouseDefaultCursorShape(int shape) {
                link_button->set_default_cursor_shape(static_cast<godot::Control::CursorShape>(shape));
            }

            int getStructuredTextBidiOverride() {
                return link_button->get_structured_text_bidi_override();
            }

            void setStructuredTextBidiOverride(int override) {
                link_button->set_structured_text_bidi_override(static_cast<godot::TextServer::StructuredTextParser>(override));
            }

            Array getStructuredTextBidiOverrideOptions() {
                return link_button->get_structured_text_bidi_override_options();
            }

            void setStructuredTextBidiOverrideOptions(const Array &args) {
                link_button->set_structured_text_bidi_override_options(args);
            }

            std::string getText() {
                return String(link_button->get_text()).utf8().get_data();
            }

            void setText(std::string text) {
                link_button->set_text(String(text.c_str()));
            }
            
            int getTextDirection() {
                return link_button->get_text_direction();
            }

            void setTextDirection(int direction) {
                link_button->set_text_direction(static_cast<godot::Control::TextDirection>(direction));
            }

            int getUnderline() {
                return link_button->get_underline_mode();
            }

            void setUnderline(int mode) {
                link_button->set_underline_mode(static_cast<godot::LinkButton::UnderlineMode>(mode));
            }

            std::string getUri() {
                return String(link_button->get_uri()).utf8().get_data();
            }

            void setUri(std::string uri) {
                link_button->set_uri(String(uri.c_str()));
            }
    };
}

#endif // LINK_BUTTON_H