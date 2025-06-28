package sunaba;

import sunaba.core.Element;

@:native("Runtime")
extern class Runtime extends Element {
    public function init(?sandboxed: Bool): Void;

}
