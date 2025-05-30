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
}