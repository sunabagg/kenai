package sunaba;

enum abstract CompositorEffectFlags(Int) {
	var AccessResolvedColor = 1;
	var AccessResolvedDepth = 2;
	var NeedsMotionVectors = 4;
	var NeedsRoughness = 8;
	var NeedsSeparateSpecular = 16;
}
