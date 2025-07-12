package kenai.ui;

import kenai.core.Color;

@:native("ReferenceRect")
extern class ReferenceRect extends Control {
    public var borderColor: Color;
    public var borderWidth: Float;
    @:native("cast")
    public static function toReferenceRect(obj: Dynamic): kenai.ui.ReferenceRect;
}

abstract ReferenceRectAbstract(ReferenceRect) from ReferenceRect to ReferenceRect {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.ReferenceRect {
        var referenceRect = kenai.ui.ReferenceRect.toReferenceRect(element);
        if (referenceRect.isNull()) {
            return null;
        }
        return referenceRect;
    }
}