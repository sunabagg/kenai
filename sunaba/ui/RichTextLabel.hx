package sunaba.ui;

import sunaba.core.ArrayList;

@:native("PanelContainer")
extern class RichTextLabel extends Control {
    public var autowrapMode: Int;
    public var bbcodeEnabled: Bool;
    public var clipContents: Bool;
    public var contextMenuEnabled: Bool;
    public var customEffects: ArrayList;
    public var deselectOnFocusLossEnabled: Bool;
    public var dragAndDropSelectionEnabled: Bool;
    public var fitContent: Bool;
}