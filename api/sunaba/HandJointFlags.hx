package sunaba;

enum abstract HandJointFlags(Int) from Int to Int {
	var orientationValid = 1;
	var orientationTracked = 2;
	var positionValid = 4;
	var positionTracked = 8;
	var linearVelocityValid = 16;
	var angularVelocityValid = 32;
}
