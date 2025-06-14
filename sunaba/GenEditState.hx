package sunaba;

enum abstract GenEditState(Int) {
	var Disabled = 0;
	var Instance = 1;
	var Main = 2;
	var MainInherited = 3;
}
