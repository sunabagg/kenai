package sunaba;

enum abstract CompositorEffectCallbackType(Int) {
	var PreOpaque = 0;
	var PostOpaque = 1;
	var PostSky = 2;
	var PreTransparent = 3;
	var PostTransparent = 4;
	var Any = -1;
}
