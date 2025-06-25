package lucidware..spatial.physics;

enum abstract PhysicsBody3DDisableMode(Int) from Int to Int {
	var remove = 0;
	var makeStatic = 1;
	var keepActive = 2;
}
