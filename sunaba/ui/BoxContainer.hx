package sunaba.ui;

import sunaba.core.Element;

@:native("BoxContainer")
extern class BoxContainer extends Container {
    public var alignment: Int;
    public var vertical: Bool;
    public function addSpacer(begin: Bool): Void;
    @:native("cast")
    public function toBoxContainer(type: Dynamic): BoxContainer;
}

abstract BoxContainerAbstract(BoxContainer) from BoxContainer to BoxContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): BoxContainerAbstract {
        var container = BoxContainer.toBoxContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}