package sunaba..ui;

enum abstract CheckButtonTextOverrunBehavior(Int) {
	var NoTrimming = 0;
	var TrimChar = 1;
	var TrimWord = 2;
	var TrimEllipsis = 3;
	var TrimWordEllipsis = 4;
}
