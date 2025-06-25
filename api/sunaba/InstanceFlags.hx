package sunaba;

enum abstract InstanceFlags(Int) from Int to Int {
	var useBakedLight = 0;
	var useDynamicGi = 1;
	var drawNextFrameIfVisible = 2;
	var ignoreOcclusionCulling = 3;
	var max = 4;
}
