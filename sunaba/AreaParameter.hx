package sunaba;

enum abstract AreaParameter(Int) {
	var GravityOverrideMode = 0;
	var Gravity = 1;
	var GravityVector = 2;
	var GravityIsPoint = 3;
	var GravityPointUnitDistance = 4;
	var LinearDampOverrideMode = 5;
	var LinearDamp = 6;
	var AngularDampOverrideMode = 7;
	var AngularDamp = 8;
	var Priority = 9;
	var WindForceMagnitude = 10;
	var WindSource = 11;
	var WindDirection = 12;
	var WindAttenuationFactor = 13;
}
