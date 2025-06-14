package sunaba.ui;

import sunaba.core.io.IoManager;

class Widget {
    public var rootElement: sunaba.core.Element = null;
    public var io: IoManager;
    

    public function new() {
        init();
        io = untyped __lua__("_G.ioManager");
    }

    public function init() {
        
    }

    public function parseMarkup(markup: String): Void {
        var xml = Xml.parse(markup);
        instantiate(xml);
    }

    private function instantiate(xml: Xml): Void {
        if (rootElement != null) {
            rootElement.delete();
        }
    }
}