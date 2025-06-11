package sunaba.core;

@:native("Element")
extern class Element extends BaseObject {
    public var scriptInstance: Dynamic;
    public var name: String;
    public var childEnteredTree: Event;
    public var childExitingTree: Event;
    public var childOrderChanged: Event;
    public var renamed: Event;
    public var replacingBy: Event;
    public var treeEntered: Event;
    public var treeExited: Event;
    public var treeExiting: Event;
    public function new();
    public function fine(path: String): Element;
    public function getParent(): Element;
    public function addChild(child: Element): Void;
    public function addSibling(sibling: Element): Void;
    public function removeChild(child: Element): Void;
    public function getChildren(): lua.Table<Int, Element>;
    public function isNull(): Bool;
    public function getViewport(): Viewport;
    public function delete(): Void;
    @:native("cast")
    public static function castElement(obj:Dynamic): Element;
}

abstract ElementAbstract(Element) from Element to Element {
    @:from
    public static function fromElement(element: Element): ElementAbstract {
        var element = Element.castElement(element);
        if (element.isNull()) {
            return null;
        }
        return element;
    }
}