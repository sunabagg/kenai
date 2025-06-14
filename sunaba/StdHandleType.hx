package sunaba;

enum abstract StdHandleType(Int) {
	var Invalid = 0;
	var Console = 1;
	var File = 2;
	var Pipe = 3;
	var Unknown = 4;
}
