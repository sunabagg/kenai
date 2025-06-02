package sunaba.ui;

@:native("PanelContainer")
extern class PanelContainer extends Container {
    @:native("cast")
    public static function toPanelContainer(obj: Dynamic): sunaba.ui.PanelContainer;
}

abstract PanelContainerAbstract(PanelContainer) from PanelContainer to PanelContainer {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.PanelContainer {
        var panelContainer = sunaba.ui.PanelContainer.toPanelContainer(element);
        if (panelContainer.isNull()) {
            return null;
        }
        return panelContainer;
    }
}