package lucidware;

enum abstract NoiseTypeEnum(Int) from Int to Int {
	var simplex = 0;
	var simplexSmooth = 1;
	var cellular = 2;
	var perlin = 3;
	var valueCubic = 4;
	var value = 5;
}
