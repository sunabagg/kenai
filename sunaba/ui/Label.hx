package sunaba.ui;

import sunaba.core.LabelSettings;

@:native("Label")
extern class Label extends Control {
    public var autowrapMode: Int;
    public var clipText: Bool;
    public var ellipsisChar: String;
    public var horizontalAlignment: Int;
    public var justificationFlags: Int;
    public var labelSettings: LabelSettings;
    public var language: String;
    public var linesSkipped: Int;
    public var maxLinesSkipped: Int;
    public var mouseFilter: Int;
    public var paragraphSeparator: String;
}