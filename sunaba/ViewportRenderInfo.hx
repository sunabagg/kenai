package sunaba;

enum abstract ViewportRenderInfo(Int) {
	var ObjectsInFrame = 0;
	var PrimitivesInFrame = 1;
	var DrawCallsInFrame = 2;
	var Max = 3;
}
