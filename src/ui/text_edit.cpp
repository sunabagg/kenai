#include "text_edit.h"

namespace sunaba::ui {
    void TextEditSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("caret_changed"), &TextEditSignalWrapper::caret_changed);
        ClassDB::bind_method(D_METHOD("gutter_added"), &TextEditSignalWrapper::gutter_added);
        ClassDB::bind_method(D_METHOD("gutter_clicked", "line", "gutter"), &TextEditSignalWrapper::gutter_clicked);
        ClassDB::bind_method(D_METHOD("gutter_removed"), &TextEditSignalWrapper::gutter_removed);
        ClassDB::bind_method(D_METHOD("lines_edited_from", "from_line"), &TextEditSignalWrapper::lines_edited_from);
        ClassDB::bind_method(D_METHOD("text_changed"), &TextEditSignalWrapper::text_changed);
        ClassDB::bind_method(D_METHOD("text_set"), &TextEditSignalWrapper::text_set);
    }

    void TextEditSignalWrapper::caret_changed() {
        if (this->element != nullptr && this->element->getCaretChangedEvent() != nullptr) {
            Array args;
            this->element->getCaretChangedEvent()->emit(args);
        }
    }

    void TextEditSignalWrapper::gutter_added() {
        if (this->element != nullptr && this->element->getGutterAddedEvent() != nullptr) {
            Array args;
            this->element->getGutterAddedEvent()->emit(args);
        }
    }

    void TextEditSignalWrapper::gutter_clicked(int line, int gutter) {
        if (this->element != nullptr && this->element->getGutterClickedEvent() != nullptr) {
            Array args;
            args.push_back(line);
            args.push_back(gutter);
            this->element->getGutterClickedEvent()->emit(args);
        }
    }

    void TextEditSignalWrapper::gutter_removed() {
        if (this->element != nullptr && this->element->getGutterRemovedEvent() != nullptr) {
            Array args;
            this->element->getGutterRemovedEvent()->emit(args);
        }
    }

    void TextEditSignalWrapper::lines_edited_from(int from_line, int to_line) {
        if (this->element != nullptr && this->element->getLinesEditedFromEvent() != nullptr) {
            Array args;
            args.push_back(from_line);
            args.push_back(to_line);
            this->element->getLinesEditedFromEvent()->emit(args);
        }
    }

    void TextEditSignalWrapper::text_changed() {
        if (this->element != nullptr && this->element->getTextChangedEvent() != nullptr) {
            Array args;
            this->element->getTextChangedEvent()->emit(args);
        }
    }

    void TextEditSignalWrapper::text_set() {
        if (this->element != nullptr && this->element->getTextSetEvent() != nullptr) {
            Array args;
            this->element->getTextSetEvent()->emit(args);
        }
    }
    
    void bindTextEdit(sol::state& lua) {
        auto ut = lua.new_usertype<TextEdit>("TextEdit",
            "new", sol::factories(
                []() { return new TextEdit(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<TextEdit*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                TextEditNode* text_edit = Object::cast_to<TextEditNode>(e->getNode());
                return new TextEdit(text_edit);
            }
        );

        // Bind different parts of the TextEdit class using separate functions
        bindTextEditProperties(ut);
        bindTextEditEvents(ut);
        bindTextEditMethods1(ut);
        bindTextEditMethods2(ut);
        bindTextEditMethods3(ut);
        bindTextEditMethods4(ut);
    }
}