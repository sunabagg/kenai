package sunaba.core.io;

@:native("IoManager")
extern class IoManager extends IoInterface {
    public function new();
    public function add(ioInterface: IoInterface): Void;
}