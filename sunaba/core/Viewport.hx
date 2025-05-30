package sunaba.core;

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
}