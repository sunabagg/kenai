package sunaba;

enum abstract BreadcrumbMarker(Int) from Int to Int {
	var none = 0;
	var reflectionProbes = 65536;
	var skyPass = 131072;
	var lightmapperPass = 196608;
	var shadowPassDirectional = 262144;
	var shadowPassCube = 327680;
	var opaquePass = 393216;
	var alphaPass = 458752;
	var transparentPass = 524288;
	var postProcessingPass = 589824;
	var blitPass = 655360;
	var uiPass = 720896;
	var debugPass = 786432;
}
