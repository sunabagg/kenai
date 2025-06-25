package sunaba;

enum abstract AlphaCutMode(Int) from Int to Int {
	var disabled = 0;
	var discard = 1;
	var opaquePrepass = 2;
	var hash = 3;
}
