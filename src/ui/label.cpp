#include "label.h"

namespace lucidfx::ui {
    void LabelProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void LabelProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void LabelProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void LabelProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void LabelProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void LabelProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void LabelProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void LabelProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void LabelProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void LabelProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool LabelProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void LabelProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant LabelProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 LabelProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String LabelProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void LabelProxy::_gui_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool LabelProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> LabelProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindLabel(sol::state& lua) {
        lua.new_usertype<Label>("Label",
            "new", sol::factories(
                []() { return new Label(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::CanvasItem, Control>(),
            "autowrapMode", sol::property(&Label::getAutowrapMode, &Label::setAutowrapMode),
            "clipText", sol::property(&Label::getClipText, &Label::setClipText),
            "ellipsisChar", sol::property(&Label::getEllipsisChar, &Label::setEllipsisChar),
            "horizontalAlignment", sol::property(&Label::getHorizontalAlignment, &Label::setHorizontalAlignment),
            "justificationFlags", sol::property(&Label::getJustificationFlags, &Label::setJustificationFlags),
            "labelSettings", sol::property(&Label::getLabelSettings, &Label::setLabelSettings),
            "language", sol::property(&Label::getLanguage, &Label::setLanguage),
            "linesSkipped", sol::property(&Label::getLinesSkipped, &Label::setLinesSkipped),
            "maxLinesVisible", sol::property(&Label::getMaxLinesVisible, &Label::setMaxLinesVisible),
            "mouseFilter", sol::property(&Label::getMouseFilter, &Label::setMouseFilter),
            "paragraphSeparator", sol::property(&Label::getParagraphSeparator, &Label::setParagraphSeparator),
            "sizeFlagsVertical", sol::property(&Label::getSizeFlagsVertical, &Label::setSizeFlagsVertical),
            "structuredTextBidiOverride", sol::property(&Label::getStructuredTextBidiOverride, &Label::setStructuredTextBidiOverride),
            "structuredTextBidiOverrideOptions", sol::property(&Label::getStructuredTextBidiOverrideOptions, &Label::setStructuredTextBidiOverrideOptions),
            "tabStops", sol::property(&Label::getTabStops, &Label::setTabStops),
            "text", sol::property(&Label::getText, &Label::setText),
            "textDirection", sol::property(&Label::getTextDirection, &Label::setTextDirection),
            "textOverrunBehavior", sol::property(&Label::getTextOverrunBehavior, &Label::setTextOverrunBehavior),
            "uppercase", sol::property(&Label::getUppercase, &Label::setUppercase),
            "verticalAlignment", sol::property(&Label::getVerticalAlignment, &Label::setVerticalAlignment),
            "visibleCharacters", sol::property(&Label::getVisibleCharacters, &Label::setVisibleCharacters),
            "visibleCharactersBehavior", sol::property(&Label::getVisibleCharactersBehavior, &Label::setVisibleCharactersBehavior),
            "visibleRatio", sol::property(&Label::getVisibleRatio, &Label::setVisibleRatio),
            "getCharacterBounds", &Label::getCharacterBounds,
            "getLineCount", &Label::getLineCount,
            "getLineHeight", &Label::getLineHeight,
            "getTotalCharacterCount", &Label::getTotalCharacterCount,
            "getVisibleLineCount", &Label::getVisibleLineCount,
            "cast", [](Element* element) {
                LabelNode* labelNode = Object::cast_to<LabelNode>(element->getNode());
                return new Label(labelNode);
            }
        );
    }
}