package sunaba;

enum abstract CompressMode(Int) from Int to Int {
	var s3Tc = 0;
	var etc = 1;
	var etc2 = 2;
	var bptc = 3;
	var astc = 4;
	var max = 5;
}
