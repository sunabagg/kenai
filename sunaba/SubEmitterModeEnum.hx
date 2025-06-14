package sunaba;

enum abstract SubEmitterModeEnum(Int) {
	var Disabled = 0;
	var Constant = 1;
	var AtEnd = 2;
	var AtCollision = 3;
	var AtStart = 4;
	var Max = 5;
}
