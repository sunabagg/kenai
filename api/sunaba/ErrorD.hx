package sunaba;

function ErrorD(err: String): Void {
    untyped __lua__("_G.__errord(err)");
}