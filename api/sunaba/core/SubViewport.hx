package sunaba.core;

@:native("SubViewport")
extern class SubViewport extends Viewport {
    public var renderTargetClearMode: Int;
    public var renderTargetUpdateMode: Int;
    public var size: Vector2i;
    public var size2dOverride: Vector2i;
    public var size2dOverrideStretch: Bool;
}