package lucidfx;

enum abstract DrawOrderEnum(Int) from Int to Int {
	var index = 0;
	var lifetime = 1;
	var reverseLifetime = 2;
	var viewDepth = 3;
}
