package sunaba;

enum abstract BarrierMask(Int) {
	var Vertex = 1;
	var Compute = 2;
	var Transfer = 4;
	var Fragment = 8;
	var Raster = 9;
	var AllBarriers = 32767;
	var NoBarrier = 32768;
}
