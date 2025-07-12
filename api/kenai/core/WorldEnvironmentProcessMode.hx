package kenai..core;

enum abstract WorldEnvironmentProcessMode(Int) from Int to Int {
	var inherit = 0;
	var pausable = 1;
	var whenPaused = 2;
	var always = 3;
	var disabled = 4;
}
