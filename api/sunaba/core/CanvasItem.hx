package sunaba.core;

import sunaba.ui.StyleBox;
import sunaba.input.InputEvent;

@:native("Element")
extern class CanvasItem extends Element {
    public var clipChildren: Int;
    public var lightMask: Int;
    public var material: Material;
    public var modulate: Color;
    public var selfModulate: Color;
    public var showBehindParent: Bool;
    public var textureFilter: Int;
    public var textureRepeat: Bool;
    public var topLevel: Bool;
    public var useParentMaterial: Bool;
    public var visibilityLayer: Int;
    public var visible: Bool;
    public var ySortEnabled: Bool;
    public var zAsRelative: Bool;
    public var zIndex: Int;
    public function drawAnimationSlice(animationLength: Float, sliceBegin: Float, sliceEnd: Float, offset: Float = 0.0): Void;
    public function drawArc(center: Vector2, radius: Float, startAngle: Float, endAngle: Float, pointCount: Int, color: Color, width: Float = 1.0, antialis: Bool = false): Void;
    public function drawChar(font: Font, pos: Vector2, chr: String, fontSize: Int = 16, modulate: Color = null): Void;
    public function drawCharOutline(font: Font, pos: Vector2, chr: String, fontSize: Int = 16, size: Int = -1, modulate: Color = null): Void;
    public function drawCircle(center: Vector2, radius: Float, color: Color, width: Float = 1.0, antialis: Bool = false): Void;
    public function drawColoredPolygon(points: lua.Table<Int, Vector2>, color: Color, uvs: lua.Table<Int, Vector2> = null, texture: Texture2D = null): Void;
    public function drawDashedLine(from: Vector2, to: Vector2, color: Color, width: Float = -1.0, dash: Float = 2.0, aligned: Bool = true, antialis: Bool = false): Void;
    public function drawEndAnimation(): Void;
    public function drawLcdTextureRectRegion(texture: Texture2D, rect: Rect2, srcRect: Rect2, modulate: Color = null): Void;
    public function drawLine(from: Vector2, to: Vector2, color: Color, width: Float = -1.0, antialis: Bool = false): Void;
    public function drawMsdfTextureRegion(texture: Texture2D, rect: Rect2, srcRect: Rect2, modulate: Color = null, outline: Float = 0.0, pxelRange: Float = 4.0, scale: Float = 1.0): Void;
    public function drawMultiline(points: lua.Table<Int, Vector2>, colors: lua.Table<Int, Color>, width: Float = -1.0, antialis: Bool = false): Void;
    public function drawMultilineColors(points: lua.Table<Int, Vector2>, colors: lua.Table<Int, Color>, width: Float = -1.0, antialis: Bool = false): Void;
    public function drawMultilineString(font: Font, pos: Vector2, text: String, alignment: Int = 0, width: Float = -1, fontSize: Int = 16, maxLines: Int = -1, modulate: Color = null, brkFlags: lua.Table<Int, Int> = null, justificationFlags: lua.Table<Int, Int> = null, direction: Int = 0, orientation: Int = 0): Void;
    public function drawMultilineStringOutline(font: Font, pos: Vector2, text: String, alignment: Int = 0, width: Float = -1, fontSize: Int = 16, maxLines: Int = -1, size: Int = 1, modulate: Color = null, brkFlags: lua.Table<Int, Int> = null, justificationFlags: lua.Table<Int, Int> = null, direction: Int = 0, orientation: Int = 0): Void;
    public function drawPolygon(points: lua.Table<Int, Vector2>, colors: lua.Table<Int, Color>, uvs: lua.Table<Int, Vector2> = null, texture: Texture2D = null): Void;
    public function darwPolylineColors(points: lua.Table<Int, Vector2>, colors: lua.Table<Int, Color>, width: Float = -1.0, antialis: Bool = false): Void;
    public function drawPrimitive(points: lua.Table<Int, Vector2>, colors: lua.Table<Int, Color>, uvs: lua.Table<Int, Vector2> = null, texture: Texture2D = null): Void;
    public function drawRect(rect: Rect2, color: Color, filled: Bool = true, width: Float = 1.0, antialis: Bool = false): Void;
    public function drawSetTransform(pos: Vector2, rotation: Float = 0.0, scale: Vector2 = null): Void;
    public function drawSetTransformMatrix(xform: Transform2D): Void;
    public function drawString(font: Font, pos: Vector2, text: String, alignment: Int = 0, width: Float = -1, fontSize: Int = 16, modulate: Color = null, justificationFlags: lua.Table<Int, Int> = null, direction: Int = 0, orientation: Int = 0): Void;
    public function drawStringOutline(font: Font, pos: Vector2, text: String, alignment: Int = 0, width: Float = -1, fontSize: Int = 16, size: Int = 1, modulate: Color = null, justificationFlags: lua.Table<Int, Int> = null, direction: Int = 0, orientation: Int = 0): Void;
    public function drawStyleBox(styleBox: StyleBox, rect: Rect2): Void;
    public function drawTexture(texture: Texture2D, pos: Vector2, modulate: Color = null): Void;
    public function drawTextureRectRegion(texture: Texture2D, rect: Rect2, srcRect: Rect2, modulate: Color = null, transpose: Bool = false, clipUv: Bool = true): Void;
    public function forceUpdateTransform(): Void;
    public function getCanvasTransform(): Transform2D;
    public function getGlobalMousePosition(): Vector2;
    public function getGlobalTransform(): Transform2D;
    public function getGlobalTransformWithCanvas(): Transform2D;
    public function getLocalMousePosition(): Vector2;
    public function getScreenTransform(): Transform2D;
    public function getTransform(): Transform2D;
    public function getViewportRect(): Rect2;
    public function getViewportTransform(): Transform2D;
    public function getVisibilityLayerBit(bit: Int): Bool;
    public function hide(): Void;
    public function isLocalTransformNotificationEnabled(): Bool;
    public function isVisibleInTree(): Bool;
    public function makeCanvasPositionLocal(position: Vector2): Vector2;
    public function makeInputLocal(event: InputEvent): InputEvent;
    public function moveToFront(): Void;
    public function queueRedraw(): Void;
    public function setNotifyLocalTransform(enable: Bool): Void;
    public function setNotifyTransform(enable: Bool): Void;
    public function show(): Void;
    @:native("cast")
    public static function toCanvasItem(obj: Dynamic): CanvasItem;
}

abstract CanvasItemAbstract(CanvasItem) from CanvasItem to CanvasItem {
    @:from
    public static function fromElement(element: Element): CanvasItemAbstract {
        var cItem = CanvasItem.toCanvasItem(element);
        if (cItem.isNull()) {
            return null;
        }
        return cItem;
    }
}
