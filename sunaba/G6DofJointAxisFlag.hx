package sunaba;

enum abstract G6DofJointAxisFlag(Int) {
	var EnableLinearLimit = 0;
	var EnableAngularLimit = 1;
	var EnableAngularSpring = 2;
	var EnableLinearSpring = 3;
	var EnableMotor = 4;
	var EnableLinearMotor = 5;
	var Max = 6;
}
