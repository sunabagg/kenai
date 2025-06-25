package lucidfx..ui;

enum abstract CheckBoxAutowrapMode(Int) from Int to Int {
	var off = 0;
	var arbitrary = 1;
	var word = 2;
	var wordSmart = 3;
}
