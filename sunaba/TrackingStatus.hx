package sunaba;

enum abstract TrackingStatus(Int) {
	var NormalTracking = 0;
	var ExcessiveMotion = 1;
	var InsufficientFeatures = 2;
	var UnknownTracking = 3;
	var NotTracking = 4;
}
