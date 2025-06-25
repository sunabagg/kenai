package lucidfx;

enum abstract ViewportEnvironmentMode(Int) from Int to Int {
	var disabled = 0;
	var enabled = 1;
	var inherit = 2;
	var max = 3;
}
