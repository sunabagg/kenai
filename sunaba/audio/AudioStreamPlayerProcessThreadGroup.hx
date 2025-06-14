package sunaba..audio;

enum abstract AudioStreamPlayerProcessThreadGroup(Int) {
	var Inherit = 0;
	var MainThread = 1;
	var SubThread = 2;
}
