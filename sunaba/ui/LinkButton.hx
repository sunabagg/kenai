package sunaba.ui;

@:native("LinkButton")
extern class LinkButton extends BaseButton {
    public var language: String;
    public var mouseDefaultCursorShape: Int;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: sunaba.core.ArrayList;
    public var text: String;
    public var textDirection: Int;
}