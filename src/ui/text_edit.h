#ifndef TEXT_EDIT_H
#define TEXT_EDIT_H

#include <godot_cpp/classes/text_edit.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TextEditNode godot::TextEdit

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTextEdit(sol::state &lua);

    class TextEdit;

    class TextEditProxy : public TextEditNode {
        public:
            sunaba::ui::TextEdit* element = nullptr;

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

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;

            void _backspace(int caret_index) override;

            void _copy(int caret_index) override;

            void _cut(int caret_index) override;

            void _handle_unicode_input(int unicode_char, int caret_index) override;

            void _paste(int caret_index) override;

            void _paste_primary_clipboard(int caret_index) override;
    };

    class TextEdit : public Control {
        private:
            TextEditNode* text_edit = nullptr; // Pointer to the TextEdit instance
            void connectTextEditSignals() {
                // Connect signals from the text_edit to the element
                // Example: text_edit->connect("signal_name", this, "method_name");
            }
        public:
            TextEdit() {
                setTextEdit(memnew(TextEditProxy));
                onInit();
            }

            TextEdit(TextEditNode* text_edit) {
                setTextEdit(text_edit);
            }

            TextEditNode* getTextEdit() {
                return text_edit;
            }

            void setTextEdit(TextEditNode* text_edit) {
                this->text_edit = text_edit;
                connectTextEditSignals();
                setControl(text_edit);
            }
            
            void setTextEdit(TextEditProxy* text_edit) {
                this->text_edit = text_edit;
                text_edit->element = this;
                connectTextEditSignals();
                setControl(text_edit);
            }

            int getAutowrapMode() {
                return text_edit->get_autowrap_mode();
            }

            void setAutowrapMode(int mode) {
                text_edit->set_autowrap_mode(static_cast<godot::TextServer::AutowrapMode>(mode));
            }

            bool getCaretBlink() {
                return text_edit->is_caret_blink_enabled();
            }

            void setCaretBlink(bool enabled) {
                text_edit->set_caret_blink_enabled(enabled);
            }

            float getCaretBlinkInterval() {
                return text_edit->get_caret_blink_interval();
            }

            void setCaretBlinkInterval(float interval) {
                text_edit->set_caret_blink_interval(interval);
            }

            bool getCaretDrawWhenEditableDisabled() {
                return text_edit->is_drawing_caret_when_editable_disabled();
            }

            void setCaretDrawWhenEditableDisabled(bool enabled) {
                text_edit->set_draw_caret_when_editable_disabled(enabled);
            }

            bool getCaretMidGrapheme() {
                return text_edit->is_caret_mid_grapheme_enabled();
            }

            void setCaretMidGrapheme(bool enabled) {
                text_edit->set_caret_mid_grapheme_enabled(enabled);
            }

            bool getCaretMoveOnRightClick() {
                return text_edit->is_move_caret_on_right_click_enabled();
            }

            void setCaretMoveOnRightClick(bool enabled) {
                text_edit->set_move_caret_on_right_click_enabled(enabled);
            }

            bool getCaretMultiple() {
                return text_edit->is_multiple_carets_enabled();
            }

            void setCaretMultiple(bool enabled) {
                text_edit->set_multiple_carets_enabled(enabled);
            }

            int getCaretType() {
                return text_edit->get_caret_type();
            }

            void setCaretType(int type) {
                text_edit->set_caret_type(static_cast<godot::TextEdit::CaretType>(type));
            }

            bool getClipContents() {
                return text_edit->is_clipping_contents();
            }

            void setClipContents(bool enabled) {
                text_edit->set_clip_contents(enabled);
            }

            bool getContextMenuEnabled() {
                return text_edit->is_context_menu_enabled();
            }

            void setContextMenuEnabled(bool enabled) {
                text_edit->set_context_menu_enabled(enabled);
            }

            std::string getCustomWordSeparators() {
                return String(text_edit->get_custom_word_separators()).utf8().get_data();
            }
    };
}

#endif // TEXT_EDIT_H