package sunaba;

enum abstract UnixPermissionFlags(Int) {
	var ExecuteOther = 1;
	var WriteOther = 2;
	var ReadOther = 4;
	var ExecuteGroup = 8;
	var WriteGroup = 16;
	var ReadGroup = 32;
	var ExecuteOwner = 64;
	var WriteOwner = 128;
	var ReadOwner = 256;
	var RestrictedDelete = 512;
	var SetGroupId = 1024;
	var SetUserId = 2048;
}
