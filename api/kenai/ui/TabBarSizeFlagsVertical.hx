package kenai..ui;

enum abstract TabBarSizeFlagsVertical(Int) from Int to Int {
	var shrinkBegin = 0;
	var fill = 1;
	var expand = 2;
	var expandFill = 3;
	var shrinkCenter = 4;
	var shrinkEnd = 8;
}
