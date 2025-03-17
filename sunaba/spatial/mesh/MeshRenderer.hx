package sunaba.spatial.mesh;

import sunaba.native.spatial.mesh.MeshRendererNative;
import sunaba.core.BaseObject;
import sunaba.spatial.IGeometryInstance;
import sunaba.core.Entity;

class MeshRenderer extends IGeometryInstance {
    public var mrInstance(get, default) : MeshRendererNative;
    public function get_mrInstance() : MeshRendererNative {
        return cast instance;
    }

    public function new() {
        super();
        instance.free();
        instance = new MeshRendererNative();
        if (instance == null) {
            throw "MeshRenderer.new() returned null";
        }

        mrInstance.setScriptInstance(this);
        pushToStack();
    }

    public static function fromInstance(instance : MeshRendererNative) : MeshRenderer {
        if (instance == null) {
            throw "MeshRenderer.fromInstance() received null instance";
        }
        var obj = new MeshRenderer();
        obj.instance = instance;
        return obj;
    }

    public function createConvexCollision() : Void {
        mrInstance.createConvexCollision();
    }

    public function createDebugTangents() : Void {
        mrInstance.createDebugTangents();
    }

    public function createTrimeshCollision() : Void {
        mrInstance.createTrimeshCollision();
    }

    public function findBlendShapeByName(name : String) : Int {
        return mrInstance.findBlendShapeByName(name);
    }

    public function getBlendShapeCount() : Int {
        return mrInstance.getBlendShapeCount();
    }

    public function getBlendShapeValue(index : Int) : Float {
        return mrInstance.getBlendShapeValue(index);
    }

    public function getSurfaceOverrideCount() : Int {
        return mrInstance.getSurfaceOverrideCount();
    }

    public function setBlendShapeValue(index : Int, value : Float) : Void {
        mrInstance.setBlendShapeValue(index, value);
    }
}

abstract MeshRendererAbstract(MeshRenderer) from MeshRenderer to MeshRenderer {
    @:from
    public static function fromBaseObject(obj : BaseObject) : MeshRendererAbstract {
        return MeshRenderer.fromInstance(cast obj.instance);
    }

    @:from
    public static function fromInstance(instance : MeshRendererNative) : MeshRendererAbstract {
        return MeshRenderer.fromInstance(instance);
    }
}