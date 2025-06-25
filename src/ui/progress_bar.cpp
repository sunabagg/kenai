#include "progress_bar.h"

namespace lucidware::ui {
    void ProgressBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ProgressBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ProgressBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ProgressBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ProgressBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ProgressBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ProgressBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ProgressBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ProgressBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void ProgressBarProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ProgressBarProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void ProgressBarProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant ProgressBarProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ProgressBarProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String ProgressBarProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void ProgressBarProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool ProgressBarProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> ProgressBarProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void ProgressBarProxy::_value_changed(double value) {
        if (element != nullptr) {
            element->valueChanged(value);
        }
    }

    void bindProgressBar(sol::state &lua) {
        lua.new_usertype<ProgressBar>("ProgressBar",
            "new", sol::factories(
                []() { return new ProgressBar(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, Control, Range>(),
            "editorPreviewIndeterminate", sol::property(&ProgressBar::isEditorPreviewIndeterminate, &ProgressBar::setEditorPreviewIndeterminate),
            "fillMode", sol::property(&ProgressBar::getFillMode, &ProgressBar::setFillMode),
            "indeterminate", sol::property(&ProgressBar::getIndeterminate, &ProgressBar::setIndeterminate),
            "showPercentage", sol::property(&ProgressBar::getShowPercentage, &ProgressBar::setShowPercentage),
            "cast", [] (Element* element) {
                ProgressBarNode* progressBar = Object::cast_to<ProgressBarNode>(element->getNode());
                return new ProgressBar(progressBar);
            }
        );
    }
}