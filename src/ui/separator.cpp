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
} // namespace sunaba::ui