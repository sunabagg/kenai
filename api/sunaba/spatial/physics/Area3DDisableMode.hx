package sunaba..spatial.physics;

enum abstract Area3DDisableMode(Int) from Int to Int {
	var remove = 0;
	var makeStatic = 1;
	var keepActive = 2;
}
