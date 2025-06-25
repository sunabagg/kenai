package lucidfx;

enum abstract FadeMode(Int) from Int to Int {
	var disabled = 0;
	var in = 1;
	var out = 2;
	var cross = 3;
	var automatic = 4;
}
