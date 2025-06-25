package lucidfx;

enum abstract EnvironmentGlowBlendMode(Int) from Int to Int {
	var additive = 0;
	var screen = 1;
	var softlight = 2;
	var replace = 3;
	var mix = 4;
}
