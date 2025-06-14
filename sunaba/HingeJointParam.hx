package sunaba;

enum abstract HingeJointParam(Int) {
	var Bias = 0;
	var LimitUpper = 1;
	var LimitLower = 2;
	var LimitBias = 3;
	var LimitSoftness = 4;
	var LimitRelaxation = 5;
	var MotorTargetVelocity = 6;
	var MotorMaxImpulse = 7;
}
