package lucidfx.ui;

import lucidfx.core.Rect2;
import lucidfx.core.Texture2D;

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
    public var textureChanged: lucidfx.core.Event;
    public function getPatchMargin(side: Int): Int;
    public function setPatchMargin(side: Int, margin: Int): Void;
    @:native("cast")
    public static function toNinePatchRect(obj: Dynamic): lucidfx.ui.NinePatchRect;
}

abstract NinePatchRectAbstract(NinePatchRect) from NinePatchRect to NinePatchRect {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.NinePatchRect {
        var ninePatchRect = lucidfx.ui.NinePatchRect.toNinePatchRect(element);
        if (ninePatchRect.isNull()) {
            return null;
        }
        return ninePatchRect;
    }
}