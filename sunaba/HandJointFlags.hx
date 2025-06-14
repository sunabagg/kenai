package sunaba;

enum abstract HandJointFlags(Int) {
	var OrientationValid = 1;
	var OrientationTracked = 2;
	var PositionValid = 4;
	var PositionTracked = 8;
	var LinearVelocityValid = 16;
	var AngularVelocityValid = 32;
}
