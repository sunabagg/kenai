package sunaba;

import sunaba.core.GlobalObjectStack;
import sunaba.core.Element;

class App {
    public var rootElement(get, default): Element;
    private function get_rootElement(): Element {
        return untyped __lua__("_G.rootElement");
    }

    public var globalObjectStack(get, default): GlobalObjectStack;
    private function get_globalObjectStack(): GlobalObjectStack {
        return GlobalObjectStack.getSingleton();
    }

    public var execDir(get, default): String;
    private function get_execDir(): String {
        return untyped __lua__("_G.execDir");
    }

    public function new() {
        GlobalObjectStack.initSingleton();
        init();
    }

    public function init() {
        
    }
}