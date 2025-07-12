#include "rich_text_label.h"

namespace kenai::ui {
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
            "new", sol::factories(
                []() { return new RichTextLabel(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::CanvasItem, Control>(),
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
            "justificationFlags", sol::property(
                &RichTextLabel::getJustificationFlags,
                &RichTextLabel::setJustificationFlags
            ),
            "language", sol::property(
                &RichTextLabel::getLanguage,
                &RichTextLabel::setLanguage
            ),
            "metaUnderlined", sol::property(
                &RichTextLabel::getMetaUnderlined,
                &RichTextLabel::setMetaUnderlined
            ),
            "progressBarDelay", sol::property(
                &RichTextLabel::getProgressBarDelay,
                &RichTextLabel::setProgressBarDelay
            ),
            "scrollActive", sol::property(
                &RichTextLabel::getScrollActive,
                &RichTextLabel::setScrollActive
            ),
            "scrollFollowing", sol::property(
                &RichTextLabel::getScrollFollowing,
                &RichTextLabel::setScrollFollowing
            ),
            "selectionEnabled", sol::property(
                &RichTextLabel::getSelectionEnabled,
                &RichTextLabel::setSelectionEnabled
            ),
            "shortcutKeysEnabled", sol::property(
                &RichTextLabel::getShortcutKeysEnabled,
                &RichTextLabel::setShortcutKeysEnabled
            ),
            "structuredTextBidiOverride", sol::property(
                &RichTextLabel::getStructuredTextBidiOverride,
                &RichTextLabel::setStructuredTextBidiOverride
            ),
            "structuredTextBidiOverrideOptions", sol::property(
                &RichTextLabel::getStructuredTextBidiOverrideOptions,
                &RichTextLabel::setStructuredTextBidiOverrideOptions
            ),
            "tabSize", sol::property(
                &RichTextLabel::getTabSize,
                &RichTextLabel::setTabSize
            ),
            "tabStops", sol::property(
                &RichTextLabel::getTabStops,
                &RichTextLabel::setTabStops
            ),
            "text", sol::property(
                &RichTextLabel::getText,
                &RichTextLabel::setText
            ),
            "textDirection", sol::property(
                &RichTextLabel::getTextDirection,
                &RichTextLabel::setTextDirection
            ),
            "threaded", sol::property(
                &RichTextLabel::getThreaded,
                &RichTextLabel::setThreaded
            ),
            "verticalAlignment", sol::property(
                &RichTextLabel::getVerticalAlignment,
                &RichTextLabel::setVerticalAlignment
            ),
            "visibleCharacters", sol::property(
                &RichTextLabel::getVisibleCharacters,
                &RichTextLabel::setVisibleCharacters
            ),
            "visibleCharactersBehavior", sol::property(
                &RichTextLabel::getVisibleCharactersBehavior,
                &RichTextLabel::setVisibleCharactersBehavior
            ),
            "visibleRatio", sol::property(
                &RichTextLabel::getVisibleRatio,
                &RichTextLabel::setVisibleRatio
            ),
            "finished", sol::property(
                &RichTextLabel::getFinishedEvent,
                &RichTextLabel::setFinishedEvent
            ),
            "metaClicked", sol::property(
                &RichTextLabel::getMetaClickedEvent,
                &RichTextLabel::setMetaClickedEvent
            ),
            "metaHoverEnded", sol::property(
                &RichTextLabel::getMetaHoverEndedEvent,
                &RichTextLabel::setMetaHoverEndedEvent
            ),
            "metaHoverStarted", sol::property(
                &RichTextLabel::getMetaHoverStartedEvent,
                &RichTextLabel::setMetaHoverStartedEvent
            ),
            "addImage", &RichTextLabel::addImage,
            "addText", &RichTextLabel::addText,
            "appendText", &RichTextLabel::appendText,
            "clear", &RichTextLabel::clear,
            "deselect", &RichTextLabel::deselect,
            "getCharacterLine", &RichTextLabel::getCharacterLine,
            "getCharacterParagraph", &RichTextLabel::getCharacterParagraph,
            "getContentHeight", &RichTextLabel::getContentHeight,
            "getContentWidth", &RichTextLabel::getContentWidth,
            "getLineCount", &RichTextLabel::getLineCount,
            "getLineOffset", &RichTextLabel::getLineOffset,
            "getLineRange", &RichTextLabel::getLineRange,
            "getMenu", &RichTextLabel::getMenu,
            "getParagraphCount", &RichTextLabel::getParagraphCount,
            "getParagraphOffset", &RichTextLabel::getParagraphOffset,
            "getParsedText", &RichTextLabel::getParsedText,
            "getSelectedText", &RichTextLabel::getSelectedText,
            "getSelectionFrom", &RichTextLabel::getSelectionFrom,
            "getSelectionLineOffset", &RichTextLabel::getSelectionLineOffset,
            "getSelectionTo", &RichTextLabel::getSelectionTo,
            "getTotalCharacterCount", &RichTextLabel::getTotalCharacterCount,
            "getVScrollBar", &RichTextLabel::getVScrollBar,
            "getVisibleLineCount", &RichTextLabel::getVisibleLineCount,
            "getVisibleParagraphCount", &RichTextLabel::getVisibleParagraphCount,
            "installEffect", &RichTextLabel::installEffect,
            "invalidateParagraph", &RichTextLabel::invalidateParagraph,
            "isFinished", &RichTextLabel::isFinished,
            "isMenuVisible", &RichTextLabel::isMenuVisible,
            "isReady", &RichTextLabel::isReady,
            "menuOption", &RichTextLabel::menuOption,
            "newline", &RichTextLabel::newline,
            "parseBBCode", &RichTextLabel::parseBBCode,
            "parseExpressionsForValues", &RichTextLabel::parseExpressionsForValues,
            "pop", &RichTextLabel::pop,
            "popAll", &RichTextLabel::popAll,
            "popContext", &RichTextLabel::popContext,
            "pushBgcolor", &RichTextLabel::pushBgcolor,
            "pushBold", &RichTextLabel::pushBold,
            "pushBoldItalics", &RichTextLabel::pushBoldItalics,
            "pushCell", &RichTextLabel::pushCell,
            "pushColor", &RichTextLabel::pushColor,
            "pushContext", &RichTextLabel::pushContext,
            //"pushCustomfx", &RichTextLabel::pushCustomfx,
            "pushDropcap", &RichTextLabel::pushDropcap,
            "pushFgcolor", &RichTextLabel::pushFgcolor,
            "pushFont", &RichTextLabel::pushFont,
            "pushFontSize", &RichTextLabel::pushFontSize,
            "pushHint", &RichTextLabel::pushHint,
            "pushIndent", &RichTextLabel::pushIndent,
            "pushItalics", &RichTextLabel::pushItalics,
            "pushLanguage", &RichTextLabel::pushLanguage,
            "pushList", &RichTextLabel::pushList,
            "pushMeta", &RichTextLabel::pushMeta,
            "pushMono", &RichTextLabel::pushMono,
            "pushNormal", &RichTextLabel::pushNormal,
            "pushOutlineColor", &RichTextLabel::pushOutlineColor,
            "pushOutlineSize", &RichTextLabel::pushOutlineSize,
            "pushParagraph", &RichTextLabel::pushParagraph,
            "pushStrikethrough", &RichTextLabel::pushStrikethrough,
            "pushTable", &RichTextLabel::pushTable,
            "pushUnderline", &RichTextLabel::pushUnderline,
            "removeParagraph", &RichTextLabel::removeParagraph,
            "scrollToLine", &RichTextLabel::scrollToLine,
            "scrollToParagraph", &RichTextLabel::scrollToParagraph,
            "scrollToSelection", &RichTextLabel::scrollToSelection,
            "selectAll", &RichTextLabel::selectAll,
            "setCellBorderColor", &RichTextLabel::setCellBorderColor,
            "setCellPadding", &RichTextLabel::setCellPadding,
            "setCellRowBackgroundColor", &RichTextLabel::setCellRowBackgroundColor,
            "setCellSizeOverride", &RichTextLabel::setCellSizeOverride,
            "setTableColumnExpand", &RichTextLabel::setTableColumnExpand,
            "updateImage", &RichTextLabel::updateImage,
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<RichTextLabel*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                RichTextLabelNode* node = Object::cast_to<RichTextLabelNode>(e->getNode());
                return new RichTextLabel(node);
            }
        );
    }
} // namespace kenai::ui