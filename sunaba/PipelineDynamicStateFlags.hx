package sunaba;

enum abstract PipelineDynamicStateFlags(Int) {
	var LineWidth = 1;
	var DepthBias = 2;
	var BlendConstants = 4;
	var DepthBounds = 8;
	var StencilCompareMask = 16;
	var StencilWriteMask = 32;
	var StencilReference = 64;
}
