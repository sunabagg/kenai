package sunaba;

enum abstract ArrayFormat(Int) {
	var FlagFormatVersion1 = 0;
	var FormatVertex = 1;
	var FormatNormal = 2;
	var FormatCustomBits = 3;
	var FormatTangent = 4;
	var FormatCustomMask = 7;
	var FormatCustomMask = 7;
	var FormatColor = 8;
	var FormatCustom0Shift = 13;
	var FormatCustom0Shift = 13;
	var FormatCustom1Shift = 16;
	var FormatCustom1Shift = 16;
	var FormatCustom2Shift = 19;
	var FormatCustom3Shift = 22;
	var CompressFlagsBase = 25;
	var FormatTexUV2 = 32;
	var FlagFormatVersionShift = 35;
	var FlagFormatVersionShift = 35;
	var FormatCustom0 = 64;
	var FormatCustom1 = 128;
	var FlagFormatVersionMask = 255;
	var FormatCustom2 = 256;
	var FormatCustom3 = 512;
	var FormatBones = 1024;
	var FormatWeights = 2048;
	var FormatIndex = 4096;
	var FlagUse2DVertices = 33554432;
	var FlagUseDynamicUpdate = 67108864;
	var FlagUse8BoneWeights = 134217728;
	var FlagUsesEmptyVertexArray = 268435456;
	var FlagCompressAttributes = 536870912;
	var FlagFormatVersion2 = 34359738368;
	var FlagFormatVersion2 = 34359738368;
}
