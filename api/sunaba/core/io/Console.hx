package sunaba.core.io;

import haxe.macro.Expr.Function;

@:native("Console")
extern class Console extends Element {
    public var ioInterface: IoInterface;
    public final logs: Vector<String>;
    public var logHandler: Function;
}