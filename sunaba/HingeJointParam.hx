package lucidware;

enum abstract HingeJointParam(Int) from Int to Int {
	var bias = 0;
	var limitUpper = 1;
	var limitLower = 2;
	var limitBias = 3;
	var limitSoftness = 4;
	var limitRelaxation = 5;
	var motorTargetVelocity = 6;
	var motorMaxImpulse = 7;
}
