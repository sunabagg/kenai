package sunaba.ui;

import sunaba.core.BaseObject;

@:native("TreeItem")
extern class TreeItem extends BaseObject {
    public var collapsed: Bool;
    public var customMinimumHeight: Int;
    public var disableFolding: Bool;
    
}