package sunaba;

enum abstract LookupResultType(Int) {
	var ScriptLocation = 0;
	var Class = 1;
	var ClassConstant = 2;
	var ClassProperty = 3;
	var ClassMethod = 4;
	var ClassSignal = 5;
	var ClassEnum = 6;
	var ClassTbdGlobalscope = 7;
	var ClassAnnotation = 8;
	var LocalConstant = 9;
	var LocalVariable = 10;
	var Max = 11;
}
