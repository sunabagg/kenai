package lucidware;

enum abstract ArrayFormat(Int) from Int to Int {
	var flagFormatVersion1 = 0;
	var formatVertex = 1;
	var formatNormal = 2;
	var formatCustomBits = 3;
	var formatTangent = 4;
	var formatCustomMask = 7;
	var formatCustomMask = 7;
	var formatColor = 8;
	var formatCustom0Shift = 13;
	var formatCustom0Shift = 13;
	var formatCustom1Shift = 16;
	var formatCustom1Shift = 16;
	var formatCustom2Shift = 19;
	var formatCustom3Shift = 22;
	var compressFlagsBase = 25;
	var formatTexUv2 = 32;
	var flagFormatVersionShift = 35;
	var flagFormatVersionShift = 35;
	var formatCustom0 = 64;
	var formatCustom1 = 128;
	var flagFormatVersionMask = 255;
	var formatCustom2 = 256;
	var formatCustom3 = 512;
	var formatBones = 1024;
	var formatWeights = 2048;
	var formatIndex = 4096;
	var flagUse2dVertices = 33554432;
	var flagUseDynamicUpdate = 67108864;
	var flagUse8BoneWeights = 134217728;
	var flagUsesEmptyVertexArray = 268435456;
	var flagCompressAttributes = 536870912;
	var flagFormatVersion2 = 34359738368;
	var flagFormatVersion2 = 34359738368;
}
