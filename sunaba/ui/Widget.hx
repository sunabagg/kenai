package sunaba.ui;

import sunaba.core.io.IoManager;

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
            var firstElement = xml.firstElement();
            if (firstElement != null) {
                if (firstElement.nodeName == "suml") {
                    var fullScreenAtt = firstElement.get("fullscreen");
                    if (fullScreenAtt == "true") {
                        //rootElement.setAnchorsAndOffsetsPreset
                    }
                }
                else {
                    throw "Invalid root element: " + firstElement.nodeName;
                }
            }
        }

        
    }
}