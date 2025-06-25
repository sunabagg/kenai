package lucidware.core;

@:native("ShaderInclude")
extern class ShaderInclude extends Resource {
    public var code: String;
    @:native("cast")
    public static function castFrom(type: Dynamic) : ShaderInclude;
}

abstract ShaderIncludeAbstract(ShaderInclude) from ShaderInclude to ShaderInclude {
    @:from
    public static function fromResource(resource: Resource) : ShaderIncludeAbstract {
        var shaderInclude = ShaderInclude.castFrom(resource);
        if (shaderInclude.isNull()) {
            return null;
        }
        return shaderInclude;
    } 
}