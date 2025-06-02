package sunaba.ui;

@:native("VSeparator")
extern class VSeparator extends Control {
    @:native("cast")
    public static function toVSeparator(obj: Dynamic): sunaba.ui.VSeparator;
}

abstract VSeparatorAbstract(VSeparator) from VSeparator to VSeparator {
    @:from
    public static function fromElement(element: sunaba.core.Element): sunaba.ui.VSeparator {
        var vSeparator = sunaba.ui.VSeparator.toVSeparator(element);
        if (vSeparator.isNull()) {
            return null;
        }
        return vSeparator;
    }
}