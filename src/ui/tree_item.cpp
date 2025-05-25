#include "tree_item.h"

namespace sunaba::ui {
    void bindTreeItem(sol::state& lua) {
        lua.new_usertype<TreeItem>("TreeItem",
            sol::constructors<TreeItem()>(),
            sol::base_classes, sol::bases<BaseObject>(),
            "collapsed", sol::property(&TreeItem::getCollapsed, &TreeItem::setCollapsed),
            "customMinimumHeight", sol::property(&TreeItem::getCustomMinimumHeight, &TreeItem::setCustomMinimumHeight),
            "disableFolding", sol::property(&TreeItem::getDisableFolding, &TreeItem::setDisableFolding),
        );
    }
}