package sunaba.core;

@:native("SubViewport")
extern class SubViewport extends Viewport {
    public var renderTargetClearMode: Int;
    public var renderTargetUpdateMode: Int;
    public var size: Vector2i;
    public var size2dOverride: Vector2i;
    public var size2dOverrideStretch: Bool;
    @:native("cast")
    public static function toSubViewport(type: Dynamic): SubViewport;
}

abstract SubViewportAbstract(SubViewport) from SubViewport to SubViewport {
    @:from
    public static function fromElement(element: Element): ViewportAbstract {
        var viewport = SubViewport.toSubViewport(element);
        if (viewport.isNull()) {
            return null;
        }
        return viewport;
    }
}