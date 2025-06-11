package sunaba;

import sunaba.core.Element;

class App {
    public var rootElement(get, default): Element;
    private function get_rootElement(): Element {
        return untyped __lua__("_G.rootElement");
    }

    public function new() {
        init();
    }

    public function init() {
        
    }
}