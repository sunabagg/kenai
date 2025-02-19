package sunaba.core;

class Behavior extends Component {
    public function new() {
        super();

        var type = Type.getClass(this);
        if (type == null) {
            throw "Behavior must be a class";
        }

        setScriptType(type);

        setScriptInstance(this);
    }
}