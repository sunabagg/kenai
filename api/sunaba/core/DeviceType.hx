package sunaba.core;

enum abstract DeviceType(Int) from Int to Int {
    var unknown = -1;
    var desktop = 0;
    var mobile = 1;
    var web = 2;
    var xr = 3;
}