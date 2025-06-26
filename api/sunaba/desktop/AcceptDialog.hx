package sunaba.desktop;

import sunaba.core.Event;

@:native("AcceptDialog")
extern class AcceptDialog extends Window {
    public var dialogAutowrap: Bool;
    public var dialogCloseOnEscape: Bool;
    public var dialogHideOnOk: Bool;
    public var dialogText: String;
    public var okButtonText: String;
    public var canceled: Event;
}