package sunaba;

import sunaba.core.Element;

@:native("Runtime")
extern class Runtime extends Element {
    public function init(?sandboxed: Bool): Void;
    public function load(path: String): Void;
    public function initMobdebug(): Void;
    public function startMobdebug(?host: String, ?port: Int): Void;
    public function stopMobdebug(): Void;
    @:native("cast")
    public static function toRuntime(obj: Any): Runtime;
}
