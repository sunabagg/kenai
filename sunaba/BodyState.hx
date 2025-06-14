package sunaba;

enum abstract BodyState(Int) {
	var Transform = 0;
	var LinearVelocity = 1;
	var AngularVelocity = 2;
	var Sleeping = 3;
	var CanSleep = 4;
}
