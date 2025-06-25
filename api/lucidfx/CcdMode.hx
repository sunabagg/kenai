package lucidfx;

enum abstract CcdMode(Int) from Int to Int {
	var disabled = 0;
	var castRay = 1;
	var castShape = 2;
}
