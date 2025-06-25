package lucidfx;

enum abstract BoneDirection(Int) from Int to Int {
	var plusX = 0;
	var minusX = 1;
	var plusY = 2;
	var minusY = 3;
	var plusZ = 4;
	var minusZ = 5;
	var fromParent = 6;
}
