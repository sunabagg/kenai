package sunaba.core;

@:native("ShaderMaterial")
extern class ShaderMaterial extends Material {
    public var shader: Shader;
    public function getShaderIntParam(name: String): Int;
    public function setShaderIntParam(name: String, value: Int): Void;
    public function getShaderFloatParam(name: String): Float;
    public function setShaderFloatParam(name: String, value: Float): Void;
    public function getShaderColorParam(name: String): Color;
    public function setShaderColorParam(name: String, value: Color): Void;
    public function getShaderStringParam(name: String): String;
    public function getShaderVector2Param(name: String): Vector2;
    public function setShaderVector2Param(name: String, value: Vector2): Void;
    public function getShaderVector3Param(name: String): Vector3;
    public function setShaderVector3Param(name: String, value: Vector3): Void;
    //public function getShaderTransform2DParam(name: String): Transform2D;
    //public function setShaderTransform2DParam(name: String, value: Transform2D): Void;
    public function getShaderTransformParam(name: String): Transform;
    public function setShaderTransformParam(name: String, value: Transform): Void;
    public function getShaderTextureParam(name: String): Texture2D;
    public function setShaderTextureParam(name: String, texture: Texture2D): Void;
    @:native("cast")
    public static function castFrom(type: Dynamic) : ShaderMaterial;
}

abstract ShaderMaterialAbstract(ShaderMaterial) from ShaderMaterial to ShaderMaterial {
    @:from
    public static function fromResource(resource: Resource) : ShaderMaterialAbstract {
        var shaderMaterial = ShaderMaterial.castFrom(resource);
        if (shaderMaterial.isNull()) {
            return null;
        }
        return shaderMaterial;
    } 
}