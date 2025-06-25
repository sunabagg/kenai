package lucidfx;

enum abstract ExpandModeEnum(Int) from Int to Int {
	var keepSize = 0;
	var ignoreSize = 1;
	var fitWidth = 2;
	var fitWidthProportional = 3;
	var fitHeight = 4;
	var fitHeightProportional = 5;
}
