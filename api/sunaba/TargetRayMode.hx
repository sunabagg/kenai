package sunaba;

enum abstract TargetRayMode(Int) from Int to Int {
	var unknown = 0;
	var gaze = 1;
	var trackedPointer = 2;
	var screen = 3;
}
