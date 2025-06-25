package sunaba;

enum abstract BodyMode(Int) from Int to Int {
	var static = 0;
	var kinematic = 1;
	var rigid = 2;
	var rigidLinear = 3;
}
