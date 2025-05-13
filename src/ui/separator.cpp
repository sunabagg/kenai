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
} // namespace sunaba::ui