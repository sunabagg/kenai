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
    public var tabStops: Array<Float>;
    public var text: String;
    public var textDirection: Int;
    public var threaded: Bool;
    public var verticalAlignment: Int;
    public var visibleCharacters: Int;
    public var visibleCharactersBehavior: Int;
    public var visibleRatio: Float;
    public var finished: sunaba.core.Event;
    public var metaClicked: sunaba.core.Event;
    public var metaHoverEnded: sunaba.core.Event;
}