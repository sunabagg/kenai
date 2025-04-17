package sunaba.core;

@:native("Element")
extern class Element extends BaseObject {
    public var scriptInstance: ScriptInstance;
    public var name: String;
    public function new();
    public function fine(path: String): Element;
    public function getParent(): Element;
    public function addChild(child: Element): Void;
    public function addSibling(sibling: Element): Void;
    public function removeChild(child: Element): Void;
    public function getChildren(): Array<Element>;
    @:native("cast")
    public static function castElement(): Element;
}

abstract ElementAbstract(Element) from Element to Element {
    @:from
    public static function fromElement(element: Element): ElementAbstract {
        return Element.castElement(element);
    }
}