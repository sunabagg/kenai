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
                SignalFunc breakpointToggledFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->breakpointToggledEvent != nullptr) {
                        this->breakpointToggledEvent->emit(args);
                    }
                    return Variant();
                };
                Callable breakpointToggledCallable = StlFunctionWrapper::create_callable_from_cpp_function(breakpointToggledFunc);
                code_edit->connect("breakpoint_toggled", breakpointToggledCallable);
                SignalFunc codeCompletionRequestedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->codeCompletionRequestedEvent != nullptr) {
                        this->codeCompletionRequestedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable codeCompletionRequestedCallable = StlFunctionWrapper::create_callable_from_cpp_function(codeCompletionRequestedFunc);
                code_edit->connect("code_completion_requested", codeCompletionRequestedCallable);
                SignalFunc SymbolHoveredFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->symbolHoveredEvent != nullptr) {
                        this->symbolHoveredEvent->emit(args);
                    }
                    return Variant();
                };
                Callable symbolHoveredCallable = StlFunctionWrapper::create_callable_from_cpp_function(SymbolHoveredFunc);
                code_edit->connect("symbol_hovered", symbolHoveredCallable);
                SignalFunc symbolLookupFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->symbolLookupEvent != nullptr) {
                        this->symbolLookupEvent->emit(args);
                    }
                    return Variant();
                };
                Callable symbolLookupCallable = StlFunctionWrapper::create_callable_from_cpp_function(symbolLookupFunc);
                code_edit->connect("symbol_lookup", symbolLookupCallable);
                SignalFunc symbolValidateFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->symbolValidateEvent != nullptr) {
                        this->symbolValidateEvent->emit(args);
                    }
                    return Variant();
                };
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

            bool getAutoBraceCompletionEnabled() {
                return code_edit->is_auto_brace_completion_enabled();
            }

            void setAutoBraceCompletionEnabled(bool enabled) {
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
                TypedArray<int> arr;
                for (const auto& line : lines) {
                    arr.push_back(line);
                }
                code_edit->set_line_length_guidelines(arr);
            }

            bool getSymbolLookupOnClick() {
                return code_edit->is_symbol_lookup_on_click_enabled();
            }

            void setSymbolLookupOnClick(bool enabled) {
                code_edit->set_symbol_lookup_on_click_enabled(enabled);
            }

            bool getSymbolTooltipOnHover() {
                return code_edit->is_symbol_tooltip_on_hover_enabled();
            }

            void setSymbolTooltipOnHover(bool enabled) {
                code_edit->set_symbol_tooltip_on_hover_enabled(enabled);
            }

            int getTextDirection() {
                return code_edit->get_text_direction();
            }

            void setTextDirection(int direction) {
                code_edit->set_text_direction(static_cast<godot::Control::TextDirection>(direction));
            }

            Event* breakpointToggledEvent;
            Event* getBreakpointToggledEvent() {
                return breakpointToggledEvent;
            }
            void setBreakpointToggledEvent(Event* event) {
                breakpointToggledEvent = event;
            }
            Event* codeCompletionRequestedEvent;
            Event* getCodeCompletionRequestedEvent() {
                return codeCompletionRequestedEvent;
            }
            void setCodeCompletionRequestedEvent(Event* event) {
                codeCompletionRequestedEvent = event;
            }
            Event* symbolHoveredEvent;
            Event* getSymbolHoveredEvent() {
                return symbolHoveredEvent;
            }
            void setSymbolHoveredEvent(Event* event) {
                symbolHoveredEvent = event;
            }
            Event* symbolLookupEvent;
            Event* getSymbolLookupEvent() {
                return symbolLookupEvent;
            }
            void setSymbolLookupEvent(Event* event) {
                symbolLookupEvent = event;
            }
            Event* symbolValidateEvent;
            Event* getSymbolValidateEvent() {
                return symbolValidateEvent;
            }
            void setSymbolValidateEvent(Event* event) {
                symbolValidateEvent = event;
            }

            void onConfirmCodeCompletion() {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["confirm_code_completion"].get<sol::function>();
                    if (func) {
                        func(scriptInstance);
                    }
                }
            }

            Dictionary onFilterCodeCompletionCandidates(const TypedArray<Dictionary>& candidates) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["filter_code_completion_candidates"].get<sol::function>();
                    if (func) {
                        Array candidatesArray;
                        for (int i = 0; i < candidates.size(); ++i) {
                            Dictionary candidate = candidates[i];
                            candidatesArray.append(candidate);
                        }
                        return func(scriptInstance, candidatesArray);
                    }
                }
                return Dictionary();
            }

            void addAutoBraceCompletionPair(const std::string& startKey, const std::string& endKey) {
                code_edit->add_auto_brace_completion_pair(String(startKey.c_str()), String(endKey.c_str()));
            }

            void addCodeCompletionOption(int type, const std::string& displayText, const std::string& insertText, const Color textColor, sunaba::core::Resource* icon = nullptr, Variant value = Variant(), int location = 1024) {
                Ref<godot::Resource> iconRef;
                if (icon != nullptr) {
                    iconRef = Ref<godot::Resource>(icon->getResource());
                }
                else {
                    iconRef = Ref<godot::Resource>();
                }
                code_edit->add_code_completion_option(static_cast<CodeEditNode::CodeCompletionKind>(type), String(displayText.c_str()), String(insertText.c_str()), textColor, iconRef, value, location);
            }

            void addCommentDelimiter(const std::string& startKey, const std::string& endKey, bool lineOnly = false) {
                code_edit->add_comment_delimiter(String(startKey.c_str()), String(endKey.c_str()), lineOnly);
            }

            void addStringDelimiter(const std::string& startKey, const std::string& endKey, bool lineOnly = false) {
                code_edit->add_string_delimiter(String(startKey.c_str()), String(endKey.c_str()), lineOnly);
            }

            bool canFoldLine(int line) {
                return code_edit->can_fold_line(line);
            }

            void cancelCodeCompletion() {
                code_edit->cancel_code_completion();
            }

            void clearBookmarkedLines() {
                code_edit->clear_bookmarked_lines();
            }

            void clearBreakpointedLines() {
                code_edit->clear_breakpointed_lines();
            }

            void clearCommentDelimiters() {
                code_edit->clear_comment_delimiters();
            }

            void clearExecutingLines() {
                code_edit->clear_executing_lines();
            }

            void clearStringDelimiters() {
                code_edit->clear_string_delimiters();
            }

            void confirmCodeCompletion() {
                code_edit->confirm_code_completion();
            }

            void convertIndent(int fromLine = -1, int toLine = -1) {
                code_edit->convert_indent(fromLine, toLine);
            }

            void createCodeRegion() {
                code_edit->create_code_region();
            }

            void deleteLines() {
                code_edit->delete_lines();
            }

            void doIndent() {
                code_edit->do_indent();
            }

            void duplicateLines() {
                code_edit->duplicate_lines();
            }

            void duplicateSelection() {
                code_edit->duplicate_selection();
            }

            void foldAllLines() {
                code_edit->fold_all_lines();
            }

            void foldLine(int line) {
                code_edit->fold_line(line);
            }

            std::string getAutoBraceCompletionCloseKey(const std::string& openKey) {
                return code_edit->get_auto_brace_completion_close_key(String(openKey.c_str())).utf8().get_data();
            }

            std::vector<int> getBookmarkedLines() {
                std::vector<int> lines;
                PackedInt32Array bookmarks = code_edit->get_bookmarked_lines();
                for (int i = 0; i < bookmarks.size(); ++i) {
                    int line = bookmarks[i];
                    lines.push_back(line);
                }
                return lines;
            }

            std::vector<int> getBreakpointedLines() {
                std::vector<int> lines;
                PackedInt32Array breakpoints = code_edit->get_breakpointed_lines();
                for (int i = 0; i < breakpoints.size(); ++i) {
                    int line = breakpoints[i];
                    lines.push_back(line);
                }
                return lines;
            }

            Dictionary getCodeCompletionOption(int index) {
                return code_edit->get_code_completion_option(index);
            }

            std::vector<Dictionary> getCodeCompletionOptions() {
                std::vector<Dictionary> options;
                Array codeCompletionOptions = code_edit->get_code_completion_options();
                for (int i = 0; i < codeCompletionOptions.size(); ++i) {
                    Dictionary option = codeCompletionOptions[i];
                    options.push_back(option);
                }
                return options;
            }

            int getCodeCompletionSelectedIndex() {
                return code_edit->get_code_completion_selected_index();
            }

            std::string getCodeRegionEndTag() {
                return code_edit->get_code_region_end_tag().utf8().get_data();
            }

            std::string getCodeRegionStartTag() {
                return code_edit->get_code_region_start_tag().utf8().get_data();
            }

            std::string getDelimiterEndKey(int delimiterIndex) {
                return code_edit->get_delimiter_end_key(delimiterIndex).utf8().get_data();
            }

            Vector2 getDelimiterEndPosition(int line, int column) {
                return code_edit->get_delimiter_end_position(line, column);
            }

            std::string getDelimiterStartKey(int delimiterIndex) {
                return code_edit->get_delimiter_start_key(delimiterIndex).utf8().get_data();
            }

            Vector2 getDelimiterStartPosition(int line, int column) {
                return code_edit->get_delimiter_start_position(line, column);
            }

            std::vector<int> getExecutingLines() {
                std::vector<int> lines;
                PackedInt32Array executingLines = code_edit->get_executing_lines();
                for (int i = 0; i < executingLines.size(); ++i) {
                    int line = executingLines[i];
                    lines.push_back(line);
                }
                return lines;
            }

            std::vector<int> getFoldedLines() {
                std::vector<int> lines;
                PackedInt32Array foldedLines = code_edit->get_folded_lines();
                for (int i = 0; i < foldedLines.size(); ++i) {
                    int line = foldedLines[i];
                    lines.push_back(line);
                }
                return lines;
            }

            std::string getTextForCodeCompletion() {
                return code_edit->get_text_for_code_completion().utf8().get_data();
            }

            std::string getTextForSymbolLookup() {
                return code_edit->get_text_for_symbol_lookup().utf8().get_data();
            }

            std::string getTextWithCursorChar(int line, int column) {
                return code_edit->get_text_with_cursor_char(line, column).utf8().get_data();
            }

            bool hasAutoBraceCompletionCloseKey(const std::string& openKey) {
                return code_edit->has_auto_brace_completion_close_key(String(openKey.c_str()));
            }

            bool hasAutoBraceCompletionOpenKey(const std::string& openKey) {
                return code_edit->has_auto_brace_completion_open_key(String(openKey.c_str()));
            }

            bool hasCommentDelimiter(const std::string& startKey) {
                return code_edit->has_comment_delimiter(String(startKey.c_str()));
            }

            bool hasStringDelimiter(const std::string& startKey, const std::string& endKey) {
                return code_edit->has_string_delimiter(String(startKey.c_str()));
            }

            void indentLines() {
                code_edit->indent_lines();
            }

            int isInComment(int line, int column = -1) {
                return code_edit->is_in_comment(line, column);
            }

            int isInString(int line, int column = -1) {
                return code_edit->is_in_string(line, column);
            }

            bool isLineBookmarked(int line) {
                return code_edit->is_line_bookmarked(line);
            }

            bool isLineBreakpointed(int line) {
                return code_edit->is_line_breakpointed(line);
            }

            bool isLineCodeRegionEnd(int line) {
                return code_edit->is_line_code_region_end(line);
            }

            bool isLineCodeRegionStart(int line) {
                return code_edit->is_line_code_region_start(line);
            }

            bool isLineExecuting(int line) {
                return code_edit->is_line_executing(line);
            }

            bool isLineFolded(int line) {
                return code_edit->is_line_folded(line);
            }

            void moveLinesDown() {
                code_edit->move_lines_down();
            }

            void moveLinesUp() {
                code_edit->move_lines_up();
            }

            void removeCommentDelimiter(const std::string& startKey) {
                code_edit->remove_comment_delimiter(String(startKey.c_str()));
            }

            void removeStringDelimiter(const std::string& startKey) {
                code_edit->remove_string_delimiter(String(startKey.c_str()));
            }

            void requestCodeCompletion() {
                code_edit->request_code_completion();
            }

            void setCodeCompletionSelectedIndex(int index) {
                code_edit->set_code_completion_selected_index(index);
            }

            void setCodeHint(const std::string& hint) {
                code_edit->set_code_hint(String(hint.c_str()));
            }

            void setCodeHintDrawBelow(bool drawBelow) {
                code_edit->set_code_hint_draw_below(drawBelow);
            }

            void setCodeRegionTags(const std::string& startTag = "&quot;region&quot;", const std::string& endTag = "&quot;endregion&quot;") {
                code_edit->set_code_region_tags(String(startTag.c_str()), String(endTag.c_str()));
            }

            void setLineAsBookmarked(int line, bool bookmarked) {
                code_edit->set_line_as_bookmarked(line, bookmarked);
            }

            void setLineAsBreakpoint(int line, bool breakpointed) {
                code_edit->set_line_as_breakpoint(line, breakpointed);
            }

            void setLineAsExecuting(int line, bool executing) {
                code_edit->set_line_as_executing(line, executing);
            }

            void setSymbolLookupWordAsValid(bool valid) {
                code_edit->set_symbol_lookup_word_as_valid(valid);
            }

            void toggleFoldableLine(int line) {
                code_edit->toggle_foldable_line(line);
            }

            void toggleFoldableLinesAtCarets() {
                code_edit->toggle_foldable_lines_at_carets();
            }

            void unfoldAllLines() {
                code_edit->unfold_all_lines();
            }

            void unfoldLine(int line) {
                code_edit->unfold_line(line);
            }

            void unindentLines() {
                code_edit->unindent_lines();
            }

            void updateCodeCompletionOptions(bool force) {
                code_edit->update_code_completion_options(force);
            }
    };
}

#endif // CODE_EDIT_H