package sunaba.ui;

import sunaba.core.CanvasItem;

@:native("Control")
extern class Control extends CanvasItem {
    public var anchorBottom:Float;
    public var anchorLeft:Float;
    public var anchorRight:Float;
    public var anchorTop:Float;
    public var autoTranslate:Bool;
    public var clippingContents:Bool;
    public var customMinimumSize: Vector2;
}