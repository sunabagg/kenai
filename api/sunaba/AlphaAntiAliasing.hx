package sunaba;

enum abstract AlphaAntiAliasing(Int) from Int to Int {
	var off = 0;
	var alphaToCoverage = 1;
	var alphaToCoverageAndToOne = 2;
}
