package lucidware.ui;

@:native("Vseparator")
extern class Vseparator extends Control {
    @:native("cast")
    public static function toVSeparator(obj: Dynamic): lucidware.ui.Vseparator;
}

abstract VseparatorAbstract(Vseparator) from Vseparator to Vseparator {
    @:from
    public static function fromElement(element: lucidware.core.Element): lucidware.ui.Vseparator {
        var vSeparator = lucidware.ui.Vseparator.toVSeparator(element);
        if (vSeparator.isNull()) {
            return null;
        }
        return vSeparator;
    }
}