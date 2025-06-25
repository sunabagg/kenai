package lucidfx;

enum abstract BodyFlagsEnum(Int) from Int to Int {
	var upperBodySupported = 1;
	var lowerBodySupported = 2;
	var handsSupported = 4;
}
