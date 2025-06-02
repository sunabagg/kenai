package sunaba.ui;

import sunaba.core.Color;

@:native("ReferenceRect")
extern class ReferenceRect extends Control {
    public var borderColor: Color;
    public var borderWidth: Float;
    @:native("cast")
    public static function toReferenceRect(obj: Dynamic): sunaba.ui.ReferenceRect;
}

abstract ReferenceRectAbstract(ReferenceRect) from ReferenceRect to ReferenceRect {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.ReferenceRect {
        var referenceRect = sunaba.ui.ReferenceRect.toReferenceRect(element);
        if (referenceRect.isNull()) {
            return null;
        }
        return referenceRect;
    }
}