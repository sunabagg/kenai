package lucidfx.ui;

import lucidfx.core.Color;

@:native("ReferenceRect")
extern class ReferenceRect extends Control {
    public var borderColor: Color;
    public var borderWidth: Float;
    @:native("cast")
    public static function toReferenceRect(obj: Dynamic): lucidfx.ui.ReferenceRect;
}

abstract ReferenceRectAbstract(ReferenceRect) from ReferenceRect to ReferenceRect {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.ReferenceRect {
        var referenceRect = lucidfx.ui.ReferenceRect.toReferenceRect(element);
        if (referenceRect.isNull()) {
            return null;
        }
        return referenceRect;
    }
}