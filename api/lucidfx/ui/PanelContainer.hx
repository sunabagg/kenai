package lucidfx.ui;

@:native("PanelContainer")
extern class PanelContainer extends Container {
    @:native("cast")
    public static function toPanelContainer(obj: Dynamic): lucidfx.ui.PanelContainer;
}

abstract PanelContainerAbstract(PanelContainer) from PanelContainer to PanelContainer {
    @:from
    public static function fromElement(element: lucidfx.core.Element): lucidfx.ui.PanelContainer {
        var panelContainer = lucidfx.ui.PanelContainer.toPanelContainer(element);
        if (panelContainer.isNull()) {
            return null;
        }
        return panelContainer;
    }
}