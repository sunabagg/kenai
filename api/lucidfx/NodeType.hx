package lucidfx;

enum abstract NodeType(Int) from Int to Int {
	var none = 0;
	var element = 1;
	var elementEnd = 2;
	var text = 3;
	var comment = 4;
	var cdata = 5;
	var unknown = 6;
}
