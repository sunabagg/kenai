package lucidfx;

enum abstract SubEmitterModeEnum(Int) from Int to Int {
	var disabled = 0;
	var constant = 1;
	var atEnd = 2;
	var atCollision = 3;
	var atStart = 4;
	var max = 5;
}
