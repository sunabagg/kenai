#include "i_geometry_instance.h"

void sunaba::spatial::bindGeometryInstance(sol::state& lua) {
    lua.new_usertype<IGeometryInstanceReference>(
        "IGeometryInstance",
        sol::constructors<IGeometryInstanceReference()>(),
        sol::base_classes, sol::bases<IVisualInstanceReference, ComponentReference>(),
        "castShadow", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getCastShadow();
        }, [](IGeometryInstanceReference& g, int cast) {
            NativeReference<IGeometryInstance>(g)->setCastShadow(cast);
        }),
        "customAabb", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getCustomAabb();
        }, [](IGeometryInstanceReference& g, AABB aabb) {
            NativeReference<IGeometryInstance>(g)->setCustomAabb(aabb);
        }),
        "giMode", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getGiMode();
        }, [](IGeometryInstanceReference& g, int mode) {
            NativeReference<IGeometryInstance>(g)->setGiMode(mode);
        }),
        "lightmapScale", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getLightmapScale();
        }, [](IGeometryInstanceReference& g, int scale) {
            NativeReference<IGeometryInstance>(g)->setLightmapScale(scale);
        }),
        "lodBias", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getLodBias();
        }, [](IGeometryInstanceReference& g, float bias) {
            NativeReference<IGeometryInstance>(g)->setLodBias(bias);
        }),
        "transparancy", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getTransparancy();
        }, [](IGeometryInstanceReference& g, float transparancy) {
            NativeReference<IGeometryInstance>(g)->setTransparancy(transparancy);
        }),
        "visibilityRangeBegin", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getVisibilityRangeBegin();
        }, [](IGeometryInstanceReference& g, float begin) {
            NativeReference<IGeometryInstance>(g)->setVisibilityRangeBegin(begin);
        }),
        "visibilityRangeEnd", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getVisibilityRangeEnd();
        }, [](IGeometryInstanceReference& g, float end) {
            NativeReference<IGeometryInstance>(g)->setVisibilityRangeEnd(end);
        }),
        "visibilityRangeBeginMargin", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getVisibilityRangeBeginMargin();
        }, [](IGeometryInstanceReference& g, float margin) {
            NativeReference<IGeometryInstance>(g)->setVisibilityRangeBeginMargin(margin);
        }),
        "visibilityRangeEndMargin", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getVisibilityRangeEndMargin();
        }, [](IGeometryInstanceReference& g, float margin) {
            NativeReference<IGeometryInstance>(g)->setVisibilityRangeEndMargin(margin);
        }),
        "visibilityRangeFadeMode", sol::property([](IGeometryInstanceReference& g) {
            return NativeReference<IGeometryInstance>(g)->getVisibilityRangeFadeMode();
        }, [](IGeometryInstanceReference& g, int mode) {
            NativeReference<IGeometryInstance>(g)->setVisibilityRangeFadeMode(mode);
        }),
        "getFromEntity", [](EntityReference& e) {
            return new IGeometryInstanceReference(
                NativeReference<Entity>(e)->getComponentByT<IGeometryInstance>()
            );
        },
        "cast",[](ComponentReference component) {
            return IGeometryInstanceReference(
                static_cast<IGeometryInstance*>(NativeReference<Component>(component).ptr)
            );
        }
    ); 
}