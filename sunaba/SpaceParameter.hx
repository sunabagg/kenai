package sunaba;

enum abstract SpaceParameter(Int) {
	var ContactRecycleRadius = 0;
	var ContactMaxSeparation = 1;
	var ContactMaxAllowedPenetration = 2;
	var ContactDefaultBias = 3;
	var BodyLinearVelocitySleepThreshold = 4;
	var BodyAngularVelocitySleepThreshold = 5;
	var BodyTimeToSleep = 6;
	var SolverIterations = 7;
}
