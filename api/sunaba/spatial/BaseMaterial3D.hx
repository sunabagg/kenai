package sunaba.spatial;

import sunaba.core.Vector3;
import sunaba.core.Material;
import sunaba.core.Color;
import sunaba.core.Texture2D;

@:native("BaseMaterial3D")
extern class BaseMaterial3D extends Material {
    public var albedoColor: Color;
    public var albedoTexture: Texture2D;
    public var albedoTextureForceSrgb: Bool;
    public var albedoTextureMsdf: Bool;
    public var alphaAntialiasingEdge: Float;
    public var alphaAntialiasingMode: Int;
    public var alphaHashScale: Int;
    public var alphaScissorThreshold: Float;
    public var anisotropy: Float;
    public var anisotropyEnabled: Bool;
    public var anisotropyFlowmap: Texture2D;
    public var aoEnabled: Bool;
    public var aoLightAffect: Float;
    public var aoOnUv2: Bool;
    public var aoTexture: Texture2D;
    public var aoTextureChannel: Int;
    public var backlight: Color;
    public var backlightEnabled: Bool;
    public var backlightTexture: Texture2D;
    public var billboardKeepScale: Bool;
    public var billboardMode: Int;
    public var blendMode: Int;
    public var clearcoat: Float;
    public var clearcoatEnabled: Bool;
    public var clearcoatRoughness: Float;
    public var clearcoatTexture: Texture2D;
    public var cullMode: Int;
    public var depthDrawMode: Int;
    public var detailAlbedo: Texture2D;
    public var detailBlendMode: Int;
    public var detailEnabled: Bool;
    public var detailMask: Texture2D;
    public var detailNormal: Texture2D;
    public var detailUvLayer: Int;
    public var diffuseMode: Int;
    public var disableAmbientLight: Bool;
    public var disableFog: Bool;
    public var disableReceiveShadows: Bool;
    public var distanceFadeMaxDistance: Float;
    public var distanceFadeMinDistance: Float;
    public var distanceFadeMode: Int;
    public var emission: Color;
    public var emissionEnabled: Bool;
    public var emissionEnergyMultiplier: Float;
    public var emissionIntensity: Float;
    public var emissionOnUv2: Bool;
    public var emissionOperator: Int;
    public var emissionTexture: Texture2D;
    public var fixedSize: Bool;
    public var grow: Bool;
    public var growAmount: Float;
    public var heightmapDeepParallax: Float;
    public var heightmapEnabled: Bool;
    public var heightmapFlipBinormal: Bool;
    public var heightmapFlipTangent: Bool;
    public var heightmapFlipTexture: Bool;
    public var heightmapMaxLayers: Int;
    public var heightmapMinLayers: Int;
    public var heightmapScale: Float;
    public var heightmapTexture: Texture2D;
    public var metallic: Float;
    public var metallicSpecular: Float;
    public var metallicTexture: Texture2D;
    public var metallicTextureChannel: Int;
    public var msdfOutlineSize: Float;
    public var msdfPixelRange: Float;
    public var noDepthTest: Bool;
    public var normalEnabled: Bool;
    public var normalScale: Float;
    public var normalTexture: Texture2D;
    public var ormTexture: Texture2D;
    public var particlesAnimHFrames: Int;
    public var particlesAnimVFrames: Int;
    public var particlesAnimLoop: Bool;
    public var pointSize: Float;
    public var proximityFadeDistance: Float;
    public var proximityFadeEnabled: Bool;
    public var refractionEnabled: Bool;
    public var refractionScale: Float;
    public var refractionTexture: Texture2D;
    public var refractionTextureChannel: Int;
    public var rim: Float;
    public var rimEnabled: Bool;
    public var rimTexture: Texture2D;
    public var rimTint: Float;
    public var roughness: Float;
    public var roughnessTexture: Texture2D;
    public var roughnessTextureChannel: Int;
    public var shadingMode: Int;
    public var shadowToOpacity: Float;
    public var specularMode: Int;
    public var subsurfScatterEnabled: Bool;
    public var subsurfScatterSkinMode: Int;
    public var subsurfScatterStrength: Float;
    public var subsurfScatterTexture: Texture2D;
    public var subsurfScatterTransmittanceBoost: Float;
    public var subsurfScatterTransmittanceColor: Color;
    public var subsurfScatterTransmittanceDepth: Float;
    public var subsurfScatterTransmittanceEnabled: Bool;
    public var subsurfScatterTransmittanceTexture: Texture2D;
    public var textureFilter: Int;
    public var textureRepeat: Bool;
    public var transparency: Int;
    public var useParticleTrails: Bool;
    public var usePointSize: Bool;
    public var uv1Offset: Vector3;
    public var uv1Scale: Vector3;
    public var uv1Triplanar: Bool;
    public var uv1TriplanarSharpness: Float;
    public var uv1WorldTriplanar: Bool;
    public var uv2Offset: Vector3;
    public var uv2Scale: Vector3;
    public var uv2Triplanar: Bool;
    public var uv2TriplanarSharpness: Float;
    public var uv2WorldTriplanar: Bool;
    public var vertexColorIsSrgb: Bool;
    public var VertexColorUseAsAlbedo: Bool;
    public function getFeature(feature: Int): Bool;
    public function getFlag(flag: Int): Bool;
    public function getTexture(texture: Int): Texture2D;
    public function setFeature(feature: Int, value: Bool): Void;
    public function setFlag(flag: Int, value: Bool): Void;
    public function setTexture(texture: Int, value: Texture2D): Void;
    @:native("cast")
    public static function castFrom(res: Dynamic): BaseMaterial3D;
}

abstract BaseMaterial3DAbstract(BaseMaterial3D) from BaseMaterial3D to BaseMaterial3D {
    @:from
    public static function fromResource(resource: Resource) : BaseMaterial3DAbstract {
        var baseMaterial3D = BaseMaterial3D.castFrom(resource);
        if (baseMaterial3D.isNull()) {
            return null;
        }
        return baseMaterial3D;
    }
} // end package sunaba.spatial