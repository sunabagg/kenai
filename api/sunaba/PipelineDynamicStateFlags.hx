package sunaba;

enum abstract PipelineDynamicStateFlags(Int) from Int to Int {
	var lineWidth = 1;
	var depthBias = 2;
	var blendConstants = 4;
	var depthBounds = 8;
	var stencilCompareMask = 16;
	var stencilWriteMask = 32;
	var stencilReference = 64;
}
