package sunaba.ui;

import sunaba.core.Element;

@:native("VBoxContainer")
extern class VBoxContainer extends BoxContainer {
    @:native("cast")
    public static function toVBoxContainer(obj: Dynamic): VBoxContainer;
}

abstract VBoxContainerAbstract(VBoxContainer) from VBoxContainer to VBoxContainer {
    @:from
    public static function fromElement(element: Element): VBoxContainerAbstract {
        var vBox: VBoxContainer = VBoxContainer.toVBoxContainer(element);
        if (vBox.isNull()) {
            return null;
        }
        return vBox;
    }
}