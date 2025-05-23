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
                Dictionary delimiters = code_edit->get_auto_brace_completion_pairs();
                for (const auto& key : delimiters.keys()) {
                    String delimiter = key;
                    String comment = delimiters[key];
                    pairs.push_back(delimiter.utf8().get_data());
                    pairs.push_back(comment.utf8().get_data());
                }
                return pairs;
            }
    };
}

#endif // CODE_EDIT_H