#ifndef TEXT_EDIT_H
#define TEXT_EDIT_H

#include <godot_cpp/classes/text_edit.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TextEditNode godot::TextEdit

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "syntax_highlighter.h"
#include "h_scroll_bar.h"
#include "../desktop/popup_menu.h"

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

            void setCustomWordSeparators(std::string separators) {
                text_edit->set_custom_word_separators(String(separators.c_str()));
            }

            bool getDeselectOnFocusLossEnabled() {
                return text_edit->is_deselect_on_focus_loss_enabled();
            }

            void setDeselectOnFocusLossEnabled(bool enabled) {
                text_edit->set_deselect_on_focus_loss_enabled(enabled);
            }

            bool getDragAndDropSelectionEnabled() {
                return text_edit->is_drag_and_drop_selection_enabled();
            }

            void setDragAndDropSelectionEnabled(bool enabled) {
                text_edit->set_drag_and_drop_selection_enabled(enabled);
            }

            bool getDrawControlChars() {
                return text_edit->get_draw_control_chars();
            }

            void setDrawControlChars(bool enabled) {
                text_edit->set_draw_control_chars(enabled);
            }

            bool getDrawSpaces() {
                return text_edit->is_drawing_spaces();
            }

            void setDrawSpaces(bool enabled) {
                text_edit->set_draw_spaces(enabled);
            }

            bool getDrawTabs() {
                return text_edit->is_drawing_tabs();
            }

            void setDrawTabs(bool enabled) {
                text_edit->set_draw_tabs(enabled);
            }

            bool getEditable() {
                return text_edit->is_editable();
            }

            void setEditable(bool enabled) {
                text_edit->set_editable(enabled);
            }

            bool getEmojiMenuEnabled() {
                return text_edit->is_emoji_menu_enabled();
            }

            void setEmojiMenuEnabled(bool enabled) {
                text_edit->set_emoji_menu_enabled(enabled);
            }

            bool getEmptySelectionClipboardEnabled() {
                return text_edit->is_empty_selection_clipboard_enabled();
            }

            void setEmptySelectionClipboardEnabled(bool enabled) {
                text_edit->set_empty_selection_clipboard_enabled(enabled);
            }

            int getFocusMode() {
                return text_edit->get_focus_mode();
            }

            void setFocusMode(int mode) {
                text_edit->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            bool getHighlightAllOccurrences() {
                return text_edit->is_highlight_all_occurrences_enabled();
            }

            void setHighlightAllOccurrences(bool enabled) {
                text_edit->set_highlight_all_occurrences(enabled);
            }

            bool getHighlightCurrentLine() {
                return text_edit->is_highlight_current_line_enabled();
            }

            void setHighlightCurrentLine(bool enabled) {
                text_edit->set_highlight_current_line(enabled);
            }

            bool getIndentWrappedLines() {
                return text_edit->is_indent_wrapped_lines();
            }

            void setIndentWrappedLines(bool enabled) {
                text_edit->set_indent_wrapped_lines(enabled);
            }

            std::string getLanguage() {
                return String(text_edit->get_language()).utf8().get_data();
            }

            void setLanguage(std::string language) {
                text_edit->set_language(String(language.c_str()));
            }

            bool getMiddleMousePasteEnabled() {
                return text_edit->is_middle_mouse_paste_enabled();
            }
            
            void setMiddleMousePasteEnabled(bool enabled) {
                text_edit->set_middle_mouse_paste_enabled(enabled);
            }

            bool getMinimapDraw() {
                return text_edit->is_drawing_minimap();
            }

            void setMinimapDraw(bool enabled) {
                text_edit->set_draw_minimap(enabled);
            }

            int getMinimapWidth() {
                return text_edit->get_minimap_width();
            }

            void setMinimapWidth(int width) {
                text_edit->set_minimap_width(width);
            }

            int getMouseDefaultCursorShape() {
                return text_edit->get_default_cursor_shape();
            }

            void setMouseDefaultCursorShape(int shape) {
                text_edit->set_default_cursor_shape(static_cast<godot::Control::CursorShape>(shape));
            }

            std::string getPlaceholderText() {
                return String(text_edit->get_placeholder()).utf8().get_data();
            }

            void setPlaceholderText(std::string text) {
                text_edit->set_placeholder(String(text.c_str()));
            }

            bool getScrollFitContentHeight() {
                return text_edit->is_fit_content_height_enabled();
            }

            void setScrollFitContentHeight(bool enabled) {
                text_edit->set_fit_content_height_enabled(enabled);
            }

            bool getScrollFitContentWidth() {
                return text_edit->is_fit_content_width_enabled();
            }

            void setScrollFitContentWidth(bool enabled) {
                text_edit->set_fit_content_width_enabled(enabled);
            }

            int getScrollHorizontal() {
                return text_edit->get_h_scroll();
            }

            void setScrollHorizontal(int scroll) {
                text_edit->set_h_scroll(scroll);
            }

            bool getScrollPastEndOfFile() {
                return text_edit->is_scroll_past_end_of_file_enabled();
            }

            void setScrollPastEndOfFile(bool enabled) {
                text_edit->set_scroll_past_end_of_file_enabled(enabled);
            }

            bool getScrollSmooth() {
                return text_edit->is_smooth_scroll_enabled();
            }

            void setScrollSmooth(bool enabled) {
                text_edit->set_smooth_scroll_enabled(enabled);
            }

            float getScrollVSScrollSpeed() {
                return text_edit->get_v_scroll_speed();
            }

            void setScrollVSScrollSpeed(float speed) {
                text_edit->set_v_scroll_speed(speed);
            }

            float getScrollVertical() {
                return text_edit->get_v_scroll();
            }

            void setScrollVertical(float scroll) {
                text_edit->set_v_scroll(scroll);
            }

            bool getSelectingEnabled() {
                return text_edit->is_selecting_enabled();
            }

            void setSelectingEnabled(bool enabled) {
                text_edit->set_selecting_enabled(enabled);
            }

            bool getShortcutKeysEnabled() {
                return text_edit->is_shortcut_keys_enabled();
            }

            void setShortcutKeysEnabled(bool enabled) {
                text_edit->set_shortcut_keys_enabled(enabled);
            }

            int getStructuredTextBidiOverride() {
                return text_edit->get_structured_text_bidi_override();
            }

            void setStructuredTextBidiOverride(int override) {
                text_edit->set_structured_text_bidi_override(static_cast<godot::TextServer::StructuredTextParser>(override));
            }

            Array getStructuredTextBidiOverrideOptions() {
                return text_edit->get_structured_text_bidi_override_options();
            }

            void setStructuredTextBidiOverrideOptions(Array options) {
                text_edit->set_structured_text_bidi_override_options(options);
            }

            SyntaxHighlighter* getSyntaxHighlighter() {
                return new SyntaxHighlighter(text_edit->get_syntax_highlighter().ptr());
            }

            void setSyntaxHighlighter(SyntaxHighlighter* highlighter) {
                text_edit->set_syntax_highlighter(highlighter->getSyntaxHighlighter());
            }

            std::string getText() {
                return String(text_edit->get_text()).utf8().get_data();
            }

            void setText(std::string text) {
                text_edit->set_text(String(text.c_str()));
            }

            int getTextDirection() {
                return text_edit->get_text_direction();
            }

            void setTextDirection(int direction) {
                text_edit->set_text_direction(static_cast<godot::Control::TextDirection>(direction));
            }

            bool getUseCustomWordSeparators() {
                return text_edit->is_custom_word_separators_enabled();
            }

            void setUseCustomWordSeparators(bool enabled) {
                text_edit->set_use_custom_word_separators(enabled);
            }

            bool getUseDefaultWordSeparators() {
                return text_edit->is_default_word_separators_enabled();
            }

            void setUseDefaultWordSeparators(bool enabled) {
                text_edit->set_use_default_word_separators(enabled);
            }

            bool getVirtualKeyboardEnabled() {
                return text_edit->is_virtual_keyboard_enabled();
            }

            void setVirtualKeyboardEnabled(bool enabled) {
                text_edit->set_virtual_keyboard_enabled(enabled);
            }

            int getWrapMode() {
                return text_edit->get_line_wrapping_mode();
            }

            void setWrapMode(int mode) {
                text_edit->set_line_wrapping_mode(static_cast<godot::TextEdit::LineWrappingMode>(mode));
            }

            Event* caretChangedEvent;
            Event* getCaretChangedEvent() {
                return caretChangedEvent;
            }
            void setCaretChangedEvent(Event* event) {
                caretChangedEvent = event;
            }

            Event* gutterAddedEvent;
            Event* getGutterAddedEvent() {
                return gutterAddedEvent;
            }
            void setGutterAddedEvent(Event* event) {
                gutterAddedEvent = event;
            }

            Event* gutterClickedEvent;
            Event* getGutterClickedEvent() {
                return gutterClickedEvent;
            }
            void setGutterClickedEvent(Event* event) {
                gutterClickedEvent = event;
            }

            Event* gutterRemovedEvent;
            Event* getGutterRemovedEvent() {
                return gutterRemovedEvent;
            }
            void setGutterRemovedEvent(Event* event) {
                gutterRemovedEvent = event;
            }

            Event* linesEditedFromEvent;
            Event* getLinesEditedFromEvent() {
                return linesEditedFromEvent;
            }
            void setLinesEditedFromEvent(Event* event) {
                linesEditedFromEvent = event;
            }

            Event* textChangedEvent;
            Event* getTextChangedEvent() {
                return textChangedEvent;
            }
            void setTextChangedEvent(Event* event) {
                textChangedEvent = event;
            }

            Event* textSetEvent;
            Event* getTextSetEvent() {
                return textSetEvent;
            }
            void setTextSetEvent(Event* event) {
                textSetEvent = event;
            }

            void onBackspace(int caret_index) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["backspace"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, caret_index);
                    }
                }
            }

            void onCopy(int caret_index) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["copy"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, caret_index);
                    }
                }
            }

            void onCut(int caret_index) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["cut"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, caret_index);
                    }
                }
            }

            void onHandleUnicodeInput(int unicode_char, int caret_index) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["handleUnicodeInput"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, unicode_char, caret_index);
                    }
                }
            }

            void onPaste(int caret_index) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["paste"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, caret_index);
                    }
                }
            }

            void onPastePrimaryClipboard(int caret_index) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["pastePrimaryClipboard"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, caret_index);
                    }
                }
            }

            int addCaret(int line, int column) {
                return text_edit->add_caret(line, column);
            }

            void addCaretAtCarets(bool below) {
                text_edit->add_caret_at_carets(below);
            }

            void addGutter(int at = -1) {
                text_edit->add_gutter(at);
            }

            void addSelectionForNextOccurrence() {
                text_edit->add_selection_for_next_occurrence();
            }

            void adjustCaretsAfterEdit(int caret, int fromLine, int fromCol, int toLine, int toCol) {
                text_edit->adjust_carets_after_edit(caret, fromLine, fromCol, toLine, toCol);
            }

            void adjustViewportToCaret(int caret = 0) {
                text_edit->adjust_viewport_to_caret(caret);
            }

            void applyIme() {
                text_edit->apply_ime();
            }

            void backspace(int caret_index = - 1) {
                text_edit->backspace(caret_index);
            }

            void beginComplexOperation() {
                text_edit->begin_complex_operation();
            }

            void beginMulticaretEdit() {
                text_edit->begin_multicaret_edit();
            }

            void clear() {
                text_edit->clear();
            }

            void clearUndoHistory() {
                text_edit->clear_undo_history();
            }

            void collapseCarets(int fromLine, int fromCol, int toLine, int toCol, bool inclusive = false) {
                text_edit->collapse_carets(fromLine, fromCol, toLine, toCol, inclusive);
            }

            void copy(int caret = -1) {
                text_edit->copy(caret);
            }

            void cut(int caret = -1) {
                text_edit->cut(caret);
            }

            void deleteSelection(int caret = -1) {
                text_edit->delete_selection(caret);
            }

            void deselect(int caret = -1) {
                text_edit->deselect(caret);
            }

            void endAction() {
                text_edit->end_action();
            }

            void endComplexOperation() {
                text_edit->end_complex_operation();
            }

            void endMulticaretEdit() {
                text_edit->end_multicaret_edit();
            }

            int getCaretColumn(int caret = 0) {
                return text_edit->get_caret_column(caret);
            }

            int getCaretCount() {
                return text_edit->get_caret_count();
            }

            Vector2 getCaretDrawPos(int caret = 0) {
                return text_edit->get_caret_draw_pos(caret);
            }

            std::vector<int> getCaretIndexEditOrder() {
                std::vector<int> order;
                PackedInt32Array orderArray = text_edit->get_caret_index_edit_order();
                for (int i = 0; i < orderArray.size(); ++i) {
                    order.push_back(orderArray[i]);
                }
                return order;
            }

            int getCaretLine(int caret = 0) {
                return text_edit->get_caret_line(caret);
            }

            int getCaretWrapIndex(int caret = 0) {
                return text_edit->get_caret_wrap_index(caret);
            }

            int getFirstNonWhitespaceColumn(int line) {
                return text_edit->get_first_non_whitespace_column(line);
            }

            int getFirstVisibleLine() {
                return text_edit->get_first_visible_line();
            }

            int getGutterCount() {
                return text_edit->get_gutter_count();
            }

            std::string getGutterName(int gutter) {
                return String(text_edit->get_gutter_name(gutter)).utf8().get_data();
            }

            int getGutterType(int gutter) {
                return text_edit->get_gutter_type(gutter);
            }

            HScrollBar* getHScrollBar() {
                return new HScrollBar(text_edit->get_h_scroll_bar());
            }

            int getIndentLevel(int line) {
                return text_edit->get_indent_level(line);
            }

            int getLastFullVisibleLine() {
                return text_edit->get_last_full_visible_line();
            }

            int getLastFullVisibleLineWrapIndex() {
                return text_edit->get_last_full_visible_line_wrap_index();
            }

            int getLastUnhiddenLine() {
                return text_edit->get_last_unhidden_line();
            }

            std::string getLine(int line) {
                return String(text_edit->get_line(line)).utf8().get_data();
            }

            Color getLineBackgroundColor(int line) {
                return text_edit->get_line_background_color(line);
            }

            Vector2i getLineColumnAtPos(Vector2i pos, bool clampLine = true, bool clampColumn = true) {
                return text_edit->get_line_column_at_pos(pos, clampLine, clampColumn);
            }

            int getLineCount() {
                return text_edit->get_line_count();
            }

            sunaba::core::Texture2D* getLineGutterIcon(int line, int gutter) {
                return new sunaba::core::Texture2D(text_edit->get_line_gutter_icon(line, gutter).ptr());
            }

            Color getLineGutterItemColor(int line, int gutter) {
                return text_edit->get_line_gutter_item_color(line, gutter);
            }

            Variant getLineGutterMetadata(int line, int gutter) {
                return text_edit->get_line_gutter_metadata(line, gutter);
            }

            std::string getLineGutterText(int line, int gutter) {
                return String(text_edit->get_line_gutter_text(line, gutter)).utf8().get_data();
            }

            int getLineHeight() {
                return text_edit->get_line_height();
            }

            std::vector<Vector2i> getLineRangesFromCarets(bool onlySelections = false, bool mergeAdjacent = true) {
                std::vector<Vector2i> ranges;
                TypedArray<Vector2i> rangesArray = text_edit->get_line_ranges_from_carets(onlySelections, mergeAdjacent);
                for (int i = 0; i < rangesArray.size(); ++i) {
                    ranges.push_back(rangesArray[i]);
                }
                return ranges;
            }

            int getLineWidth(int line, int wrapIndex = -1) {
                return text_edit->get_line_width(line, wrapIndex);
            }

            std::string getLineWithIme(int line) {
                return String(text_edit->get_line_with_ime(line)).utf8().get_data();
            }

            int getLineWrapCount(int line) {
                return text_edit->get_line_wrap_count(line);
            }

            int getLineWrapIndexAtColumn(int line, int column) {
                return text_edit->get_line_wrap_index_at_column(line, column);
            }

            std::vector<std::string> getLineWrappedText(int line) {
                std::vector<std::string> wrappedText;
                PackedStringArray wrappedTextArray = text_edit->get_line_wrapped_text(line);
                for (int i = 0; i < wrappedTextArray.size(); ++i) {
                    wrappedText.push_back(wrappedTextArray[i].utf8().get_data());
                }
                return wrappedText;
            }

            Vector2 getLocalMousePos() {
                return text_edit->get_local_mouse_pos();
            }

            sunaba::desktop::PopupMenu* getMenu() {
                return new sunaba::desktop::PopupMenu(text_edit->get_menu());
            }

            int getMinimapLineAtPos(Vector2i pos) {
                return text_edit->get_minimap_line_at_pos(pos);
            }

            int getMinimapVisibleLines() {
                return text_edit->get_minimap_visible_lines();
            }

            Vector2i getNextVisibleLineIndexOffsetFrom(int line, int wrapIndex, int visibleAmount) {
                return text_edit->get_next_visible_line_index_offset_from(line, wrapIndex, visibleAmount);
            }
    };
}

#endif // TEXT_EDIT_H