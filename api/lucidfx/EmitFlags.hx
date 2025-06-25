package lucidfx;

enum abstract EmitFlags(Int) from Int to Int {
	var position = 1;
	var rotScale = 2;
	var velocity = 4;
	var color = 8;
	var custom = 16;
}
