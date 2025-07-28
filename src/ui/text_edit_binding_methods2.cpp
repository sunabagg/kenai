#include "text_edit.h"

namespace sunaba::ui {
    void bindTextEditMethods2(sol::usertype<TextEdit>& ut) {
        ut["getLineBackgroundColor"] = &TextEdit::getLineBackgroundColor;
        ut["getLineColumnAtPos"] = &TextEdit::getLineColumnAtPos;
        ut["getLineCount"] = &TextEdit::getLineCount;
        ut["getLineGutterIcon"] = &TextEdit::getLineGutterIcon;
        ut["getLineGutterItemColor"] = &TextEdit::getLineGutterItemColor;
        ut["getLineGutterMetadata"] = &TextEdit::getLineGutterMetadata;
        ut["getLineGutterText"] = &TextEdit::getLineGutterText;
        ut["getLineHeight"] = &TextEdit::getLineHeight;
        ut["getLineRangesFromCarets"] = &TextEdit::getLineRangesFromCarets;
        ut["getLineWidth"] = &TextEdit::getLineWidth;
        ut["getLineWithIme"] = &TextEdit::getLineWithIme;
        ut["getLineWrapCount"] = &TextEdit::getLineWrapCount;
        ut["getLineWrapIndexAtColumn"] = &TextEdit::getLineWrapIndexAtColumn;
        ut["getLineWrappedText"] = &TextEdit::getLineWrappedText;
        ut["getLocalMousePos"] = &TextEdit::getLocalMousePos;
        ut["getMenu"] = &TextEdit::getMenu;
        ut["getMinimapLineAtPos"] = &TextEdit::getMinimapLineAtPos;
        ut["getMinimapVisibleLines"] = &TextEdit::getMinimapVisibleLines;
        ut["getNextVisibleLineIndexOffsetFrom"] = &TextEdit::getNextVisibleLineIndexOffsetFrom;
        ut["getNextVisibleLineOffsetFrom"] = &TextEdit::getNextVisibleLineOffsetFrom;
        ut["getPosAtLineColumn"] = &TextEdit::getPosAtLineColumn;
        ut["getRectAtLineColumn"] = &TextEdit::getRectAtLineColumn;
        ut["getSavedVersion"] = &TextEdit::getSavedVersion;
        ut["getScrollPosForLine"] = &TextEdit::getScrollPosForLine;
        ut["getSelectedText"] = &TextEdit::getSelectedText;
        ut["getSelectionAtLineColumn"] = &TextEdit::getSelectionAtLineColumn;
        ut["getSelectionColumn"] = &TextEdit::getSelectionColumn;
        ut["getSelectionFromColumn"] = &TextEdit::getSelectionFromColumn;
        ut["getSelectionFromLine"] = &TextEdit::getSelectionFromLine;
        ut["getSelectionLine"] = &TextEdit::getSelectionLine;
        ut["getSelectionMode"] = &TextEdit::getSelectionMode;
        ut["getSelectionOriginColumn"] = &TextEdit::getSelectionOriginColumn;
        ut["getSelectionOriginLine"] = &TextEdit::getSelectionOriginLine;
        ut["getSelectionToColumn"] = &TextEdit::getSelectionToColumn;
        ut["getSelectionToLine"] = &TextEdit::getSelectionToLine;
        ut["getSortedCarets"] = &TextEdit::getSortedCarets;
        ut["getTabSize"] = &TextEdit::getTabSize;
        ut["getTotalGutterWidth"] = &TextEdit::getTotalGutterWidth;
        ut["getTotalVisibleLineCount"] = &TextEdit::getTotalVisibleLineCount;
        ut["getVScrollBar"] = &TextEdit::getVScrollBar;
        ut["getVersion"] = &TextEdit::getVersion;
        ut["getVisibleLineCount"] = &TextEdit::getVisibleLineCount;
        ut["getVisibleLineCountInRange"] = &TextEdit::getVisibleLineCountInRange;
        ut["getWordAtPos"] = &TextEdit::getWordAtPos;
        ut["getWordUnderCaret"] = &TextEdit::getWordUnderCaret;
    }
}
