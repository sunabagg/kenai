#include "rich_text_label.h"

namespace sunaba::ui {
    void RichTextLabelProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void RichTextLabelProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void RichTextLabelProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void RichTextLabelProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void RichTextLabelProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void RichTextLabelProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void RichTextLabelProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void RichTextLabelProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void RichTextLabelProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void RichTextLabelProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool RichTextLabelProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void RichTextLabelProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant RichTextLabelProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 RichTextLabelProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String RichTextLabelProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void RichTextLabelProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool RichTextLabelProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> RichTextLabelProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void RichTextLabelSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("finished"), &RichTextLabelSignalWrapper::finished);
        ClassDB::bind_method(D_METHOD("meta_clicked", "meta"), &RichTextLabelSignalWrapper::meta_clicked);
        ClassDB::bind_method(D_METHOD("meta_hover_ended", "meta"), &RichTextLabelSignalWrapper::meta_hover_ended);
        ClassDB::bind_method(D_METHOD("meta_hover_started", "meta"), &RichTextLabelSignalWrapper::meta_hover_started);
    }

    void RichTextLabelSignalWrapper::finished() {
        if (element != nullptr) {
            Array args;
            element->finishedEvent->emit(args);
        }
    }

    void RichTextLabelSignalWrapper::meta_clicked(const Variant& meta) {
        if (element != nullptr) {
            Array args;
            args.append(meta);
            element->metaClickedEvent->emit(args);
        }
    }

    void RichTextLabelSignalWrapper::meta_hover_ended(const Variant& meta) {
        if (element != nullptr) {
            Array args;
            args.append(meta);
            element->metaHoverEndedEvent->emit(args);
        }
    }

    void RichTextLabelSignalWrapper::meta_hover_started(const Variant& meta) {
        if (element != nullptr) {
            Array args;
            args.append(meta);
            element->metaHoverStartedEvent->emit(args);
        }
    }

    void bindRichTextLabel(sol::state& lua) {
        lua.new_usertype<RichTextLabel>("RichTextLabel",
            sol::constructors<RichTextLabel()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "autowrapMode", sol::property(
                &RichTextLabel::getAutowrapMode,
                &RichTextLabel::setAutowrapMode
            ),
            "bbcodeEnabled", sol::property(
                &RichTextLabel::getBbcodeEnabled,
                &RichTextLabel::setBbcodeEnabled
            ),
            "clipContents", sol::property(
                &RichTextLabel::getClipContents,
                &RichTextLabel::setClipContents
            ),
            "contextMenuEnabled", sol::property(
                &RichTextLabel::getContextMenuEnabled,
                &RichTextLabel::setContextMenuEnabled
            ),
            "customEffects", sol::property(
                &RichTextLabel::getCustomEffects,
                &RichTextLabel::setCustomEffects
            ),
            "deselectOnFocusLossEnabled", sol::property(
                &RichTextLabel::getDeselectOnFocusLossEnabled,
                &RichTextLabel::setDeselectOnFocusLossEnabled
            ),
            "dragAndDropSelectionEnabled", sol::property(
                &RichTextLabel::getDragAndDropSelectionEnabled,
                &RichTextLabel::setDragAndDropSelectionEnabled
            ),
            "fitContent", sol::property(
                &RichTextLabel::getFitContent,
                &RichTextLabel::setFitContent
            ),
            "hintUnderlined", sol::property(
                &RichTextLabel::getHintUnderlined,
                &RichTextLabel::setHintUnderlined
            ),
            "horizontalAlignment", sol::property(
                &RichTextLabel::getHorizontalAlignment,
                &RichTextLabel::setHorizontalAlignment
            ),
        );
    }
} // namespace sunaba::ui