package sunaba;

enum abstract ApiType(Int) from Int to Int {
	var core = 0;
	var editor = 1;
	var extension = 2;
	var editorExtension = 3;
	var none = 4;
}
