package lucidfx;

enum abstract CompositorEffectFlags(Int) from Int to Int {
	var accessResolvedColor = 1;
	var accessResolvedDepth = 2;
	var needsMotionVectors = 4;
	var needsRoughness = 8;
	var needsSeparateSpecular = 16;
}
