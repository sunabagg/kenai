package lucidfx;

enum abstract SaverFlags(Int) from Int to Int {
	var none = 0;
	var relativePaths = 1;
	var bundleResources = 2;
	var changePath = 4;
	var omitEditorProperties = 8;
	var saveBigEndian = 16;
	var compress = 32;
	var replaceSubresourcePaths = 64;
}
