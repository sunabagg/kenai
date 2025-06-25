package sunaba;

enum abstract G6DofJointAxisFlag(Int) from Int to Int {
	var enableLinearLimit = 0;
	var enableAngularLimit = 1;
	var enableAngularSpring = 2;
	var enableLinearSpring = 3;
	var enableMotor = 4;
	var enableLinearMotor = 5;
	var max = 6;
}
