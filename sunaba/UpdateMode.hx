package lucidfx;

enum abstract UpdateMode(Int) from Int to Int {
	var disabled = 0;
	var once = 1;
	var whenVisible = 2;
	var whenParentVisible = 3;
	var always = 4;
}
