package sunaba;

import sunaba.core.Vector;
import sunaba.core.Element;

@:native("Runtime")
extern class Runtime extends Element {
    public var args: Vector<String>;
    public function init(?sandboxed: Bool): Void;
    public function load(path: String): Void;
    public function initMobdebug(): Void;
    public function startMobdebug(?host: String, ?port: Int): Void;
    public function stopMobdebug(): Void;
    @:native("cast")
    public static function toRuntime(obj: Any): Runtime;
}

abstract RuntimeAbstract(Runtime) from Runtime to Runtime {
    @:from
    public static function fromElement(e: Element): RuntimeAbstract {
        var runtime = Runtime.toRuntime(e);
        if (e.isNull())
            return null;
        return runtime;
    }
}
