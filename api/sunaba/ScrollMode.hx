package sunaba;

enum abstract ScrollMode(Int) from Int to Int {
	var disabled = 0;
	var auto = 1;
	var showAlways = 2;
	var showNever = 3;
	var reserve = 4;
}
