package sunaba.ui;

import sunaba.core.CanvasItem;
import sunaba.core.Vector2;
import sunaba.core.Element;

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
    public var offsetBottom:Float;
    public var offsetLeft:Float;
    public var offsetRight:Float;
    public var offsetTop:Float;
    public var physicsInterpolationMode:Int;
    public var pivotOffset:Vector2;
    public var position:Vector2;
    public var rotation:Float;
    public var rotationDegrees:Float;
    public var scale:Vector2;
    public var shortcutContext:Element;
    public var size:Vector2;
    public var sizeFlagsHorizontal:Int;
    public var sizeFlagsStretchRatio:Float;
    public var sizeFlagsVertical:Int;
    public var theme:Theme;
    public var themeTypeVariation:String;
    public var toolTipAutoTranslateMode:Int;
    public var toolTipText:String;
    public function acceptEvent():Void;
    
}