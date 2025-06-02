package sunaba.ui;

@:native("PanelContainer")
extern class RichTextLabel extends Control {
    public var autowrapMode: Int;
    public var bbcodeEnabled: Bool;
    public var clipContents: Bool;
    public var contextMenuEnabled: Bool;
}