package sunaba.ui;

@:native("HBoxContainer")
extern class HBoxContainer extends BoxContainer {
    @:native("cast")
    public function toHBoxContainer(type: Dynamic): HBoxContainer;
}

abstract HBoxContainerAbstract(HBoxContainer) from HBoxContainer to HBoxContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): HBoxContainerAbstract {
        var hbox = HBoxContainer.toHBoxContainer(element);
        if (hbox.isNull()) {
            return null;
        }
        return hbox;
    }
}