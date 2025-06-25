package lucidware.core;

class GlobalObjectStack {
    public var stack : Array<StackHandle>;

    public static function getSingleton() : GlobalObjectStack {
        var gos : GlobalObjectStack = untyped __lua__("_G.globalObjectStack");
        if (gos == null) {
            initSingleton();
            gos = untyped __lua__("_G.globalObjectStack");
            if (gos == null) {
                throw "GlobalObjectStack is not initialized";
            }
        }

        return gos;
    }

    public static function initSingleton() {
        var singleton = new GlobalObjectStack();
        untyped __lua__("_G.globalObjectStack = singleton");
    }

    public function new() {
        stack = [];
    }
}