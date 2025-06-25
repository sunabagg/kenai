package lucidware.ui;

import lucidware.core.Element;

@:native("CenterContainer")
extern class CenterContainer extends Container {
    public function new();
    public var useTopLeft: Bool;
    @:native("cast")
    public static function toCenterContainer(type: Dynamic): CenterContainer;
}

abstract CenterContainerAbstract(CenterContainer) from CenterContainer to CenterContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): CenterContainerAbstract {
        var container = CenterContainer.toCenterContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}