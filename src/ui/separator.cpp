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
} // namespace sunaba::ui