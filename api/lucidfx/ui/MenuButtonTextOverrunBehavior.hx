package lucidfx..ui;

enum abstract MenuButtonTextOverrunBehavior(Int) from Int to Int {
	var noTrimming = 0;
	var trimChar = 1;
	var trimWord = 2;
	var trimEllipsis = 3;
	var trimWordEllipsis = 4;
}
