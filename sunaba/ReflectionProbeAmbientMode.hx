package lucidfx;

enum abstract ReflectionProbeAmbientMode(Int) from Int to Int {
	var disabled = 0;
	var environment = 1;
	var color = 2;
}
