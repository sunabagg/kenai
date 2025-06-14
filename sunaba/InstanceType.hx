package sunaba;

enum abstract InstanceType(Int) {
	var None = 0;
	var Mesh = 1;
	var Multimesh = 2;
	var Particles = 3;
	var ParticlesCollision = 4;
	var Light = 5;
	var ReflectionProbe = 6;
	var Decal = 7;
	var VoxelGI = 8;
	var Lightmap = 9;
	var Occluder = 10;
	var VisiblityNotifier = 11;
	var FogVolume = 12;
	var Max = 13;
	var GeometryMask = 14;
}
