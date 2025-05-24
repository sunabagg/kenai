#include "code_edit.h"

namespace sunaba::ui {
    void CodeEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void CodeEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void CodeEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void CodeEditProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void CodeEditProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void CodeEditProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void CodeEditProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void CodeEditProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void CodeEditProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void CodeEditProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool CodeEditProxy::_can_drop_data(const Vector2& at_position, const Variant& data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void CodeEditProxy::_drop_data(const Vector2& at_position, const Variant& data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant CodeEditProxy::_get_drag_data(const Vector2& at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 CodeEditProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

    String CodeEditProxy::_get_tooltip(const Vector2& at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void CodeEditProxy::_gui_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool CodeEditProxy::_has_point(const Vector2& point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> CodeEditProxy::_structured_text_parser(const Array& args, const String& text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void CodeEditProxy::_backspace(int caret_index) {
        if (this->element != nullptr) {
            this->element->onBackspace(caret_index);
        }
    }

    void CodeEditProxy::_copy(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCopy(caret_index);
        }
    }

    void CodeEditProxy::_cut(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCut(caret_index);
        }
    }

    void CodeEditProxy::_handle_unicode_input(int unicode_char, int caret_index) {
        if (this->element != nullptr) {
            this->element->onHandleUnicodeInput(unicode_char, caret_index);
        }
    }

    void CodeEditProxy::_paste(int caret_index) {
        if (this->element != nullptr) {
            this->element->onPaste(caret_index);
        }
    }

    void CodeEditProxy::_paste_primary_clipboard(int caret_index) {
        if (this->element != nullptr) {
            this->element->onPastePrimaryClipboard(caret_index);
        }
    }

    void bindCodeEdit(sol::state& lua) {
        lua.new_usertype<CodeEdit>("CodeEdit",
            sol::constructors<CodeEdit()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control, TextEdit>(),
            "autoBraceCompletionEnabled", sol::property(
                &CodeEdit::getAutoBraceCompletionEnabled,
                &CodeEdit::setAutoBraceCompletionEnabled
            ),
            "autoBraceCompletionHighlightMatching", sol::property(
                &CodeEdit::getAutoBraceCompletionHighlightMatching,
                &CodeEdit::setAutoBraceCompletionHighlightMatching
            ),
            "autoBraceCompletionPairs", sol::property(
                &CodeEdit::getAutoBraceCompletionPairs,
                &CodeEdit::setAutoBraceCompletionPairs
            ),
            "codeCompletionEnabled", sol::property(
                &CodeEdit::getCodeCompletionEnabled,
                &CodeEdit::setCodeCompletionEnabled
            ),
            "codeCompletionPrefixes", sol::property(
                &CodeEdit::getCodeCompletionPrefixes,
                &CodeEdit::setCodeCompletionPrefixes
            ),
            "delimiterComments", sol::property(
                &CodeEdit::getDelimiterComments,
                &CodeEdit::setDelimiterComments
            ),
            "delimiterStrings", sol::property(
                &CodeEdit::getDelimiterStrings,
                &CodeEdit::setDelimiterStrings
            ),
            "guttersDrawBookmarks", sol::property(
                &CodeEdit::getGuttersDrawBookmarks,
                &CodeEdit::setGuttersDrawBookmarks
            ),
            "guttersDrawBreakpointsGutter", sol::property(
                &CodeEdit::getGuttersDrawBreakpointsGutter,
                &CodeEdit::setGuttersDrawBreakpointsGutter
            ),
            "guttersDrawExecutingLines", sol::property(
                &CodeEdit::getGuttersDrawExecutingLines,
                &CodeEdit::setGuttersDrawExecutingLines
            ),
            "guttersDrawFoldGutter", sol::property(
                &CodeEdit::getGuttersDrawFoldGutter,
                &CodeEdit::setGuttersDrawFoldGutter
            ),
            "guttersDrawLineNumbers", sol::property(
                &CodeEdit::getGuttersDrawLineNumbers,
                &CodeEdit::setGuttersDrawLineNumbers
            ),
            "guttersZeroPadLineNumbers", sol::property(
                &CodeEdit::getGuttersZeroPadLineNumbers,
                &CodeEdit::setGuttersZeroPadLineNumbers
            ),
            "indentAutomatic", sol::property(
                &CodeEdit::getIndentAutomatic,
                &CodeEdit::setIndentAutomatic
            ),
            "indentAutomaticPrefixes", sol::property(
                &CodeEdit::getIndentAutomaticPrefixes,
                &CodeEdit::setIndentAutomaticPrefixes
            ),
            "indentSize", sol::property(
                &CodeEdit::getIndentSize,
                &CodeEdit::setIndentSize
            ),
            "indentUseSpaces", sol::property(
                &CodeEdit::getIndentUseSpaces,
                &CodeEdit::setIndentUseSpaces
            ),
            "layoutDirection", sol::property(
                &CodeEdit::getLayoutDirection,
                &CodeEdit::setLayoutDirection
            ),
            "lineFolding", sol::property(
                &CodeEdit::getLineFolding,
                &CodeEdit::setLineFolding
            ),
            "lineLengthGuidelines", sol::property(
                &CodeEdit::getLineLengthGuidelines,
                &CodeEdit::setLineLengthGuidelines
            ),
            "symbolLookupOnClick", sol::property(
                &CodeEdit::getSymbolLookupOnClick,
                &CodeEdit::setSymbolLookupOnClick
            ),
            "symbolTooltipOnHover", sol::property(
                &CodeEdit::getSymbolTooltipOnHover,
                &CodeEdit::setSymbolTooltipOnHover
            ),
            "textDirection", sol::property(
                &CodeEdit::getTextDirection,
                &CodeEdit::setTextDirection
            ),
            "breakpointToggled", sol::property(
                &CodeEdit::getBreakpointToggledEvent,
                &CodeEdit::setBreakpointToggledEvent
            ),
            "codeCompletionRequested", sol::property(
                &CodeEdit::getCodeCompletionRequestedEvent,
                &CodeEdit::setCodeCompletionRequestedEvent
            ),
            "symbolHovered", sol::property(
                &CodeEdit::getSymbolHoveredEvent,
                &CodeEdit::setSymbolHoveredEvent
            ),
            "symbolLookup", sol::property(
                &CodeEdit::getSymbolLookupEvent,
                &CodeEdit::setSymbolLookupEvent
            ),
            "symbolValidate", sol::property(
                &CodeEdit::getSymbolValidateEvent,
                &CodeEdit::setSymbolValidateEvent
            ),
            "addAutoBraceCompletionPair", &CodeEdit::addAutoBraceCompletionPair,
            "addCodeCompletionOption", &CodeEdit::addCodeCompletionOption,
            "addCommentDelimiter", &CodeEdit::addCommentDelimiter,
            "addStringDelimiter", &CodeEdit::addStringDelimiter,
            "canFoldLine", &CodeEdit::canFoldLine,
            "cancelCodeCompletion", &CodeEdit::cancelCodeCompletion,
            "clearBookmarkedLines", &CodeEdit::clearBookmarkedLines,
            "clearBreakpointedLines", &CodeEdit::clearBreakpointedLines,
            "clearCommentDelimiters", &CodeEdit::clearCommentDelimiters,
            "clearExecutingLines", &CodeEdit::clearExecutingLines,
            "clearStringDelimiters", &CodeEdit::clearStringDelimiters,
            "confirmCodeCompletion", &CodeEdit::confirmCodeCompletion,
            "convertIndent", &CodeEdit::convertIndent,
            "createCodeRegion", &CodeEdit::createCodeRegion,
            "deleteLines", &CodeEdit::deleteLines,
            "doIndent", &CodeEdit::doIndent,
            "duplicateLines", &CodeEdit::duplicateLines,
            "duplicateSelection", &CodeEdit::duplicateSelection,
            "foldAllLines", &CodeEdit::foldAllLines,
            "foldLine", &CodeEdit::foldLine,
            "getAutoBraceCompletionCloseKey", &CodeEdit::getAutoBraceCompletionCloseKey,
            "getBookmarkedLines", &CodeEdit::getBookmarkedLines,
            "getBreakpointedLines", &CodeEdit::getBreakpointedLines,
            "getCodeCompletionOption", &CodeEdit::getCodeCompletionOption,
            "getCodeCompletionOptions", &CodeEdit::getCodeCompletionOptions,
            "getCodeCompletionSelectedIndex", &CodeEdit::getCodeCompletionSelectedIndex,
            "getCodeRegionEndTag", &CodeEdit::getCodeRegionEndTag,
            "getCodeRegionStartTag", &CodeEdit::getCodeRegionStartTag,
            "getDelimiterEndKey", &CodeEdit::getDelimiterEndKey,
            "getDelimiterEndPosition", &CodeEdit::getDelimiterEndPosition,
            "getDelimiterStartKey", &CodeEdit::getDelimiterStartKey,
            "getDelimiterStartPosition", &CodeEdit::getDelimiterStartPosition,
            "getExecutingLines", &CodeEdit::getExecutingLines,
            "getFoldedLines", &CodeEdit::getFoldedLines,
            "getTextForCodeCompletion", &CodeEdit::getTextForCodeCompletion,
            "getTextForSymbolLookup", &CodeEdit::getTextForSymbolLookup,
            "getTextWithCursorChar", &CodeEdit::getTextWithCursorChar,
            "hasAutoBraceCompletionCloseKey", &CodeEdit::hasAutoBraceCompletionCloseKey,
            "hasAutoBraceCompletionOpenKey", &CodeEdit::hasAutoBraceCompletionOpenKey,
            "hasCommentDelimiter", &CodeEdit::hasCommentDelimiter,
            "hasStringDelimiter", &CodeEdit::hasStringDelimiter,
            "indentLines", &CodeEdit::indentLines,
            "isInComment", &CodeEdit::isInComment,
            "isInString", &CodeEdit::isInString,
            "isLineBookmarked", &CodeEdit::isLineBookmarked,
            "isLineBreakpointed", &CodeEdit::isLineBreakpointed,
            "isLineCodeRegionEnd", &CodeEdit::isLineCodeRegionEnd,
            "isLineCodeRegionStart", &CodeEdit::isLineCodeRegionStart,
            "isLineExecuting", &CodeEdit::isLineExecuting,
            "isLineFolded", &CodeEdit::isLineFolded,
            "moveLinesDown", &CodeEdit::moveLinesDown,
            "removeCommentDelimiter", &CodeEdit::removeCommentDelimiter,
            "removeStringDelimiter", &CodeEdit::removeStringDelimiter,
            "requestCodeCompletion", &CodeEdit::requestCodeCompletion,
            "setCodeCompletionSelectedIndex", &CodeEdit::setCodeCompletionSelectedIndex,
            "setCodeHint", &CodeEdit::setCodeHint,
            "setCodeHintDrawBelow", &CodeEdit::setCodeHintDrawBelow,
            "setCodeRegionTags", &CodeEdit::setCodeRegionTags,
            "setLineAsBookmarked", &CodeEdit::setLineAsBookmarked,
            "setLineAsBreakpoint", &CodeEdit::setLineAsBreakpoint,
            "setLineAsExecuting", &CodeEdit::setLineAsExecuting,
            "setSymbolLookupWordAsValid", &CodeEdit::setSymbolLookupWordAsValid,
            "toggleFoldableLine", &CodeEdit::toggleFoldableLine,
            "toggleFoldableLinesAtCarets", &CodeEdit::toggleFoldableLinesAtCarets,
            "unfoldAllLines", &CodeEdit::unfoldAllLines,
            "unfoldLine", &CodeEdit::unfoldLine,
            "unindentLines", &CodeEdit::unindentLines,
            "updateCodeCompletionOptions", &CodeEdit::updateCodeCompletionOptions,
            "cast", [](Element* element) {
                CodeEditNode* code_edit = Object::cast_to<CodeEditNode>(element->getNode());
                return new CodeEdit(code_edit);
            }
        );
    }
}