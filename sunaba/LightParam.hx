package lucidware;

enum abstract LightParam(Int) from Int to Int {
	var energy = 0;
	var indirectEnergy = 1;
	var volumetricFogEnergy = 2;
	var specular = 3;
	var range = 4;
	var size = 5;
	var attenuation = 6;
	var spotAngle = 7;
	var spotAttenuation = 8;
	var shadowMaxDistance = 9;
	var shadowSplit1Offset = 10;
	var shadowSplit2Offset = 11;
	var shadowSplit3Offset = 12;
	var shadowFadeStart = 13;
	var shadowNormalBias = 14;
	var shadowBias = 15;
	var shadowPancakeSize = 16;
	var shadowOpacity = 17;
	var shadowBlur = 18;
	var transmittanceBias = 19;
	var intensity = 20;
	var max = 21;
}
