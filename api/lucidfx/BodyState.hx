package lucidfx;

enum abstract BodyState(Int) from Int to Int {
	var transform = 0;
	var linearVelocity = 1;
	var angularVelocity = 2;
	var sleeping = 3;
	var canSleep = 4;
}
