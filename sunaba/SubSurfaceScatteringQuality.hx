package lucidware;

enum abstract SubSurfaceScatteringQuality(Int) from Int to Int {
	var disabled = 0;
	var low = 1;
	var medium = 2;
	var high = 3;
}
