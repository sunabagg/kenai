#include "i_visual_instance.h"

void sunaba::spatial::bindVisualInstance(sol::state& lua) {
    lua.new_usertype<IVisualInstanceReference>(
        "IVisualInstance",
        sol::constructors<IVisualInstanceReference()>(),
        sol::base_classes, sol::bases<Component>(),
        "layerMask", sol::property([](IVisualInstanceReference& v) {
            return NativeReference<IVisualInstance>(v)->getLayerMask();
        }, [](IVisualInstanceReference& v, int mask) {
            NativeReference<IVisualInstance>(v)->setLayerMask(mask);
        }),
        "sortingOffset", sol::property([](IVisualInstanceReference& v) {
            return NativeReference<IVisualInstance>(v)->getSortingOffset();
        }, [](IVisualInstanceReference& v, float offset) {
            NativeReference<IVisualInstance>(v)->setSortingOffset(offset);
        }),
        "sortingUseAabbCenter", sol::property([](IVisualInstanceReference& v) {
            return NativeReference<IVisualInstance>(v)->getSortingUseAabbCenter();
        }, [](IVisualInstanceReference& v, bool use) {
            NativeReference<IVisualInstance>(v)->setSortingUseAabbCenter(use);
        }),
        "getAabb", [](IVisualInstanceReference& v) {
            return NativeReference<IVisualInstance>(v)->getAabb();
        },
        "onGetAabb", [](IVisualInstanceReference& v) {
            return NativeReference<IVisualInstance>(v)->onGetAabb();
        },
        "getLayerMaskValue", [](IVisualInstanceReference& v, int layer) {
            return NativeReference<IVisualInstance>(v)->getLayerMaskValue(layer);
        },
        "setLayerMaskValue", [](IVisualInstanceReference& v, int layer, bool value) {
            NativeReference<IVisualInstance>(v)->setLayerMaskValue(layer, value);
        },
        "getFromEntity", [](EntityReference& e) {
            return new IVisualInstanceReference(
                NativeReference<Entity>(e)->getComponentByT<IVisualInstance>()
            );
        },
        "cast", [](ComponentReference& cr) {
            return IVisualInstanceReference(
                static_cast<IVisualInstance*>(NativeReference<Component>(cr).ptr)
            );
        }
    );
}