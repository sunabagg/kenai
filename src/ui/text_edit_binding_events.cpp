#include "text_edit.h"

namespace sunaba::ui {
    void bindTextEditEvents(sol::usertype<TextEdit>& ut) {
        ut["caretChanged"] = sol::property(
            &TextEdit::getCaretChangedEvent,
            &TextEdit::setCaretChangedEvent
        );
        ut["gutterAdded"] = sol::property(
            &TextEdit::getGutterAddedEvent,
            &TextEdit::setGutterAddedEvent
        );
        ut["gutterClicked"] = sol::property(
            &TextEdit::getGutterClickedEvent,
            &TextEdit::setGutterClickedEvent
        );
        ut["gutterRemoved"] = sol::property(
            &TextEdit::getGutterRemovedEvent,
            &TextEdit::setGutterRemovedEvent
        );
        ut["linesEditedFrom"] = sol::property(
            &TextEdit::getLinesEditedFromEvent,
            &TextEdit::setLinesEditedFromEvent
        );
        ut["textChanged"] = sol::property(
            &TextEdit::getTextChangedEvent,
            &TextEdit::setTextChangedEvent
        );
        ut["textSet"] = sol::property(
            &TextEdit::getTextSetEvent,
            &TextEdit::setTextSetEvent
        );
    }
}
