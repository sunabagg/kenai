package kenai;

enum abstract RotationEditModeEnum(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
