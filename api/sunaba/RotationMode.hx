package sunaba;

enum abstract RotationMode(Int) from Int to Int {
	var resetFullRotation = 0;
	var resetButKeepTilt = 1;
	var dontResetRotation = 2;
}
