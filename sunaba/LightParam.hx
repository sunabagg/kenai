package sunaba;

enum abstract LightParam(Int) {
	var Energy = 0;
	var IndirectEnergy = 1;
	var VolumetricFogEnergy = 2;
	var Specular = 3;
	var Range = 4;
	var Size = 5;
	var Attenuation = 6;
	var SpotAngle = 7;
	var SpotAttenuation = 8;
	var ShadowMaxDistance = 9;
	var ShadowSplit1Offset = 10;
	var ShadowSplit2Offset = 11;
	var ShadowSplit3Offset = 12;
	var ShadowFadeStart = 13;
	var ShadowNormalBias = 14;
	var ShadowBias = 15;
	var ShadowPancakeSize = 16;
	var ShadowOpacity = 17;
	var ShadowBlur = 18;
	var TransmittanceBias = 19;
	var Intensity = 20;
	var Max = 21;
}
