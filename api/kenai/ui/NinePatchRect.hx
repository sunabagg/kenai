package kenai.ui;

import kenai.core.Rect2;
import kenai.core.Texture2D;

@:native("NinePatchRect")
extern class NinePatchRect extends Control {
    public var axisStretchHorizontal: Int;
    public var axisStretchVertical: Int;
    public var drawCenter: Bool;
    public var patchMarginBottom: Int;
    public var patchMarginLeft: Int;
    public var patchMarginRight: Int;
    public var patchMarginTop: Int;
    public var regionRect: Rect2;
    public var texture: Texture2D;
    public var textureChanged: kenai.core.Event;
    public function getPatchMargin(side: Int): Int;
    public function setPatchMargin(side: Int, margin: Int): Void;
    @:native("cast")
    public static function toNinePatchRect(obj: Dynamic): kenai.ui.NinePatchRect;
}

abstract NinePatchRectAbstract(NinePatchRect) from NinePatchRect to NinePatchRect {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.NinePatchRect {
        var ninePatchRect = kenai.ui.NinePatchRect.toNinePatchRect(element);
        if (ninePatchRect.isNull()) {
            return null;
        }
        return ninePatchRect;
    }
}