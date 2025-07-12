package kenai..spatial.joints;

enum abstract Joint3DRotationOrder(Int) from Int to Int {
	var xyz = 0;
	var xzy = 1;
	var yxz = 2;
	var yzx = 3;
	var zxy = 4;
	var zyx = 5;
}
