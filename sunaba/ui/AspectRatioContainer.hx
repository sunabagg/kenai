package lucidware.ui;

import lucidware.core.Element;

@:native("AspectRatioContainer")
extern class AspectRatioContainer extends Container {
    public var alignmentHorizontal: Int;
    public var alignmentVertical: Int;
    public var ratio: Float;
    public var stretchMode: Int;
    @:native("cast")
    public static function toAspectRatioContainer(type: Dynamic): AspectRatioContainer;
}

abstract AspectRatioContainerAbstract(AspectRatioContainer) from AspectRatioContainer to AspectRatioContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): AspectRatioContainerAbstract {
        var container = AspectRatioContainer.toAspectRatioContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}