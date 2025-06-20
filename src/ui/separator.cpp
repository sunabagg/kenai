#include "separator.h"

namespace sunaba::ui
{
    void SeparatorProxy::_enter_tree()
    {
        if (element != nullptr)
        {
            element->enterTree();
        }
    }

    void SeparatorProxy::_exit_tree()
    {
        if (element != nullptr)
        {
            element->exitTree();
        }
    }

    void SeparatorProxy::_ready()
    {
        if (element != nullptr)
        {
            element->ready();
        }
    }

    void SeparatorProxy::_process(double delta)
    {
        if (element != nullptr)
        {
            element->process(delta);
        }
    }

    void SeparatorProxy::_physics_process(double delta)
    {
        if (element != nullptr)
        {
            element->physicsProcess(delta);
        }
    }

    void SeparatorProxy::_input(const Ref<InputEvent>& event)
    {
        if (element != nullptr)
        {
            element->input(event);
        }
    }

    void SeparatorProxy::_unhandled_input(const Ref<InputEvent>& event)
    {
        if (element != nullptr)
        {
            element->unhandledInput(event);
        }
    }

    void SeparatorProxy::_unhandled_key_input(const Ref<InputEvent>& event)
    {
        if (element != nullptr)
        {
            element->unhandledKeyInput(event);
        }
    }

    void SeparatorProxy::_shortcut_input(const Ref<InputEvent>& event)
    {
        if (element != nullptr)
        {
            element->shortcutInput(event);
        }
    }

    void SeparatorProxy::_draw()
    {
        if (element != nullptr)
        {
            element->_draw();
        }
    }

    bool SeparatorProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const
    {
        if (element != nullptr)
        {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SeparatorProxy::_drop_data(const Vector2 &at_position, const Variant &data)
    {
        if (element != nullptr)
        {
            element->dropData(at_position, data);
        }
    }

    Variant SeparatorProxy::_get_drag_data(const Vector2 &at_position)
    {
        if (element != nullptr)
        {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SeparatorProxy::_get_minimum_size() const
    {
        if (element != nullptr)
        {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String SeparatorProxy::_get_tooltip(const Vector2 &at_position) const
    {
        if (element != nullptr)
        {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void SeparatorProxy::_gui_input(const Ref<InputEvent> &event)
    {
        if (element != nullptr)
        {
            element->guiInput(event);
        }
    }

    bool SeparatorProxy::_has_point(const Vector2 &point) const
    {
        if (element != nullptr)
        {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> SeparatorProxy::_structured_text_parser(const Array &args, const String &text) const
    {
        if (element != nullptr)
        {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindSeparator(sol::state& lua) {
        lua.new_usertype<Separator>("Separator",
            "new", sol::factories(
                []() { return new Separator(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "cast", [] (Element* element) {
                SeparatorNode* separator = Object::cast_to<SeparatorNode>(element->getNode());
                return new Separator(separator);
            }
        );
    }
} // namespace sunaba::ui