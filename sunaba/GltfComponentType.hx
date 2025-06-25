package lucidfx;

enum abstract GltfComponentType(Int) from Int to Int {
	var none = 0;
	var signedByte = 5120;
	var unsignedByte = 5121;
	var signedShort = 5122;
	var unsignedShort = 5123;
	var signedInt = 5124;
	var unsignedInt = 5125;
	var singleFloat = 5126;
	var doubleFloat = 5130;
	var halfFloat = 5131;
	var signedLong = 5134;
	var unsignedLong = 5135;
}
