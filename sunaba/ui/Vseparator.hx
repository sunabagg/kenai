package sunaba.ui;

@:native("Vseparator")
extern class Vseparator extends Control {
    @:native("cast")
    public static function toVSeparator(obj: Dynamic): sunaba.ui.Vseparator;
}

abstract VseparatorAbstract(Vseparator) from Vseparator to Vseparator {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.Vseparator {
        var vSeparator = sunaba.ui.Vseparator.toVSeparator(element);
        if (vSeparator.isNull()) {
            return null;
        }
        return vSeparator;
    }
}