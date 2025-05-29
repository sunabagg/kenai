package sunaba.ui;

import sunaba.core.Texture2D;

@:native("ButtonGroup")
extern class Button extends BaseButton {
    public var alignment: Int;
    public var autowrapMode: Int;
    public var clipText: Bool;
    public var expandIcon: Bool;
    public var flat: Bool;
    public var icon: Texture2D;
    public var iconAlignment: Int;
}