package sunaba;

enum abstract BakeError(Int) {
	var Ok = 0;
	var NoSceneRoot = 1;
	var ForeignData = 2;
	var NoLightmapper = 3;
	var NoSavePath = 4;
	var NoMeshes = 5;
	var MeshesInvalid = 6;
	var CantCreateImage = 7;
	var UserAborted = 8;
	var TextureSizeTooSmall = 9;
	var LightmapTooSmall = 10;
	var AtlasTooSmall = 11;
}
