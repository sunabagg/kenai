package sunaba.desktop;

@:native("AcceptDialog")
extern class AcceptDialog extends Window {
    public var dialogAutowrap: Bool;
    public var dialogCloseOnEscape: Bool;
    public var dialogHideOnOk: Bool;
    public var dialogText: String;
    public var okButtonText: String;
}