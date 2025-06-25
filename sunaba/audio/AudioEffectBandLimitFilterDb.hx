package lucidfx..audio;

enum abstract AudioEffectBandLimitFilterDb(Int) from Int to Int {
	var filter6Db = 0;
	var filter12Db = 1;
	var filter18Db = 2;
	var filter24Db = 3;
}
