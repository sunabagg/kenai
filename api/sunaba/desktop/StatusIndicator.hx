package sunaba.desktop;

import sunaba.core.Element;
import sunaba.core.Texture2D;
import sunaba.core.Event;

@:native("StatusIndicator")
extern class StatusIndicator extends Element {
    public var icon: Texture2D;
    public var menu: String;
    public var tooltip: String;
}