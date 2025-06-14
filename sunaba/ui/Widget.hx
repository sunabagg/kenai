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
                else {
                    var anchorTopAtt = firstElement.get("anchorTop");
                    if (anchorTopAtt != null) {
                        rootElement.anchorTop = Std.parseFloat(anchorTopAtt);
                    }
                    var anchorLeftAtt = firstElement.get("anchorLeft");
                    if (anchorLeftAtt != null) {
                        rootElement.anchorLeft = Std.parseFloat(anchorLeftAtt);
                    }
                    var anchorBottomAtt = firstElement.get("anchorBottom");
                    if (anchorBottomAtt != null) {
                        rootElement.anchorBottom = Std.parseFloat(anchorBottomAtt);
                    }
                    var anchorRightAtt = firstElement.get("anchorRight");
                    if (anchorRightAtt != null) {
                        rootElement.anchorRight = Std.parseFloat(anchorRightAtt);
                    }

                    var offsetTopAtt = firstElement.get("offsetTop");
                    if (offsetTopAtt != null) {
                        rootElement.offsetTop = Std.parseFloat(offsetTopAtt);
                    }
                    var offsetLeftAtt = firstElement.get("offsetLeft");
                    if (offsetLeftAtt != null) {
                        rootElement.offsetLeft = Std.parseFloat(offsetLeftAtt);
                    }
                    var offsetBottomAtt = firstElement.get("offsetBottom");
                    if (offsetBottomAtt != null) {
                        rootElement.offsetBottom = Std.parseFloat(offsetBottomAtt);
                    }
                    var offsetRightAtt = firstElement.get("offsetRight");
                    if (offsetRightAtt != null) {
                        rootElement.offsetRight = Std.parseFloat(offsetRightAtt);
                    }
                }

                var nameAtt = firstElement.get("name");
                if (nameAtt != null) {
                    rootElement.name = nameAtt;
                }

                var children = firstElement.elements();
                for (child in children) {
                    if (child.nodeName == "head") {
                        for (headChild in child.elements()) {
                            if (headChild.nodeName == "style") {
                                //
                            }
                        }
                    }
                }

            }
            else {
                throw "Invalid root element: " + firstElement.nodeName;
            }
        }
    }
}