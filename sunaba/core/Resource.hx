package sunaba.core;

@:native("Resource")
extern class Resource extends BaseObject {
    public function duplicate() : Resource;
    public function emitChanged() : Void;
    public function isNull() : Bool;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Resource;
}

abstract ResourceAbstarct(Resource) from Resource to Resource {
    @:from
    public static function fromResource(resource: Resource) : ResourceAbstarct {
        return Resource.castFrom(resource);
    } 
}