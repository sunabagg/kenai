package sunaba;

function WarnD(err: String): Void {
    untyped __lua__("_G.__warnd(err)");
}