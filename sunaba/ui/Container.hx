package sunaba.ui;

import sunaba.core.Event;

@:native("Container")
public class Container extends Control {
    public var mouseFilter: Int;
    public var preSortChildren: Event;
    public var sortChildren: Event;
    public function fitChildInRect(child: Control, rect: sunaba.core.Rect2): Void;
    public function queueSort(): Void;
    public function getAllowedSizeFlagsHorizontal(): Array<Int>;
    public function getAllowedSizeFlagsVertical(): Array<Int>;
    @:native("cast")
    public function toContainer(type: Dynamic): Container;
}