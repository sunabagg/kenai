package lucidfx;

enum abstract EnvironmentBlendModeEnum(Int) from Int to Int {
	var opaque = 0;
	var additive = 1;
	var alphaBlend = 2;
}
