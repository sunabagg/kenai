package sunaba.ui;

import sunaba.input.InputEvent;

@:native("SubViewportContainer")
extern class SubViewportContainer extends Container {
    public var mouseTarget: Bool;
    public var stretch: Bool;
    public var stretchShrink: Bool;
    @:native("cast")
    public static function toSubViewportContainer(obj: Dynamic): sunaba.ui.SubViewportContainer;
}