package lucidfx;

enum abstract AudioStreamGeneratorMixRate(Int) from Int to Int {
	var output = 0;
	var input = 1;
	var custom = 2;
	var max = 3;
}
