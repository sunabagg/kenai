package lucidware;

enum abstract BakeError(Int) from Int to Int {
	var ok = 0;
	var noSceneRoot = 1;
	var foreignData = 2;
	var noLightmapper = 3;
	var noSavePath = 4;
	var noMeshes = 5;
	var meshesInvalid = 6;
	var cantCreateImage = 7;
	var userAborted = 8;
	var textureSizeTooSmall = 9;
	var lightmapTooSmall = 10;
	var atlasTooSmall = 11;
}
