package sunaba;

enum abstract BreadcrumbMarker(Int) {
	var None = 0;
	var ReflectionProbes = 65536;
	var SkyPass = 131072;
	var LightmapperPass = 196608;
	var ShadowPassDirectional = 262144;
	var ShadowPassCube = 327680;
	var OpaquePass = 393216;
	var AlphaPass = 458752;
	var TransparentPass = 524288;
	var PostProcessingPass = 589824;
	var BlitPass = 655360;
	var UiPass = 720896;
	var DebugPass = 786432;
}
