package lucidware;

enum abstract TransformAlignEnum(Int) from Int to Int {
	var disabled = 0;
	var zBillboard = 1;
	var yToVelocity = 2;
	var zBillboardYToVelocity = 3;
}
