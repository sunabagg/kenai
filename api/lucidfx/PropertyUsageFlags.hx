package lucidfx;

enum abstract PropertyUsageFlags(Int) from Int to Int {
	var none = 0;
	var noEditor = 2;
	var noEditor = 2;
	var editor = 4;
	var default = 6;
	var internal = 8;
	var checkable = 16;
	var checked = 32;
	var group = 64;
	var category = 128;
	var subgroup = 256;
	var classIsBitfield = 512;
	var noInstanceState = 1024;
	var restartIfChanged = 2048;
	var scriptVariable = 4096;
	var storeIfNull = 8192;
	var updateAllIfModified = 16384;
	var scriptDefaultValue = 32768;
	var classIsEnum = 65536;
	var nilIsVariant = 131072;
	var array = 262144;
	var alwaysDuplicate = 524288;
	var neverDuplicate = 1048576;
	var highEndGfx = 2097152;
	var nodePathFromSceneRoot = 4194304;
	var resourceNotPersistent = 8388608;
	var keyingIncrements = 16777216;
	var deferredSetResource = 33554432;
	var editorInstantiateObject = 67108864;
	var editorBasicSetting = 134217728;
	var readOnly = 268435456;
	var secret = 536870912;
}
