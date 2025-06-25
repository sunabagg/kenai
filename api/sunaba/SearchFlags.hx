package sunaba;

enum abstract SearchFlags(Int) from Int to Int {
	var matchCase = 1;
	var wholeWords = 2;
	var backwards = 4;
}
