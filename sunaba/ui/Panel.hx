package lucidware.ui;

@:native("Panel")
extern class Panel extends Control {
    @:native("cast")
    public static function toPanel(obj: Dynamic): lucidware.ui.Panel;
}

abstract PanelAbstract(Panel) from Panel to Panel {
    @:from
    public static function fromElement(element: lucidware.core.Element): PanelAbstract {
        var panel = lucidware.ui.Panel.toPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}