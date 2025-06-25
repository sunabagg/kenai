package sunaba;

enum abstract LoopModeEnum(Int) from Int to Int {
	var disabled = 0;
	var forward = 1;
	var pingpong = 2;
	var backward = 3;
}
