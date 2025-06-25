package lucidfx;

enum abstract FixedSizeScaleMode(Int) from Int to Int {
	var disable = 0;
	var integerOnly = 1;
	var enabled = 2;
}
