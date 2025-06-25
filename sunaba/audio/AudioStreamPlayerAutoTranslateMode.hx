package lucidfx..audio;

enum abstract AudioStreamPlayerAutoTranslateMode(Int) from Int to Int {
	var inherit = 0;
	var always = 1;
	var disabled = 2;
}
