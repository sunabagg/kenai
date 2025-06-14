package sunaba;

enum abstract BlendFactor(Int) {
	var Zero = 0;
	var One = 1;
	var SrcColor = 2;
	var OneMinusSrcColor = 3;
	var DstColor = 4;
	var OneMinusDstColor = 5;
	var SrcAlpha = 6;
	var OneMinusSrcAlpha = 7;
	var DstAlpha = 8;
	var OneMinusDstAlpha = 9;
	var ConstantColor = 10;
	var OneMinusConstantColor = 11;
	var ConstantAlpha = 12;
	var OneMinusConstantAlpha = 13;
	var SrcAlphaSaturate = 14;
	var Src1Color = 15;
	var OneMinusSrc1Color = 16;
	var Src1Alpha = 17;
	var OneMinusSrc1Alpha = 18;
	var Max = 19;
}
