package sunaba;

enum abstract SamplerBorderColor(Int) from Int to Int {
	var floatTransparentBlack = 0;
	var intTransparentBlack = 1;
	var floatOpaqueBlack = 2;
	var intOpaqueBlack = 3;
	var floatOpaqueWhite = 4;
	var intOpaqueWhite = 5;
	var max = 6;
}
