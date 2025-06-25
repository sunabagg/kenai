package lucidware.core;

@:native("Shader")
extern class Shader extends Resource {
    public var code: String;
    public function getDefaultTextureParameter(name: String, index: Int = 0): Texture2D;
    public function getMode(): Int;
    public function getShaderUniformLis() : ArrayList;
    public function setDefaultTextureParameter(name: String, texture: Texture2D, index: Int = 0): Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : Shader;
}

abstract ShaderAbstract(Shader) from Shader to Shader {
    @:from
    public static function fromResource(resource: Resource) : ShaderAbstract {
        var shader = Shader.castFrom(resource);
        if (shader.isNull()) {
            return null;
        }
        return shader;
    } 
    
}