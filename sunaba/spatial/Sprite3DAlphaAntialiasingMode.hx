package lucidfx..spatial;

enum abstract Sprite3DAlphaAntialiasingMode(Int) from Int to Int {
	var off = 0;
	var alphaToCoverage = 1;
	var alphaToCoverageAndToOne = 2;
}
