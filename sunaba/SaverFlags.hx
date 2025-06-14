package sunaba;

enum abstract SaverFlags(Int) {
	var None = 0;
	var RelativePaths = 1;
	var BundleResources = 2;
	var ChangePath = 4;
	var OmitEditorProperties = 8;
	var SaveBigEndian = 16;
	var Compress = 32;
	var ReplaceSubresourcePaths = 64;
}
