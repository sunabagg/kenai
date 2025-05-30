package sunaba.ui;

import sunaba.core.Element;

@:native("CenterContainer")
extern class CenterContainer extends Container {
    public var useTopLeft: Bool;
    @:native("cast")
    public function toCenterContainer(type: Dynamic): CenterContainer;
}

abstract CenterContainerAbstract(CenterContainer) from CenterContainer to CenterContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): CenterContainerAbstract {
        var container = CenterContainer.toCenterContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}