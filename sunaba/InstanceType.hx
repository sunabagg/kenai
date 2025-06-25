package lucidware;

enum abstract InstanceType(Int) from Int to Int {
	var none = 0;
	var mesh = 1;
	var multimesh = 2;
	var particles = 3;
	var particlesCollision = 4;
	var light = 5;
	var reflectionProbe = 6;
	var decal = 7;
	var voxelGi = 8;
	var lightmap = 9;
	var occluder = 10;
	var visiblityNotifier = 11;
	var fogVolume = 12;
	var max = 13;
	var geometryMask = 14;
}
