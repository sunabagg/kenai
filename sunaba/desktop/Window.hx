package sunaba.desktop;

import sunaba.core.Viewport;
import sunaba.core.Vector2i;
import sunaba.core.Vector2;
import sunaba.ui.Theme;

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
    public var currentScreen: Int;
    public var excludeFromCapture: Bool;
    public var exclusive: Bool;
    public var extendToTitle: Bool;
    public var forceNative: Bool;
    public var initialPosition: Int;
    public var keepTitleVisible: Bool;
    public var maxSize: Vector2i;
    public var minSize: Vector2i;
    public var mode: Int;
    public var mousePassthrough: Bool;
    public var mousePassthroughPolygon: Array<Vector2>;
    public var popupWindow: Bool;
    public var position: Vector2i;
    public var sharpCorners: Bool;
    public var size: Vector2i;
    public var theme: Theme;
    public var themeTypeVariation: String;
    public var title: String;
    public var transient: Bool;
    public var transientToFocused: Bool;
    public var transparent: Bool;
    public var unfocusable: Bool;
    public var unresizable: Bool;
    public var visible: Bool;
}