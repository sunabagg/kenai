package lucidware;

enum abstract LookupResultType(Int) from Int to Int {
	var scriptLocation = 0;
	var class = 1;
	var classConstant = 2;
	var classProperty = 3;
	var classMethod = 4;
	var classSignal = 5;
	var classEnum = 6;
	var classTbdGlobalscope = 7;
	var classAnnotation = 8;
	var localConstant = 9;
	var localVariable = 10;
	var max = 11;
}
