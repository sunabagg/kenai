//
// Created by lucas on 1/31/2025.
//

#include "base_object.h"

namespace sunaba::core
{
    
    const JSClassDef BaseObject::baseObjectJsClass = {
        "BaseObject",
        .finalizer = jsBaseObjectFinalizer,
    };

    void jsBaseObjectFinalizer(JSContext* rt, JSValue value ) {
        BaseObject* baseObj = (BaseObject*)JS_GetOpaque(value, BaseObject::baseObjectClassID);
        if (baseObj) {
            if (baseObj->hasBeenFreed()) {
                delete baseObj;
            }
        }
    }

    JSValue jsBaseObjectConstructor(JSContext* ctx, JSValueConst newTarget,  int argc, JSValueConst* argv) {
        if (argc != 0) return JS_EXCEPTION;

        BaseObject* obj = new BaseObject();

        JSValue objVal = JS_NewObjectClass(ctx, BaseObject::baseObjectClassID);
        JS_SetOpaque(objVal, obj);

        return objVal;
    }

    JSValue jsBaseObjectFree(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
        BaseObject* obj = (BaseObject*)JS_GetOpaque(this_val, BaseObject::baseObjectClassID);
        if (obj) {
            obj->free();
        }
        return JS_UNDEFINED;
    }

    const JSCFunctionListEntry BaseObject::baseObjectProtoFuncs[] = {
        JS_CFUNC_DEF("free", 0, jsBaseObjectFree),
        JS_PROP_STRING_DEF("[[Class]]", "BaseObject", JS_PROP_CONFIGURABLE),
        JS_PROP_STRING_DEF("className", "BaseObject", JS_PROP_CONFIGURABLE),
    };

    void registerBaseObject(JSRuntime* rt, JSContext* ctx) {
        JS_NewClassID(rt, &BaseObject::baseObjectClassID);
        JS_NewClass(rt, BaseObject::baseObjectClassID, &BaseObject::baseObjectJsClass);

        JSValue proto = JS_NewObject(ctx);
        JS_SetPropertyFunctionList(
            ctx, 
            proto, 
            BaseObject::baseObjectProtoFuncs, 
            sizeof(BaseObject::baseObjectProtoFuncs)
        );

        JSValue constructor = JS_NewCFunction2(
            ctx, 
            jsBaseObjectConstructor, 
            "BaseObject", 
            0, 
            JS_CFUNC_constructor, 
            0
        );
        JS_SetConstructor(ctx, constructor, proto);
        JS_SetClassProto(ctx, BaseObject::baseObjectClassID, proto);

        JS_SetPropertyStr(ctx, JS_GetGlobalObject(ctx), "BaseObject", constructor);
    }
}

using namespace sunaba::core;

void BaseObject::notification(const int p_notification, bool p_reversed)
{
    if (p_reversed) {
        onNotification(p_notification);
    }
    else {
        onNotification(-p_notification);
    }


}