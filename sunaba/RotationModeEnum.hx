package lucidware;

enum abstract RotationModeEnum(Int) from Int to Int {
	var none = 0;
	var y = 1;
	var xy = 2;
	var xyz = 3;
	var oriented = 4;
}
