package lucidware.ui;

@:native("GridContainer")
extern class GridContainer extends Container {
    public var columns: Int;
    @:native("cast")
    public static function toGridContainer(type: Dynamic): GridContainer;
}

abstract GridContainerAbstract(GridContainer) from GridContainer to GridContainer {
    @:from
    public static function fromElement(element: lucidware.core.Element): GridContainerAbstract {
        var grid = GridContainer.toGridContainer(element);
        if (grid.isNull()) {
            return null;
        }
        return grid;
    }
}