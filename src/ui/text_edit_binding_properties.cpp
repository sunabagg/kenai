#include "text_edit.h"

namespace sunaba::ui {
    void bindTextEditProperties(sol::usertype<TextEdit>& ut) {
        ut["autowrapMode"] = sol::property(
            &TextEdit::getAutowrapMode,
            &TextEdit::setAutowrapMode
        );
        ut["caretBlink"] = sol::property(
            &TextEdit::getCaretBlink,
            &TextEdit::setCaretBlink
        );
        ut["caretBlinkInterval"] = sol::property(
            &TextEdit::getCaretBlinkInterval,
            &TextEdit::setCaretBlinkInterval
        );
        ut["caretDrawWhenEditableDisabled"] = sol::property(
            &TextEdit::getCaretDrawWhenEditableDisabled,
            &TextEdit::setCaretDrawWhenEditableDisabled
        );
        ut["caretMidGrapheme"] = sol::property(
            &TextEdit::getCaretMidGrapheme,
            &TextEdit::setCaretMidGrapheme
        );
        ut["caretMoveOnRightClick"] = sol::property(
            &TextEdit::getCaretMoveOnRightClick,
            &TextEdit::setCaretMoveOnRightClick
        );
        ut["caretMultiple"] = sol::property(
            &TextEdit::getCaretMultiple,
            &TextEdit::setCaretMultiple
        );
        ut["caretType"] = sol::property(
            &TextEdit::getCaretType,
            &TextEdit::setCaretType
        );
        ut["clipContents"] = sol::property(
            &TextEdit::getClipContents,
            &TextEdit::setClipContents
        );
        ut["contextMenuEnabled"] = sol::property(
            &TextEdit::getContextMenuEnabled,
            &TextEdit::setContextMenuEnabled
        );
        ut["customWordSeparators"] = sol::property(
            &TextEdit::getCustomWordSeparators,
            &TextEdit::setCustomWordSeparators
        );
        ut["deselectOnFocusLossEnabled"] = sol::property(
            &TextEdit::getDeselectOnFocusLossEnabled,
            &TextEdit::setDeselectOnFocusLossEnabled
        );
        ut["dragAndDropSelectionEnabled"] = sol::property(
            &TextEdit::getDragAndDropSelectionEnabled,
            &TextEdit::setDragAndDropSelectionEnabled
        );
        ut["drawControlChars"] = sol::property(
            &TextEdit::getDrawControlChars,
            &TextEdit::setDrawControlChars
        );
        ut["drawSpaces"] = sol::property(
            &TextEdit::getDrawSpaces,
            &TextEdit::setDrawSpaces
        );
        ut["drawTabs"] = sol::property(
            &TextEdit::getDrawTabs,
            &TextEdit::setDrawTabs
        );
        ut["editable"] = sol::property(
            &TextEdit::getEditable,
            &TextEdit::setEditable
        );
        ut["emojiMenuEnabled"] = sol::property(
            &TextEdit::getEmojiMenuEnabled,
            &TextEdit::setEmojiMenuEnabled
        );
        ut["emptySelectionClipboardEnabled"] = sol::property(
            &TextEdit::getEmptySelectionClipboardEnabled,
            &TextEdit::setEmptySelectionClipboardEnabled
        );
        ut["focusMode"] = sol::property(
            &TextEdit::getFocusMode,
            &TextEdit::setFocusMode
        );
        ut["highlightAllOccurrences"] = sol::property(
            &TextEdit::getHighlightAllOccurrences,
            &TextEdit::setHighlightAllOccurrences
        );
        ut["highlightCurrentLine"] = sol::property(
            &TextEdit::getHighlightCurrentLine,
            &TextEdit::setHighlightCurrentLine
        );
        ut["indentWrappedLines"] = sol::property(
            &TextEdit::getIndentWrappedLines,
            &TextEdit::setIndentWrappedLines
        );
        ut["language"] = sol::property(
            &TextEdit::getLanguage,
            &TextEdit::setLanguage
        );
        ut["middleMousePasteEnabled"] = sol::property(
            &TextEdit::getMiddleMousePasteEnabled,
            &TextEdit::setMiddleMousePasteEnabled
        );
        ut["minimapDraw"] = sol::property(
            &TextEdit::getMinimapDraw,
            &TextEdit::setMinimapDraw
        );
        ut["minimapWidth"] = sol::property(
            &TextEdit::getMinimapWidth,
            &TextEdit::setMinimapWidth
        );
        ut["mouseDefaultCursorShape"] = sol::property(
            &TextEdit::getMouseDefaultCursorShape,
            &TextEdit::setMouseDefaultCursorShape
        );
        ut["placeholderText"] = sol::property(
            &TextEdit::getPlaceholderText,
            &TextEdit::setPlaceholderText
        );
        ut["scrollFitContentHeight"] = sol::property(
            &TextEdit::getScrollFitContentHeight,
            &TextEdit::setScrollFitContentHeight
        );
        ut["scrollFitContentWidth"] = sol::property(
            &TextEdit::getScrollFitContentWidth,
            &TextEdit::setScrollFitContentWidth
        );
        ut["scrollHorizontal"] = sol::property(
            &TextEdit::getScrollHorizontal,
            &TextEdit::setScrollHorizontal
        );
        ut["scrollPastEndOfFile"] = sol::property(
            &TextEdit::getScrollPastEndOfFile,
            &TextEdit::setScrollPastEndOfFile
        );
        ut["scrollSmooth"] = sol::property(
            &TextEdit::getScrollSmooth,
            &TextEdit::setScrollSmooth
        );
        ut["scrollVScrollSpeed"] = sol::property(
            &TextEdit::getScrollVScrollSpeed,
            &TextEdit::setScrollVScrollSpeed
        );
        ut["scrollVertical"] = sol::property(
            &TextEdit::getScrollVertical,
            &TextEdit::setScrollVertical
        );
        ut["selectingEnabled"] = sol::property(
            &TextEdit::getSelectingEnabled,
            &TextEdit::setSelectingEnabled
        );
        ut["shortcutKeysEnabled"] = sol::property(
            &TextEdit::getShortcutKeysEnabled,
            &TextEdit::setShortcutKeysEnabled
        );
        ut["structuredTextBidiOverride"] = sol::property(
            &TextEdit::getStructuredTextBidiOverride,
            &TextEdit::setStructuredTextBidiOverride
        );
        ut["structuredTextBidiOverrideOptions"] = sol::property(
            &TextEdit::getStructuredTextBidiOverrideOptions,
            &TextEdit::setStructuredTextBidiOverrideOptions
        );
        ut["syntaxHighlighter"] = sol::property(
            &TextEdit::getSyntaxHighlighter,
            &TextEdit::setSyntaxHighlighter
        );
        ut["text"] = sol::property(
            &TextEdit::getText,
            &TextEdit::setText
        );
        ut["textDirection"] = sol::property(
            &TextEdit::getTextDirection,
            &TextEdit::setTextDirection
        );
        ut["useCustomWordSeparators"] = sol::property(
            &TextEdit::getUseCustomWordSeparators,
            &TextEdit::setUseCustomWordSeparators
        );
        ut["useDefaultWordSeparators"] = sol::property(
            &TextEdit::getUseDefaultWordSeparators,
            &TextEdit::setUseDefaultWordSeparators
        );
        ut["virtualKeyboardEnabled"] = sol::property(
            &TextEdit::getVirtualKeyboardEnabled,
            &TextEdit::setVirtualKeyboardEnabled
        );
        ut["wrapMode"] = sol::property(
            &TextEdit::getWrapMode,
            &TextEdit::setWrapMode
        );
    }
}
