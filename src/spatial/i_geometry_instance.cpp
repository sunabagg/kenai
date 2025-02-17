#include "i_geometry_instance.h"

void sunaba_spatial::bindGeometryInstance(sol::state& lua) {
    sunaba_spatial::bindVisualInstance(lua);
    lua.new_usertype<IGeometryInstance>(
        "IGeometryInstance",
        sol::constructors<IGeometryInstance()>(),
        sol::base_classes, sol::bases<IVisualInstance, Component>(),
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
        "visibilityRangeFadeMode", sol::property(&IGeometryInstance::getVisibilityRangeFadeMode, &IGeometryInstance::setVisibilityRangeFadeMode)
    ); 
}