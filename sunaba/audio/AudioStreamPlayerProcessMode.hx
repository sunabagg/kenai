package sunaba..audio;

enum abstract AudioStreamPlayerProcessMode(Int) {
	var Inherit = 0;
	var Pausable = 1;
	var WhenPaused = 2;
	var Always = 3;
	var Disabled = 4;
}
