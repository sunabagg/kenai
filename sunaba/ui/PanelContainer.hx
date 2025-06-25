package lucidware.ui;

@:native("PanelContainer")
extern class PanelContainer extends Container {
    @:native("cast")
    public static function toPanelContainer(obj: Dynamic): lucidware.ui.PanelContainer;
}

abstract PanelContainerAbstract(PanelContainer) from PanelContainer to PanelContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.PanelContainer {
        var panelContainer = lucidware.ui.PanelContainer.toPanelContainer(element);
        if (panelContainer.isNull()) {
            return null;
        }
        return panelContainer;
    }
}