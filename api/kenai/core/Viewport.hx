package kenai.core;

import kenai.spatial.World3D;
import kenai.ui.Control;
import kenai.input.InputEvent;

@:native("Viewport")
extern class Viewport extends Element {
    public var anisotropicFilteringLevel: Int;
    public var audioListenerEnable2D: Bool;
    public var audioListenerEnable3D: Bool;
    public var canvasCullMask: Int;
    public var canvasItemDefaultTextureFilter: Int;
    public var canvasItemDefaultTextureRepeat: Int;
    public var canvasTransform: Transform2D;
    public var debugDraw: Int;
    public var disable3D: Bool;
    public var fsrSharpness: Float;
    public var globalCanvasTransform: Transform2D;
    public var guiDisableInput: Bool;
    public var guiEmbedSubwindows: Bool;
    public var guiSnapControlsToPixels: Bool;
    public var handleInputLocally: Bool;
    public var meshLodThreshold: Float;
    public var msaa2D: Int;
    public var msaa3D: Int;
    public var ownWorld3D: Bool;
    public var physicsInterpolationMode: Int;
    public var physicsObjectPicking: Bool;
    public var physicsObjectPickingFirstOnly: Bool;
    public var physicsObjectPickingSort: Bool;
    public var positionalShadowAtlas16Bits: Bool;
    public var positionalShadowAtlasQuad0: Bool;
    public var positionalShadowAtlasQuad1: Bool;
    public var positionalShadowAtlasQuad2: Bool;
    public var positionalShadowAtlasQuad3: Bool;
    public var positionalShadowAtlasSize: Int;
    public var scaling3DMode: Int;
    public var scaling3DScale: Float;
    public var screenSpaceAA: Int;
    public var sdfOversize: Int;
    public var sdfScale: Float;
    public var snap2DTransformToPixels: Bool;
    public var textureMipmapBias: Float;
    public var transparentBg: Bool;
    public var useDebanding: Bool;
    public var useHdr2D: Bool;
    public var useOcclusionCulling: Bool;
    public var useTaa: Bool;
    public var useXr: Bool;
    public var vrsMode: Int;
    public var vrsTexture: Texture2D;
    public var vrsUpdateMode: Int;
    public var world3D: World3D;
    public var guiFocusChanged: Event;
    public var sizeChanged: Event;
    public function findWorld3D(): World3D;
    public function canvasCullMaskBit(layer: Int): Bool;
    public function getFinalTransform(): Transform2D;
    public function getMousePosition(): Vector2;
    public function getRenderInfo(type: Int, info: Int): Int;
    public function getScreenTransform(): Transform2D;
    public function getStretchTransform(): Transform2D;
    public function getVisibleRect(): Rect2;
    public function guiCancelDrag(): Void;
    public function guiGetDragData(): Variant;
    public function guiGetFocusOwner() : Control;
    public function guiGetHoveredControl(): Control;
    public function guiIsDragSuccessful(): Bool;
    public function guiIsDragging(): Bool;
    public function guiReleaseFocus(): Void;
    public function isInputHandled(): Bool;
    public function notifyMouseEntered(): Void;
    public function pushInput(event: InputEvent, ?inLocalCoords: Bool): Void;
    public function pushTextInput(text: String): Void;
    public function pushUnhandledInput(event: InputEvent, ?inLocalCoords: Bool): Void;
    public function setCanvasCullMaskBit(layer: Int, enable: Bool): Void;
    public function setInputAsHandled(): Void;
    public function setPositionalShadowAtlasQuadrantSubdiv(quadrant: Int, subdiv: Int): Void;
    public function updateMouseCursorState(): Void;
    public function warpMouse(position: Vector2): Void;
    @:native("cast")
    public static function toViewport(type: Dynamic): Viewport;
}

abstract ViewportAbstract(Viewport) from Viewport to Viewport {
    @:from
    public static function fromElement(element: Element): ViewportAbstract {
        var viewport = Viewport.toViewport(element);
        if (viewport.isNull()) {
            return null;
        }
        return viewport;
    }
}