package lucidfx;

enum abstract BodyAxis(Int) from Int to Int {
	var linearX = 1;
	var linearY = 2;
	var linearZ = 4;
	var angularX = 8;
	var angularY = 16;
	var angularZ = 32;
}
