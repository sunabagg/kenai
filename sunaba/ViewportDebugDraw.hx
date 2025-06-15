package sunaba;

enum abstract ViewportDebugDraw(Int) from Int to Int {
	var disabled = 0;
	var unshaded = 1;
	var lighting = 2;
	var overdraw = 3;
	var wireframe = 4;
	var normalBuffer = 5;
	var voxelGiAlbedo = 6;
	var voxelGiLighting = 7;
	var voxelGiEmission = 8;
	var shadowAtlas = 9;
	var directionalShadowAtlas = 10;
	var sceneLuminance = 11;
	var ssao = 12;
	var ssil = 13;
	var pssmSplits = 14;
	var decalAtlas = 15;
	var sdfgi = 16;
	var sdfgiProbes = 17;
	var giBuffer = 18;
	var disableLod = 19;
	var clusterOmniLights = 20;
	var clusterSpotLights = 21;
	var clusterDecals = 22;
	var clusterReflectionProbes = 23;
	var occluders = 24;
	var motionVectors = 25;
	var internalBuffer = 26;
}
