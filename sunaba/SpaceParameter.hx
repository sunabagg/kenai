package lucidware;

enum abstract SpaceParameter(Int) from Int to Int {
	var contactRecycleRadius = 0;
	var contactMaxSeparation = 1;
	var contactMaxAllowedPenetration = 2;
	var contactDefaultBias = 3;
	var bodyLinearVelocitySleepThreshold = 4;
	var bodyAngularVelocitySleepThreshold = 5;
	var bodyTimeToSleep = 6;
	var solverIterations = 7;
}
