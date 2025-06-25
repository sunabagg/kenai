package lucidware;

enum abstract ShadowCastingSetting(Int) from Int to Int {
	var off = 0;
	var on = 1;
	var doubleSided = 2;
	var shadowsOnly = 3;
}
