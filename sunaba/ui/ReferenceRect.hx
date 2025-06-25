package lucidware.ui;

import lucidware.core.Color;

@:native("ReferenceRect")
extern class ReferenceRect extends Control {
    public var borderColor: Color;
    public var borderWidth: Float;
    @:native("cast")
    public static function toReferenceRect(obj: Dynamic): lucidware.ui.ReferenceRect;
}

abstract ReferenceRectAbstract(ReferenceRect) from ReferenceRect to ReferenceRect {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.ReferenceRect {
        var referenceRect = lucidware.ui.ReferenceRect.toReferenceRect(element);
        if (referenceRect.isNull()) {
            return null;
        }
        return referenceRect;
    }
}