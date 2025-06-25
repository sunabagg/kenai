package lucidfx;

enum abstract AreaParameter(Int) from Int to Int {
	var gravityOverrideMode = 0;
	var gravity = 1;
	var gravityVector = 2;
	var gravityIsPoint = 3;
	var gravityPointUnitDistance = 4;
	var linearDampOverrideMode = 5;
	var linearDamp = 6;
	var angularDampOverrideMode = 7;
	var angularDamp = 8;
	var priority = 9;
	var windForceMagnitude = 10;
	var windSource = 11;
	var windDirection = 12;
	var windAttenuationFactor = 13;
}
