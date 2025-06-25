package lucidfx;

enum abstract ViewportClearMode(Int) from Int to Int {
	var always = 0;
	var never = 1;
	var onlyNextFrame = 2;
}
