package lucidfx..ui;

enum abstract MenuBarMouseFilter(Int) from Int to Int {
	var stop = 0;
	var pass = 1;
	var ignore = 2;
}
