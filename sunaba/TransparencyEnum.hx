package sunaba;

enum abstract TransparencyEnum(Int) {
	var Disabled = 0;
	var Alpha = 1;
	var AlphaScissor = 2;
	var AlphaHash = 3;
	var AlphaDepthPrePass = 4;
	var Max = 5;
}
