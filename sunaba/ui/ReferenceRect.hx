package sunaba.ui;

import sunaba.core.Color;

@:native("ReferenceRect")
extern class ReferenceRect extends Control {
    public var borderColor: Color;
    public var borderWidth: Float;
    @:native("cast")
    public static function toReferenceRect(obj: Dynamic): sunaba.ui.ReferenceRect;
}