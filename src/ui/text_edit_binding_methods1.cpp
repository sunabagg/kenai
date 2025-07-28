#include "text_edit.h"

namespace sunaba::ui {
    void bindTextEditMethods1(sol::usertype<TextEdit>& ut) {
        ut["addCaret"] = &TextEdit::addCaret;
        ut["addCaretAtCarets"] = &TextEdit::addCaretAtCarets;
        ut["addGutter"] = &TextEdit::addGutter;
        ut["addSelectionForNextOccurrence"] = &TextEdit::addSelectionForNextOccurrence;
        ut["adjustCaretsAfterEdit"] = &TextEdit::adjustCaretsAfterEdit;
        ut["adjustViewportToCaret"] = &TextEdit::adjustViewportToCaret;
        ut["applyIme"] = &TextEdit::applyIme;
        ut["backspace"] = &TextEdit::backspace;
        ut["beginComplexOperation"] = &TextEdit::beginComplexOperation;
        ut["beginMulticaretEdit"] = &TextEdit::beginMulticaretEdit;
        ut["cancelIme"] = &TextEdit::cancelIme;
        ut["centerViewportToCaret"] = &TextEdit::centerViewportToCaret;
        ut["clear"] = &TextEdit::clear;
        ut["clearUndoHistory"] = &TextEdit::clearUndoHistory;
        ut["collapseCarets"] = &TextEdit::collapseCarets;
        ut["copy"] = &TextEdit::copy;
        ut["cut"] = &TextEdit::cut;
        ut["deleteSelection"] = &TextEdit::deleteSelection;
        ut["deselect"] = &TextEdit::deselect;
        ut["endAction"] = &TextEdit::endAction;
        ut["endComplexOperation"] = &TextEdit::endComplexOperation;
        ut["endMulticaretEdit"] = &TextEdit::endMulticaretEdit;
        ut["getCaretColumn"] = &TextEdit::getCaretColumn;
        ut["getCaretCount"] = &TextEdit::getCaretCount;
        ut["getCaretDrawPos"] = &TextEdit::getCaretDrawPos;
        ut["getCaretIndexEditOrder"] = &TextEdit::getCaretIndexEditOrder;
        ut["getCaretLine"] = &TextEdit::getCaretLine;
        ut["getCaretWrapIndex"] = &TextEdit::getCaretWrapIndex;
        ut["getFirstNonWhitespaceColumn"] = &TextEdit::getFirstNonWhitespaceColumn;
        ut["getFirstVisibleLine"] = &TextEdit::getFirstVisibleLine;
        ut["getGutterCount"] = &TextEdit::getGutterCount;
        ut["getGutterName"] = &TextEdit::getGutterName;
        ut["getGutterType"] = &TextEdit::getGutterType;
        ut["getGutterWidth"] = &TextEdit::getGutterWidth;
        ut["getHScrollBar"] = &TextEdit::getHScrollBar;
        ut["getIndentLevel"] = &TextEdit::getIndentLevel;
        ut["getLastFullVisibleLine"] = &TextEdit::getLastFullVisibleLine;
        ut["getLastFullVisibleLineWrapIndex"] = &TextEdit::getLastFullVisibleLineWrapIndex;
        ut["getLastUnhiddenLine"] = &TextEdit::getLastUnhiddenLine;
    }
}
