package sunaba.core;

class GlobalObjectStack {
    public var stack : Array<StackHandle>;

    public static function getSingleton() {
        return untyped __lua__("_G.globalObjectStack");
    }

    public static function initSingleton() {
        var singleton = new GlobalObjectStack();
        untyped __lua__("_G.globalObjectStack = singleton");
    }

    public function new() {
        stack = [];
    }
}