#include "i_visual_instance.h"

void sunaba_spatial::bindVisualInstance(sol::state& lua) {
    lua.new_usertype<IVisualInstance>(
        "IVisualInstance",
        sol::no_constructor,
        sol::base_classes, sol::bases<Component>(),
        "layerMask", sol::property(&IVisualInstance::getLayerMask, &IVisualInstance::setLayerMask),
        "sortingOffset", sol::property(&IVisualInstance::getSortingOffset, &IVisualInstance::setSortingOffset),
        "sortingUseAabbCenter", sol::property(&IVisualInstance::getSortingUseAabbCenter, &IVisualInstance::setSortingUseAabbCenter),
        "getAabb", &IVisualInstance::getAabb,
        "onGetAabb", &IVisualInstance::onGetAabb,
        "getLayerMaskValue", &IVisualInstance::getLayerMaskValue,
        "setLayerMaskValue", &IVisualInstance::setLayerMaskValue
    );
}