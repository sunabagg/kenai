package sunaba.ui;

@:native("GridContainer")
extern class GridContainer extends Container {
    public var columns: Int;
    @:native("cast")
    public function toGridContainer(type: Dynamic): GridContainer;
}