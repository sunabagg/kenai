package sunaba.core.io;

import haxe.Constraints.Function;

@:native("Console")
extern class Console extends Element {
    public var ioInterface: IoInterface;
    public final logs: Vector<String>;
    public var logHandler: Function;
    public function addCommand(cmdNamd: String, func: Function): Void;
    public function getLogColor(log: String): Color;
    public function cmd(command: String, args: Vector<String>): Error;
    public function eval(code: String): Error;
}