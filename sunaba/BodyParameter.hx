package lucidware;

enum abstract BodyParameter(Int) from Int to Int {
	var bounce = 0;
	var friction = 1;
	var mass = 2;
	var inertia = 3;
	var centerOfMass = 4;
	var gravityScale = 5;
	var linearDampMode = 6;
	var angularDampMode = 7;
	var linearDamp = 8;
	var angularDamp = 9;
	var max = 10;
}
