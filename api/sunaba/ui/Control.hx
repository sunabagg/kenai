package sunaba.ui;

import sunaba.core.CanvasItem;
import sunaba.core.Vector2;
import sunaba.core.Element;
import sunaba.core.Variant;
import sunaba.core.Color;
import sunaba.core.Font;
import sunaba.core.Texture2D;
import sunaba.core.Rect2;
import sunaba.core.Event;

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
    public var focusEntered: Event;
    public var focusExited: Event;
    public var guiInput: Event;
    public var minimumSizeChanged: Event;
    public var mouseEntered: Event;
    public var mouseExited: Event;
    public var resized: Event;
    public var sizeFlagsChanged: Event;
    public var themeChanged: Event;
    public function acceptEvent():Void;
    public function addThemeColorOverride(name:String, color:Color):Void;
    public function addThemeConstantOverride(name:String, constant:Variant):Void;
    public function addThemeFontOverride(name:String, font:Font):Void;
    public function addThemeFontSizeOverride(name:String, size:Float):Void;
    public function addThemeIconOverride(name:String, icon:Texture2D):Void;
    public function addThemeStyleboxOverride(name:String, stylebox:StyleBox):Void;
    public function beginBulkThemeOverride():Void;
    public function endBulkThemeOverride():Void;
    public function findNextValidFocus():Control;
    public function findPrevValidFocus():Control;
    public function findValidFocusNeighbor(side: Int):Control;
    public function forceDrag(data:Variant,preview:Control):Void;
    public function getAnchor(side:Int):Float;
    public function getCombinedMinimumSize():Vector2;
    public function getCursorShape(position:Vector2):Int;
    public function getEnd():Vector2;
    public function getFocusNeighbor(side:Int):String;
    public function getGlobalRect():Rect2;
    public function getScreenPosition():Vector2;
    public function getThemeColor(name:String):Color;
    public function getThemeConstant(name:String):Variant;
    public function getThemeDefaultBaseScale():Float;
    public function getThemeDefaultFont():Font;
    public function getThemeDefaultFontSize():Float;
    public function getThemeFont(name:String):Font;
    public function getThemeFontSize(name:String):Float;
    public function getThemeIcon(name:String):Texture2D;
    public function getThemeStylebox(name:String):StyleBox;
    public function getTooltip():String;
    public function grabClickFocus():Void;
    public function grabFocus():Void;
    public function hasFocus():Bool;
    public function hasThemeColor(name:String,?type:String):Bool;
    public function hasThemeColorOverride(name:String):Bool;
    public function hasThemeConstant(name:String,?type:String):Bool;
    public function hasThemeConstantOverride(name:String):Bool;
    public function hasThemeFont(name:String,?type:String):Bool;
    public function hasThemeFontOverride(name:String):Bool;
    public function hasThemeFontSize(name:String,?type:String):Bool;
    public function hasThemeFontSizeOverride(name:String):Bool;
    public function hasThemeIcon(name:String,?type:String):Bool;
    public function hasThemeIconOverride(name:String):Bool;
    public function hasThemeStylebox(name:String,?type:String):Bool;
    public function hasThemeStyleboxOverride(name:String):Bool;
    public function isDragSuccessful():Bool;
    public function isLayoutRtl():Bool;
    public function releaseFocus():Void;
    public function removeThemeColorOverride(name:String):Void;
    public function removeThemeConstantOverride(name:String):Void;
    public function removeThemeFontOverride(name:String):Void;
    public function removeThemeFontSizeOverride(name:String):Void;
    public function removeThemeIconOverride(name:String):Void;
    public function removeThemeStyleboxOverride(name:String):Void;
    public function resetSize():Void;
    public function setAnchor(side:Int, anchor:Float, ?keepOffset:Bool, ?pushOppositeAnchor:Bool):Void;
    public function setAnchorAndOffset(side:Int, anchor:Float, offset:Float, ?pushOppositeAnchor:Bool):Void;
    public function setAnchorsAndOffsetsPreset(preset:Int, ?resizeMode:Int, ?margin:Int):Void;
    public function setAnchorsPreset(preset:Int, ?keepOffsets:Bool):Void;
    public function setBegin(position:Vector2):Void;
    public function setDragPreview(preview:Control):Void;
    public function setEnd(position:Vector2):Void;
    public function setFocusNeighbor(side:Int, neighbor:String):Void;
    public function setGlobalPosition(position:Vector2):Void;
    public function setOffset(side:Int, offset:Float):Void;
    public function setOffsetsPreset(preset:Int, ?resizeMode:Int, ?margin:Int):Void;
    public function setPosition(position:Vector2, ?keepOffset:Bool):Void;
    public function setSize(size:Vector2, ?keepOffsets:Bool):Void;
    public function updateMinimumSize():Void;
    public function warpMouse(position:Vector2):Void;
    @:native("cast")
    public static function toControl(obj:Dynamic):Control;
}

abstract ControlAbstract(Control) from Control to Control {
    @:from
    public static function fromElement(element: Element): ControlAbstract {
        var cItem = Control.toControl(element);
        if (cItem.isNull()) {
            return null;
        }
        return cItem;
    }
}