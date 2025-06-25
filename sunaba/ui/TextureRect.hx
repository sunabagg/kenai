package lucidware.ui;

import lucidware.core.Texture2D;
import lucidware.core.Element;

@:native("TextureRect")
extern class TextureRect extends Control {
    public var expandMode: Int;
    public var flipH: Bool;
    public var flipV: Bool;
    public var stretchMode: Int;
    public var texture: Texture2D;
    @:native("cast")
    public static function toTextureRect(obj: Dynamic): TextureRect;
}

abstract TextureRectAbstract(TextureRect) from TextureRect to TextureRect {
    @:from
    public static function fromElement(e: Element): TextureRectAbstract {
        var tRect = TextureRect.toTextureRect(e);
        if (tRect.isNull()) {
            return null;
        }
        return tRect;
    }
}