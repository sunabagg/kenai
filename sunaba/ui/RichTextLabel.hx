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
    public var hintUnderlined: Bool;
    public var horizontalAlignment: Int;
    public var justificationFlags: Int;
    public var language: String;
    public var metaUnderlined: Bool;
    public var progressBarDelay: Int;
    public var scrollActive: Bool;
    public var scrollFollowing: Bool;
    public var selectionEnabled: Bool;
    public var shortcutKeysEnabled: Bool;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: ArrayList;
    public var tabSize: Int;
}