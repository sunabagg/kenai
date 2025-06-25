package sunaba;

enum abstract IgdStatusEnum(Int) from Int to Int {
	var ok = 0;
	var httpError = 1;
	var httpEmpty = 2;
	var noUrls = 3;
	var noIgd = 4;
	var disconnected = 5;
	var unknownDevice = 6;
	var invalidControl = 7;
	var mallocError = 8;
	var unknownError = 9;
}
