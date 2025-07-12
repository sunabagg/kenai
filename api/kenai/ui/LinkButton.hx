package kenai.ui;

@:native("LinkButton")
extern class LinkButton extends BaseButton {
    public var language: String;
    public var mouseDefaultCursorShape: Int;
    public var structuredTextBidiOverride: Int;
    public var structuredTextBidiOverrideOptions: kenai.core.ArrayList;
    public var text: String;
    public var textDirection: Int;
    public var underline: Bool;
    public var uri: String;
    @:native("cast")
    public static function toLinkButton(obj: Dynamic): kenai.ui.LinkButton;
}

abstract LinkButtonAbstract(LinkButton) from LinkButton to LinkButton {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.LinkButton {
        var linkButton = kenai.ui.LinkButton.toLinkButton(element);
        if (linkButton.isNull()) {
            return null;
        }
        return linkButton;
    }
}