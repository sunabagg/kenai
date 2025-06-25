package lucidfx;

enum abstract VisibilityMode(Int) from Int to Int {
	var default = 0;
	var forceShow = 1;
	var forceHide = 2;
}
