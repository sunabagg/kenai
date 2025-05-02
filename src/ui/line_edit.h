#ifndef LINE_EDIT_H
#define LINE_EDIT_H

#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define LineEditNode godot::LineEdit

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindLineEdit(sol::state &lua);

    class LineEdit;

    class LineEditProxy : public LineEditNode {
        public:
            sunaba::ui::LineEdit* element = nullptr;

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
    };

    class LineEdit : public Control {
        private:
            LineEditNode* line_edit_node = nullptr;

            void connectLineEditSignals() {
                // Connect signals specific to LineEdit
            }

        public:
            LineEdit() {
                setLineEditNode(memnew(LineEditProxy));
                onInit();
            }

            LineEdit(LineEditNode* line_edit) {
                setLineEditNode(line_edit);
                onInit();
            }

            void setLineEditNode(LineEditNode* line_edit) {
                line_edit_node = line_edit;
                connectLineEditSignals();
                setControl(line_edit_node);
            }

            void setLineEditNode(LineEditProxy* line_edit) {
                line_edit_node = line_edit;
                line_edit->element = this;
                connectLineEditSignals();
                setControl(line_edit_node);
            }

            LineEditNode* getLineEditNode() {
                return line_edit_node;
            }

            int getAlignment() {
                return line_edit_node->get_horizontal_alignment();
            }

            void setAlignment(int alignment) {
                line_edit_node->set_horizontal_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            bool getCaretBlink() {
                return line_edit_node->is_caret_blink_enabled();
            }

            void setCaretBlink(bool enabled) {
                line_edit_node->set_caret_blink_enabled(enabled);
            }

            float getCaretBlinkInterval() {
                return line_edit_node->get_caret_blink_interval();
            }

            void setCaretBlinkInterval(float interval) {
                line_edit_node->set_caret_blink_interval(interval);
            }

            int getCaretColumn() {
                return line_edit_node->get_caret_column();
            }

            void setCaretColumn(int column) {
                line_edit_node->set_caret_column(column);
            }

            bool getCaretForceDisplayed() {
                return line_edit_node->is_caret_force_displayed();
            }

            void setCaretForceDisplayed(bool enabled) {
                line_edit_node->set_caret_force_displayed(enabled);
            }

            bool getCaretMidGrapheme() {
                return line_edit_node->is_caret_mid_grapheme_enabled();
            }

            void setCaretMidGrapheme(bool enabled) {
                line_edit_node->set_caret_mid_grapheme_enabled(enabled);
            }

            bool getClearButtonEnabled() {
                return line_edit_node->is_clear_button_enabled();
            }

            void setClearButtonEnabled(bool enabled) {
                line_edit_node->set_clear_button_enabled(enabled);
            }

            bool getContextMenuEnabled() {
                return line_edit_node->is_context_menu_enabled();
            }

            void setContextMenuEnabled(bool enabled) {
                line_edit_node->set_context_menu_enabled(enabled);
            }

            bool getDeselectOnFocusLossEnabled() {
                return line_edit_node->is_deselect_on_focus_loss_enabled();
            }

            void setDeselectOnFocusLossEnabled(bool enabled) {
                line_edit_node->set_deselect_on_focus_loss_enabled(enabled);
            }

            bool getDragAndDropSelectionEnabled() {
                return line_edit_node->is_drag_and_drop_selection_enabled();
            }

            void setDragAndDropSelectionEnabled(bool enabled) {
                line_edit_node->set_drag_and_drop_selection_enabled(enabled);
            }

            bool getDrawControlChars() {
                return line_edit_node->get_draw_control_chars();
            }

            void setDrawControlChars(bool enabled) {
                line_edit_node->set_draw_control_chars(enabled);
            }

            bool getEditable() {
                return line_edit_node->is_editable();
            }

            void setEditable(bool enabled) {
                line_edit_node->set_editable(enabled);
            }

            bool getEmojiMenuEnabled() {
                return line_edit_node->is_emoji_menu_enabled();
            }

            void setEmojiMenuEnabled(bool enabled) {
                line_edit_node->set_emoji_menu_enabled(enabled);
            }

            bool getExpandToTextLength() {
                return line_edit_node->is_expand_to_text_length_enabled();
            }

            void setExpandToTextLength(bool enabled) {
                line_edit_node->set_expand_to_text_length_enabled(enabled);
            }

            bool getFlat() {
                return line_edit_node->is_flat();
            }

            void setFlat(bool enabled) {
                line_edit_node->set_flat(enabled);
            }

            int getFocusMode() {
                return line_edit_node->get_focus_mode();
            }

            void setFocusMode(int mode) {
                line_edit_node->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }
    };
}

#endif // LINE_EDIT_H