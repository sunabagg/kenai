package sunaba;

enum abstract AlphaCutMode(Int) {
	var Disabled = 0;
	var Discard = 1;
	var OpaquePrepass = 2;
	var Hash = 3;
}
