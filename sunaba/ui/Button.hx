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
    public var language: String;
    public var text: String;
    public var textDirection: Int;
    public var textOverrunBehavior: Int;
    public var verticalIconAlignment: Int;
    @:native("cast")
    public function toButton(type: Dynamic): Button;
}