package sunaba;

enum abstract InstanceFlags(Int) {
	var UseBakedLight = 0;
	var UseDynamicGI = 1;
	var DrawNextFrameIfVisible = 2;
	var IgnoreOcclusionCulling = 3;
	var Max = 4;
}
