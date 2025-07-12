package kenai.ui;

@:native("PanelContainer")
extern class PanelContainer extends Container {
    @:native("cast")
    public static function toPanelContainer(obj: Dynamic): kenai.ui.PanelContainer;
}

abstract PanelContainerAbstract(PanelContainer) from PanelContainer to PanelContainer {
    @:from
    public static function fromElement(element: kenai.core.Element): kenai.ui.PanelContainer {
        var panelContainer = kenai.ui.PanelContainer.toPanelContainer(element);
        if (panelContainer.isNull()) {
            return null;
        }
        return panelContainer;
    }
}