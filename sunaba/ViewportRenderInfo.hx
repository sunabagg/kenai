package lucidfx;

enum abstract ViewportRenderInfo(Int) from Int to Int {
	var objectsInFrame = 0;
	var primitivesInFrame = 1;
	var drawCallsInFrame = 2;
	var max = 3;
}
