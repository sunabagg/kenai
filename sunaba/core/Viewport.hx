package sunaba.core;

@:native("Viewport")
extern class Viewport extends Element {
    public var anisotropicFilteringLevel: Int;
    public var audioListenerEnable2D: Bool;
    public var audioListenerEnable3D: Bool;
    public var canvasCullMask: Int;
    public var canvasItemDefaultTextureFilter: Int;
}