package lucidware;

enum abstract BlendFactor(Int) from Int to Int {
	var zero = 0;
	var one = 1;
	var srcColor = 2;
	var oneMinusSrcColor = 3;
	var dstColor = 4;
	var oneMinusDstColor = 5;
	var srcAlpha = 6;
	var oneMinusSrcAlpha = 7;
	var dstAlpha = 8;
	var oneMinusDstAlpha = 9;
	var constantColor = 10;
	var oneMinusConstantColor = 11;
	var constantAlpha = 12;
	var oneMinusConstantAlpha = 13;
	var srcAlphaSaturate = 14;
	var src1Color = 15;
	var oneMinusSrc1Color = 16;
	var src1Alpha = 17;
	var oneMinusSrc1Alpha = 18;
	var max = 19;
}
