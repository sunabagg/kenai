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
} // namespace sunaba::ui