package lucidware;

enum abstract GltfObjectModelType(Int) from Int to Int {
	var unknown = 0;
	var bool = 1;
	var float = 2;
	var floatArray = 3;
	var float2 = 4;
	var float3 = 5;
	var float4 = 6;
	var float2x2 = 7;
	var float3x3 = 8;
	var float4x4 = 9;
	var int = 10;
}
