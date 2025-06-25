package sunaba.core.io;

@:native("IoManager")
extern class IoManager extends IoInterface {
    public function new();
    public function add(ioInterface: IoInterface): Void;
    public function remove(ioInterface: IoInterface): Void;
    public function getFileUri(path: String, base_uri: String): String;
}