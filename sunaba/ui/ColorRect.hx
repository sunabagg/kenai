package sunaba.ui;

import sunaba.core.Color;
import sunaba.core.Element;

@:native("ColorRect")
extern class ColorRect extends Control {
    public var color: Color;
    @:native("cast")
    public function toColorRect(type: Dynamic): ColorRect;
}