package lucidware;

enum abstract TrackingStatus(Int) from Int to Int {
	var normalTracking = 0;
	var excessiveMotion = 1;
	var insufficientFeatures = 2;
	var unknownTracking = 3;
	var notTracking = 4;
}
