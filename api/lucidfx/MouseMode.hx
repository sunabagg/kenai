package lucidfx;

enum abstract MouseMode(Int) from Int to Int {
	var visible = 0;
	var hidden = 1;
	var captured = 2;
	var confined = 3;
	var confinedHidden = 4;
	var max = 5;
}
