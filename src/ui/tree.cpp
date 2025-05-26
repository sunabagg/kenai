#include "tree.h"

namespace sunaba::ui {
    void TreeProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TreeProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TreeProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TreeProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TreeProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TreeProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TreeProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TreeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TreeProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TreeProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TreeProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TreeProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TreeProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TreeProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

    String TreeProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TreeProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool TreeProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    // Object* TreeProxy::_make_custom_tooltip(const String &for_text) const {
    //     if (this->element != nullptr) {
    //         return this->element->makeCustomTooltip(for_text);
    //     }
    //     return nullptr;  
    // }

    TypedArray<Vector3i> TreeProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindTree(sol::state &lua) {
        lua.new_usertype<Tree>("Tree",
            sol::constructors<Tree()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "allowReselect", sol::property(
                &Tree::getAllowReselect,
                &Tree::setAllowReselect
            ),
            "allowRmbSelect", sol::property(
                &Tree::getAllowRmbSelect,
                &Tree::setAllowRmbSelect
            ),
            "allowSearch", sol::property(
                &Tree::getAllowSearch,
                &Tree::setAllowSearch
            ),
            "autoTooltip", sol::property(
                &Tree::getAutoTooltip,
                &Tree::setAutoTooltip
            ),
            "clipContents", sol::property(
                &Tree::getClipContents,
                &Tree::setClipContents
            ),
            "columnTitlesVisible", sol::property(
                &Tree::getColumnTitlesVisible,
                &Tree::setColumnTitlesVisible
            ),
            "columns", sol::property(
                &Tree::getColumns,
                &Tree::setColumns
            ),
            "dropModeFlags", sol::property(
                &Tree::getDropModeFlags,
                &Tree::setDropModeFlags
            ),
            "enableRecursiveFolding", sol::property(
                &Tree::getEnableRecursiveFolding,
                &Tree::setEnableRecursiveFolding
            ),
        );
    }
}