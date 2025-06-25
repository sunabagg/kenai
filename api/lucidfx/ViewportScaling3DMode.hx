package lucidfx;

enum abstract ViewportScaling3DMode(Int) from Int to Int {
	var bilinear = 0;
	var fsr = 1;
	var fsr2 = 2;
	var metalfxSpatial = 3;
	var metalfxTemporal = 4;
	var max = 5;
}
