package lucidfx.ui;

import lucidfx.core.Element;
import lucidfx.core.Texture2D;

@:native("Button")
extern class Button extends BaseButton {
    public var alignment: Int;
    public var autowrapMode: Int;
    public var clipText: Bool;
    public var expandIcon: Bool;
    public var flat: Bool;
    public var icon: Texture2D;
    public var iconAlignment: Int;
    public var language: String;
    public var text: String;
    public var textDirection: Int;
    public var textOverrunBehavior: Int;
    public var verticalIconAlignment: Int;
    @:native("cast")
    public static function toButton(type: Dynamic): Button;
}

abstract ButtonAbstract(Button) from Button to Button {
    @:from
    public static function fromElement(element: Element): ButtonAbstract {
        var btn = Button.toButton(element);
        if (btn.isNull()) {
            return null;
        }
        return btn;
    }
}