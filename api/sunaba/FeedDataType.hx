package sunaba;

enum abstract FeedDataType(Int) from Int to Int {
	var noimage = 0;
	var rgb = 1;
	var ycbcr = 2;
	var ycbcrSep = 3;
	var external = 4;
}
