package lucidfx;

enum abstract CanvasLightShadowFilter(Int) from Int to Int {
	var none = 0;
	var pcf5 = 1;
	var pcf13 = 2;
	var max = 3;
}
