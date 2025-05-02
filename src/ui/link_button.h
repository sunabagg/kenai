#ifndef LINK_BUTTON_H
#define LINK_BUTTON_H

#include <godot_cpp/classes/link_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define LinkButtonNode godot::LinkButton

#include "base_button.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindLinkButton(sol::state &lua);

    class LinkButton;

    class LinkButtonProxy : public LinkButtonNode {
        public:
            sunaba::ui::LinkButton* element = nullptr;

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
                setLinkButtonNode(memnew(LinkButtonProxy));
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
    };
}

#endif // LINK_BUTTON_H