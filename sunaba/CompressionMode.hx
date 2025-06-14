package sunaba;

enum abstract CompressionMode(Int) {
	var Lossless = 0;
	var Lossy = 1;
	var BasisUniversal = 2;
	var S3Tc = 3;
	var Etc2 = 4;
	var Bptc = 5;
}
