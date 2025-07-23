package sunaba;

import sunaba.core.Element;

@:generic
function CastElement<T>(eclass: Class<T>, e: Element) {
    var castedE : T = untyped __lua__("eclass.cast(e)");
    return castedE;
}