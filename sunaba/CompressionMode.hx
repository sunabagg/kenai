package lucidware;

enum abstract CompressionMode(Int) from Int to Int {
	var lossless = 0;
	var lossy = 1;
	var basisUniversal = 2;
	var s3Tc = 3;
	var etc2 = 4;
	var bptc = 5;
}
