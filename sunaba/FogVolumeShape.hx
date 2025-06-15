package sunaba;

enum abstract FogVolumeShape(Int) from Int to Int {
	var ellipsoid = 0;
	var cone = 1;
	var cylinder = 2;
	var box = 3;
	var world = 4;
	var max = 5;
}
