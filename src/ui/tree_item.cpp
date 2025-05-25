#include "tree_item.h"

namespace sunaba::ui {
    void bindTreeItem(sol::state& lua) {
        lua.new_usertype<TreeItem>("TreeItem",
            sol::constructors<TreeItem()>(),
            sol::base_classes, sol::bases<BaseObject>()
        );
    }
}