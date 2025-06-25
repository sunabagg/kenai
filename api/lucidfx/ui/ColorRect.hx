package lucidfx.ui;

import lucidfx.core.Color;
import lucidfx.core.Element;

@:native("ColorRect")
extern class ColorRect extends Control {
    public var color: Color;
    @:native("cast")
    public static function toColorRect(type: Dynamic): ColorRect;
}

abstract ColorRectAbstract(ColorRect) from ColorRect to ColorRect {
    @:from
    public static function fromElement(element: lucidfx.core.Element): ColorRectAbstract {
        var rect = ColorRect.toColorRect(element);
        if (rect.isNull()) {
            return null;
        }
        return rect;
    }
}