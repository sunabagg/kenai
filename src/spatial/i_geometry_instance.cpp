#include "i_geometry_instance.h"

void kenai::spatial::bindGeometryInstance(sol::state& lua) {
    lua.new_usertype<IGeometryInstance>(
        "IGeometryInstance",
        "new", sol::factories(
            []() { return new IGeometryInstance(); }
        ),
        sol::base_classes, sol::bases<IVisualInstance, Component>(),
        sol::meta_function::garbage_collect, sol::destructor([](IGeometryInstance* i) {  }),
        "castShadow", sol::property(&IGeometryInstance::getCastShadow, &IGeometryInstance::setCastShadow),
        "customAabb", sol::property(&IGeometryInstance::getCustomAabb, &IGeometryInstance::setCustomAabb),
        "giMode", sol::property(&IGeometryInstance::getGiMode, &IGeometryInstance::setGiMode),
        "lightmapScale", sol::property(&IGeometryInstance::getLightmapScale, &IGeometryInstance::setLightmapScale),
        "lodBias", sol::property(&IGeometryInstance::getLodBias, &IGeometryInstance::setLodBias),
        "transparancy", sol::property(&IGeometryInstance::getTransparancy, &IGeometryInstance::setTransparancy),
        "visibilityRangeBegin", sol::property(&IGeometryInstance::getVisibilityRangeBegin, &IGeometryInstance::setVisibilityRangeBegin),
        "visibilityRangeEnd", sol::property(&IGeometryInstance::getVisibilityRangeEnd, &IGeometryInstance::setVisibilityRangeEnd),
        "visibilityRangeBeginMargin", sol::property(&IGeometryInstance::getVisibilityRangeBeginMargin, &IGeometryInstance::setVisibilityRangeBeginMargin),
        "visibilityRangeEndMargin", sol::property(&IGeometryInstance::getVisibilityRangeEndMargin, &IGeometryInstance::setVisibilityRangeEndMargin),
        "visibilityRangeFadeMode", sol::property(&IGeometryInstance::getVisibilityRangeFadeMode, &IGeometryInstance::setVisibilityRangeFadeMode),
        "cast",[](Component* component) { 
            return dynamic_cast<IGeometryInstance*>(component); 
        }
    ); 
}