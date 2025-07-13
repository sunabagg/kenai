package sunaba.core.io;

@:native("Console")
extern class Console extends Element {
    public var ioInterface: IoInterface;
    public final logs: Vector<String>;
}