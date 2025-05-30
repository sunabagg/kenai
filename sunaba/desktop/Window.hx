package sunaba.desktop;

import sunaba.core.Viewport;

@:native("Window")
extern class Window extends Viewport {
    public var alwaysOnTop: Bool;
}