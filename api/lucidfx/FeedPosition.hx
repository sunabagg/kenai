package lucidfx;

enum abstract FeedPosition(Int) from Int to Int {
	var unspecified = 0;
	var front = 1;
	var back = 2;
}
