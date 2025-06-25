package lucidfx;

enum abstract EditAction(Int) from Int to Int {
	var none = 0;
	var typing = 1;
	var backspace = 2;
	var delete = 3;
}
