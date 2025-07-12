package kenai;

import kenai.core.Element;

class App {
    public var rootElement(get, default): Element;
    private function get_rootElement(): Element {
        return untyped __lua__("_G.rootElement");
    }

    public static var execDir(get, default): String;
    private static function get_execDir(): String {
        return untyped __lua__("_G.execDir");
    }

    public static var resDir(get, default): String;
    private static function get_resDir(): String {
        return untyped __lua__("_G.resDir");
    }
    
    public static var shareDir(get, default): String;
    private static function get_shareDir(): String {
        return untyped __lua__("_G.shareDir");
    }

    public function new() {
        init();
    }

    public function init() {
        
    }

    public static function exit() {
        untyped __lua__("_G.exit()");
    }
}