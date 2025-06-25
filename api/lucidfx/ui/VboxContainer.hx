package lucidfx.ui;

import lucidfx.core.Element;

@:native("VboxContainer")
extern class VboxContainer extends BoxContainer {
    @:native("cast")
    public static function toVBoxContainer(obj: Dynamic): VboxContainer;
}

abstract VboxContainerAbstract(VboxContainer) from VboxContainer to VboxContainer {
    @:from
    public static function fromElement(element: Element): VboxContainerAbstract {
        var vBox: VboxContainer = VboxContainer.toVBoxContainer(element);
        if (vBox.isNull()) {
            return null;
        }
        return vBox;
    }
}