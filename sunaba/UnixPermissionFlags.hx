package lucidfx;

enum abstract UnixPermissionFlags(Int) from Int to Int {
	var executeOther = 1;
	var writeOther = 2;
	var readOther = 4;
	var executeGroup = 8;
	var writeGroup = 16;
	var readGroup = 32;
	var executeOwner = 64;
	var writeOwner = 128;
	var readOwner = 256;
	var restrictedDelete = 512;
	var setGroupId = 1024;
	var setUserId = 2048;
}
