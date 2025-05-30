package sunaba.desktop;

import sunaba.core.Viewport;
import sunaba.core.Vector2i;

@:native("Window")
extern class Window extends Viewport {
    public var alwaysOnTop: Bool;
    public var autoTranslate: Bool;
    public var borderless: Bool;
    public var contentScaleAspect: Int;
    public var contentScaleFactor: Float;
    public var contentScaleMode: Int;
    public var contentScaleSize: Vector2i;
    public var contentScaleStretch: Int;
}