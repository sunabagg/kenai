package lucidfx;

enum abstract EnableModeEnum(Int) from Int to Int {
	var inherit = 0;
	var always = 1;
	var whenPaused = 2;
}
