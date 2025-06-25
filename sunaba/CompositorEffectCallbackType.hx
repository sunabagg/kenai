package lucidware;

enum abstract CompositorEffectCallbackType(Int) from Int to Int {
	var preOpaque = 0;
	var postOpaque = 1;
	var postSky = 2;
	var preTransparent = 3;
	var postTransparent = 4;
	var any = -1;
}
