package sunaba..desktop;

enum abstract WindowDebugDraw(Int) {
	var Disabled = 0;
	var Unshaded = 1;
	var Lighting = 2;
	var Overdraw = 3;
	var Wireframe = 4;
	var NormalBuffer = 5;
	var VoxelGIAlbedo = 6;
	var VoxelGILighting = 7;
	var VoxelGIEmission = 8;
	var ShadowAtlas = 9;
	var DirectionalShadowAtlas = 10;
	var SceneLuminance = 11;
	var Ssao = 12;
	var Ssil = 13;
	var PssmSplits = 14;
	var DecalAtlas = 15;
	var Sdfgi = 16;
	var SdfgiProbes = 17;
	var GIBuffer = 18;
	var DisableLod = 19;
	var ClusterOmniLights = 20;
	var ClusterSpotLights = 21;
	var ClusterDecals = 22;
	var ClusterReflectionProbes = 23;
	var Occluders = 24;
	var MotionVectors = 25;
	var InternalBuffer = 26;
}
