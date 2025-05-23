#ifndef CODE_EDIT_H
#define CODE_EDIT_H

#include <godot_cpp/classes/code_edit.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define CodeEditNode godot::CodeEdit

#include "text_edit.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindCodeEdit(sol::state& lua);

    class CodeEdit;

    class CodeEditProxy : public CodeEditNode {
        public:
            sunaba::ui::CodeEdit* element = nullptr;

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

            bool _can_drop_data(const Vector2& at_position, const Variant& data) const override;

            void _drop_data(const Vector2& at_position, const Variant& data) override;

            Variant _get_drag_data(const Vector2& at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2& at_position) const override;

            void _gui_input(const Ref<InputEvent>& event) override;

            bool _has_point(const Vector2& point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array& args, const String& text) const override;

            void _backspace(int caret_index) override;

            void _copy(int caret_index) override;

            void _cut(int caret_index) override;

            void _handle_unicode_input(int unicode_char, int caret_index) override;

            void _paste(int caret_index) override;

            void _paste_primary_clipboard(int caret_index) override;

            void _confirm_code_completion(bool replace) override;

            TypedArray<Dictionary> _filter_code_completion_candidates(const TypedArray<Dictionary>& candidates) const override;
    };

    class CodeEdit : public TextEdit {
        private:
            CodeEditNode* code_edit = nullptr; // Pointer to the CodeEdit instance

            void connectCodeEditSignals() {
                // Connect signals specific to CodeEdit
                // Example: code_edit->connect("signal_name", this, "method_name");
            }

        public:
            CodeEdit() {
                setCodeEdit(memnew(CodeEditProxy));
                onInit();
            }

            CodeEdit(CodeEditNode* code_edit) {
                setCodeEdit(code_edit);
            }

            CodeEditNode* getCodeEdit() {
                return code_edit;
            }

            void setCodeEdit(CodeEditNode* code_edit) {
                this->code_edit = code_edit;
                connectCodeEditSignals();
                setTextEdit(code_edit);
            }

            void setCodeEdit(CodeEditProxy* code_edit) {
                this->code_edit = code_edit;
                code_edit->element = this;
                connectCodeEditSignals();
                setTextEdit(code_edit);
            }

            bool getAutBraceCompletionEnabled() {
                return code_edit->is_auto_brace_completion_enabled();
            }

            void setAutBraceCompletionEnabled(bool enabled) {
                code_edit->set_auto_brace_completion_enabled(enabled);
            }

            bool getAutoBraceCompletionHighlightMatching() {
                return code_edit->is_highlight_matching_braces_enabled();
            }

            void setAutoBraceCompletionHighlightMatching(bool enabled) {
                code_edit->set_highlight_matching_braces_enabled(enabled);
            }

            Dictionary getAutoBraceCompletionPairs() {
                return code_edit->get_auto_brace_completion_pairs();
            }

            void setAutoBraceCompletionPairs(const Dictionary& pairs) {
                code_edit->set_auto_brace_completion_pairs(pairs);
            }

            bool getCodeCompletionEnabled() {
                return code_edit->is_code_completion_enabled();
            }

            void setCodeCompletionEnabled(bool enabled) {
                code_edit->set_code_completion_enabled(enabled);
            }

            std::vector<std::string> getCodeCompletionPrefixes() {
                std::vector<std::string> pairs;
                TypedArray<String> prefixes = code_edit->get_auto_indent_prefixes();
                for (int i = 0; i < prefixes.size(); ++i) {
                    String prefix = prefixes[i];
                    pairs.push_back(prefix.utf8().get_data());
                }
                return pairs;
            }

            void setCodeCompletionPrefixes(const std::vector<std::string>& prefixes) {
                TypedArray<String> arr;
                for (const auto& prefix : prefixes) {
                    arr.push_back(String(prefix.c_str()));
                }
                code_edit->set_auto_indent_prefixes(arr);
            }

            std::vector<std::string> getDelimiterComments() {
                std::vector<std::string> pairs;
                auto delimiters = code_edit->get_comment_delimiters();
                for (int i = 0; i < delimiters.size(); ++i) {
                    String delimiter = delimiters[i];
                    pairs.push_back(delimiter.utf8().get_data());
                }
                return pairs;
            }

            void setDelimiterComments(const std::vector<std::string>& delimiters) {
                TypedArray<String> arr;
                for (const auto& delimiter : delimiters) {
                    arr.push_back(String(delimiter.c_str()));
                }
                code_edit->set_comment_delimiters(arr);
            }

            std::vector<std::string> getDelimiterStrings() {
                std::vector<std::string> pairs;
                auto delimiters = code_edit->get_string_delimiters();
                for (int i = 0; i < delimiters.size(); ++i) {
                    String delimiter = delimiters[i];
                    pairs.push_back(delimiter.utf8().get_data());
                }
                return pairs;
            }

            void setDelimiterStrings(const std::vector<std::string>& delimiters) {
                TypedArray<String> arr;
                for (const auto& delimiter : delimiters) {
                    arr.push_back(String(delimiter.c_str()));
                }
                code_edit->set_string_delimiters(arr);
            }

            bool getGuttersDrawBookmarks() {
                return code_edit->is_drawing_bookmarks_gutter();
            }

            void setGuttersDrawBookmarks(bool enabled) {
                code_edit->set_draw_bookmarks_gutter(enabled);
            }

            bool getGuttersDrawBreakpointsGutter() {
                return code_edit->is_drawing_breakpoints_gutter();
            }

            void setGuttersDrawBreakpointsGutter(bool enabled) {
                code_edit->set_draw_breakpoints_gutter(enabled);
            }

            bool getGuttersDrawExecutingLines() {
                return code_edit->is_drawing_executing_lines_gutter();
            }

            void setGuttersDrawExecutingLines(bool enabled) {
                code_edit->set_draw_executing_lines_gutter(enabled);
            }

            bool getGuttersDrawFoldGutter() {
                return code_edit->is_drawing_fold_gutter();
            }

            void setGuttersDrawFoldGutter(bool enabled) {
                code_edit->set_draw_fold_gutter(enabled);
            }

            bool getGuttersDrawLineNumbers() {
                return code_edit->is_draw_line_numbers_enabled();
            }

            void setGuttersDrawLineNumbers(bool enabled) {
                code_edit->set_draw_line_numbers(enabled);
            }

            bool getGuttersZeroPadLineNumbers() {
                return code_edit->is_line_numbers_zero_padded();
            }

            void setGuttersZeroPadLineNumbers(bool enabled) {
                code_edit->set_line_numbers_zero_padded(enabled);
            }

            bool getIndentAutomatic() {
                return code_edit->is_auto_indent_enabled();
            }

            void setIndentAutomatic(bool enabled) {
                code_edit->set_auto_indent_enabled(enabled);
            }

            std::vector<std::string> getIndentAutomaticPrefixes() {
                std::vector<std::string> pairs;
                TypedArray<String> prefixes = code_edit->get_auto_indent_prefixes();
                for (int i = 0; i < prefixes.size(); ++i) {
                    String prefix = prefixes[i];
                    pairs.push_back(prefix.utf8().get_data());
                }
                return pairs;
            }

            void setIndentAutomaticPrefixes(const std::vector<std::string>& prefixes) {
                TypedArray<String> arr;
                for (const auto& prefix : prefixes) {
                    arr.push_back(String(prefix.c_str()));
                }
                code_edit->set_auto_indent_prefixes(arr);
            }

            int getIndentSize() {
                return code_edit->get_indent_size();
            }

            void setIndentSize(int size) {
                code_edit->set_indent_size(size);
            }

            bool getIndentUseSpaces() {
                return code_edit->is_indent_using_spaces();
            }

            void setIndentUseSpaces(bool use_spaces) {
                code_edit->set_indent_using_spaces(use_spaces);
            }

            int getLayoutDirection() {
                return code_edit->get_layout_direction();
            }

            void setLayoutDirection(int direction) {
                code_edit->set_layout_direction(static_cast<godot::Control::LayoutDirection>(direction));
            }

            bool getLineFolding() {
                return code_edit->is_line_folding_enabled();
            }

            void setLineFolding(bool enabled) {
                code_edit->set_line_folding_enabled(enabled);
            }

            std::vector<int> getLineLengthGuidelines() {
                std::vector<int> lines;
                PackedInt32Array guidelines = code_edit->get_line_length_guidelines();
                for (int i = 0; i < guidelines.size(); ++i) {
                    int line = guidelines[i];
                    lines.push_back(line);
                }
                return lines;
            }

            void setLineLengthGuidelines(const std::vector<int>& lines) {
                PackedInt32Array arr;
                for (const auto& line : lines) {
                    arr.push_back(line);
                }
                code_edit->set_line_length_guidelines(arr);
            }
    };
}

#endif // CODE_EDIT_H