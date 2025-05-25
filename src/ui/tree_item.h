#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include <godot_cpp/classes/tree_item.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTreeItem godot::TreeItem

#include "../core/base_object.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTreeItem(sol::state& lua);

    class TreeItem : public BaseObject {
        
    };
}


#endif // TREE_ITEM_H