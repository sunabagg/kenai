package sunaba.ui;

import sunaba.core.CanvasItem;
import sunaba.core.Vector2;

@:native("Control")
extern class Control extends CanvasItem {
    public var anchorBottom:Float;
    public var anchorLeft:Float;
    public var anchorRight:Float;
    public var anchorTop:Float;
    public var autoTranslate:Bool;
    public var clippingContents:Bool;
    public var customMinimumSize: Vector2;
    public var focusMode:Bool;
    public var focusNeighborBottom: String;
    public var focusNeighborLeft: String;
    public var focusNeighborRight: String;
    public var focusNeighborTop: String;
    public var focusNext: String;
    public var focusPrevious: String;
    public var globalPosition: Vector2;
    public var growHorizontal:Bool;
    public var growVertical:Bool;
    public var layoutDirection:Float;
    public var localizingNumeralSystem:Bool;
    public var mouseFilter:Int;
    public var mouseForcePassScrollEvents:Bool;
}