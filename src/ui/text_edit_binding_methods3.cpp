#include "text_edit.h"

namespace sunaba::ui {
    void bindTextEditMethods3(sol::usertype<TextEdit>& ut) {
        ut["hasImeText"] = &TextEdit::hasImeText;
        ut["hasRedo"] = &TextEdit::hasRedo;
        ut["hasSelection"] = &TextEdit::hasSelection;
        ut["hasUndo"] = &TextEdit::hasUndo;
        ut["insertLineAt"] = &TextEdit::insertLineAt;
        ut["insertText"] = &TextEdit::insertText;
        ut["insertTextAtCaret"] = &TextEdit::insertTextAtCaret;
        ut["isCaretAfterSelectionOrigin"] = &TextEdit::isCaretAfterSelectionOrigin;
        ut["isCaretVisible"] = &TextEdit::isCaretVisible;
        ut["isDraggingCursor"] = &TextEdit::isDraggingCursor;
        ut["isGutterClickable"] = &TextEdit::isGutterClickable;
        ut["isGutterDrawn"] = &TextEdit::isGutterDrawn;
        ut["isGutterOverwritable"] = &TextEdit::isGutterOverwritable;
        ut["isInMulitcaretEdit"] = &TextEdit::isInMulitcaretEdit;
        ut["isLineGutterClickable"] = &TextEdit::isLineGutterClickable;
        ut["isLineWrapped"] = &TextEdit::isLineWrapped;
        ut["isMenuVisible"] = &TextEdit::isMenuVisible;
        ut["isMouseOverSelection"] = &TextEdit::isMouseOverSelection;
        ut["isOvertypeModeEnabled"] = &TextEdit::isOvertypeModeEnabled;
        ut["menuOption"] = &TextEdit::menuOption;
        ut["mergeGutters"] = &TextEdit::mergeGutters;
        ut["mergeOverlappingCarets"] = &TextEdit::mergeOverlappingCarets;
        ut["multicaretEditIgnoreCaret"] = &TextEdit::multicaretEditIgnoreCaret;
        ut["paste"] = &TextEdit::paste;
        ut["pastePrimaryClipboard"] = &TextEdit::pastePrimaryClipboard;
        ut["redo"] = &TextEdit::redo;
        ut["removeCaret"] = &TextEdit::removeCaret;
        ut["removeGutter"] = &TextEdit::removeGutter;
        ut["removeLineAt"] = &TextEdit::removeLineAt;
        ut["removeSecondaryCarets"] = &TextEdit::removeSecondaryCarets;
        ut["removeText"] = &TextEdit::removeText;
        ut["search"] = &TextEdit::search;
        ut["select"] = &TextEdit::select;
        ut["selectAll"] = &TextEdit::selectAll;
        ut["selectWordUnderCaret"] = &TextEdit::selectWordUnderCaret;
    }
}
