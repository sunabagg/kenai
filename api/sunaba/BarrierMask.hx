package sunaba;

enum abstract BarrierMask(Int) from Int to Int {
	var vertex = 1;
	var compute = 2;
	var transfer = 4;
	var fragment = 8;
	var raster = 9;
	var allBarriers = 32767;
	var noBarrier = 32768;
}
