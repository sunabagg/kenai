//
// Created by lucas on 1/31/2025.
//

#ifndef NH_OBJECT_H
#define NH_OBJECT_H

#include <lua.h>
#include <quickjs.h>

namespace sunaba::core
{
    //static void generateBaseObjectUsertype(lua_State* L);

    void registerBaseObject(JSContext* ctx);
    JSValue jsBaseObjectConstructor(JSContext* ctx, JSValueConst newTarget,  int argc, JSValueConst* argv);
    JSValue jsBaseObjectFree(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv);

    class BaseObject {
    public:
        bool freed = false;
        virtual void onNotification( int p_what ) {}

        void notification(const int p_notification, bool p_reversed = false);

        bool hasBeenFreed() {
            return freed;
        }

        static JSClassID baseObjectClassID;

        static JSClassDef baseObjectJsClass;

        static const JSCFunctionListEntry baseObjectProtoFuncs[];

        virtual void onFree() {}
        
        void free() { 
            this->onFree();
            freed = true;
        }

        virtual ~BaseObject() {
            if (!freed) {
                free();
            }
        }
    };

    void jsBaseObjectFinalizer(JSRuntime* rt, JSValue val) {
        BaseObject* baseObj = (BaseObject*)JS_GetOpaque(val, BaseObject::baseObjectClassID);
        if (baseObj) {
            if (baseObj->hasBeenFreed()) {
                delete baseObj;
            }
        }
    }
}

#endif //NH_OBJECT_H
