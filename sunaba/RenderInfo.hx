package sunaba;

enum abstract RenderInfo(Int) {
	var ObjectsInFrame = 0;
	var PrimitivesInFrame = 1;
	var DrawCallsInFrame = 2;
	var Max = 3;
}
