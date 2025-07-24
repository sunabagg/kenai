package sunaba.core;
import sunaba.desktop.Window;

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
    public function find(path: String): Element;
    public function getParent(): Element;
    public function addChild(child: Element): Void;
    public function addSibling(sibling: Element): Void;
    public function removeChild(child: Element): Void;
    public function getIndex(includeInternal: Bool = false): Int;
    public function getChildren(): Vector<Element>;
    public function isNull(): Bool;
    public function getViewport(): Viewport;
    public function getWindow(): Window;
    public function delete(): Void;
    @:native("cast")
    public static function castElement(obj:Dynamic): Element;
    public static function isElementType(): Bool;
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