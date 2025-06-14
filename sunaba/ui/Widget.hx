package sunaba.ui;

import sunaba.core.Element;
import lua.Table;
import sunaba.core.io.IoManager;
import sunaba.LayoutPreset;
import sunaba.LayoutPresetMode;

class Widget {
    public var rootElement: Control;
    public var io: IoManager;
    

    public function new() {
        io = untyped __lua__("_G.ioManager");
        rootElement = new Control();

        init();
    }

    public function init() {
        
    }

    public function parseMarkup(markup: String): Void {
        var xml = Xml.parse(markup);
        instantiate(xml);
    }

    private function instantiate(xml: Xml): Void {
        if (rootElement != null) {
            var childrenTable : Table<Int, Element> = rootElement.getChildren();
            var children : Array<Element> = Table.toArray(childrenTable);
            for (i in 0... children.length) {
                var child = children[i];
                if (child != null) {
                    child.delete();
                }
            }
        }

        var firstElement = xml.firstElement();
        if (firstElement != null) {
            if (firstElement.nodeName == "suml") {
                var fullScreenAtt = firstElement.get("fullscreen");
                if (fullScreenAtt == "true") {
                    rootElement.setAnchorsAndOffsetsPreset(cast LayoutPreset.FullRect, cast LayoutPresetMode.KeepSize);
                    rootElement.sizeFlagsHorizontal = cast SizeFlags.Fill;
                    rootElement.sizeFlagsVertical = cast SizeFlags.Fill;
                }
            }
            else {
                throw "Invalid root element: " + firstElement.nodeName;
            }
        }
    }
}