package sunaba;

enum abstract PropertyUsageFlags(Int) {
	var None = 0;
	var NoEditor = 2;
	var NoEditor = 2;
	var Editor = 4;
	var Default = 6;
	var Internal = 8;
	var Checkable = 16;
	var Checked = 32;
	var Group = 64;
	var Category = 128;
	var Subgroup = 256;
	var ClassIsBitfield = 512;
	var NoInstanceState = 1024;
	var RestartIfChanged = 2048;
	var ScriptVariable = 4096;
	var StoreIfNull = 8192;
	var UpdateAllIfModified = 16384;
	var ScriptDefaultValue = 32768;
	var ClassIsEnum = 65536;
	var NilIsVariant = 131072;
	var Array = 262144;
	var AlwaysDuplicate = 524288;
	var NeverDuplicate = 1048576;
	var HighEndGfx = 2097152;
	var NodePathFromSceneRoot = 4194304;
	var ResourceNotPersistent = 8388608;
	var KeyingIncrements = 16777216;
	var DeferredSetResource = 33554432;
	var EditorInstantiateObject = 67108864;
	var EditorBasicSetting = 134217728;
	var ReadOnly = 268435456;
	var Secret = 536870912;
}
