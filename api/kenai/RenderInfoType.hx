package kenai;

enum abstract RenderInfoType(Int) from Int to Int {
	var visible = 0;
	var shadow = 1;
	var canvas = 2;
	var max = 3;
}
