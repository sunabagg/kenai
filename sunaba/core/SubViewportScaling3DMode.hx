package sunaba..core;

enum abstract SubViewportScaling3DMode(Int) {
	var Bilinear = 0;
	var Fsr = 1;
	var Fsr2 = 2;
	var MetalfxSpatial = 3;
	var MetalfxTemporal = 4;
	var Max = 5;
}
