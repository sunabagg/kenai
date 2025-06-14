package sunaba;

enum abstract JointFlags(Int) {
	var OrientationValid = 1;
	var OrientationTracked = 2;
	var PositionValid = 4;
	var PositionTracked = 8;
}
