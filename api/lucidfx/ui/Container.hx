package lucidfx.ui;

import lucidfx.core.Event;
import lucidfx.core.Element;

@:native("Container")
extern class Container extends Control {
    public var preSortChildren: Event;
    public var sortChildren: Event;
    public function fitChildInRect(child: Control, rect: lucidfx.core.Rect2): Void;
    public function queueSort(): Void;
    public function getAllowedSizeFlagsHorizontal(): lua.Table<Int,Int>;
    public function getAllowedSizeFlagsVertical(): lua.Table<Int,Int>;
    @:native("cast")
    public static function toContainer(type: Dynamic): Container;
}

abstract ContainerAbstarct(Container) from Container to Container {
    @:from
    public static function fromElement(element: lucidfx.core.Element): ContainerAbstarct {
        var container = Container.toContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}