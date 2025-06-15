package sunaba;

enum abstract SelectModeEnum(Int) from Int to Int {
	var single = 0;
	var multi = 1;
	var toggle = 2;
}
