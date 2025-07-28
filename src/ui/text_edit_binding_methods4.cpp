#include "text_edit.h"

namespace sunaba::ui {
    void bindTextEditMethods4(sol::usertype<TextEdit>& ut) {
        ut["setCaretColumn"] = &TextEdit::setCaretColumn;
        ut["setCaretLine"] = &TextEdit::setCaretLine;
        ut["setGutterClickable"] = &TextEdit::setGutterClickable;
        ut["setGutterDraw"] = &TextEdit::setGutterDraw;
        ut["setGutterName"] = &TextEdit::setGutterName;
        ut["setGutterOverwritable"] = &TextEdit::setGutterOverwritable;
        ut["setGutterType"] = &TextEdit::setGutterType;
        ut["setGutterWidth"] = &TextEdit::setGutterWidth;
        ut["setLine"] = &TextEdit::setLine;
        ut["setLineAsCenterVisible"] = &TextEdit::setLineAsCenterVisible;
        ut["setLineAsFirstVisible"] = &TextEdit::setLineAsFirstVisible;
        ut["setLineAsLastVisible"] = &TextEdit::setLineAsLastVisible;
        ut["setLineBackgroundColor"] = &TextEdit::setLineBackgroundColor;
        ut["setLineGutterClickable"] = &TextEdit::setLineGutterClickable;
        ut["setLineGutterIcon"] = &TextEdit::setLineGutterIcon;
        ut["setLineGutterItemColor"] = &TextEdit::setLineGutterItemColor;
        ut["setLineGutterMetadata"] = &TextEdit::setLineGutterMetadata;
        ut["setLineGutterText"] = &TextEdit::setLineGutterText;
        ut["setOvertypeModeEnabled"] = &TextEdit::setOvertypeModeEnabled;
        ut["setSearchFlags"] = &TextEdit::setSearchFlags;
        ut["setSearchText"] = &TextEdit::setSearchText;
        ut["setSelectionMode"] = &TextEdit::setSelectionMode;
        ut["setSelectionOriginColumn"] = &TextEdit::setSelectionOriginColumn;
        ut["setSelectionOriginLine"] = &TextEdit::setSelectionOriginLine;
        ut["setTabSize"] = &TextEdit::setTabSize;
        ut["skipSelectionForNextOccurrence"] = &TextEdit::skipSelectionForNextOccurrence;
        ut["startAction"] = &TextEdit::startAction;
        ut["swapLines"] = &TextEdit::swapLines;
        ut["tagSavedVersion"] = &TextEdit::tagSavedVersion;
        ut["undo"] = &TextEdit::undo;
    }
}
