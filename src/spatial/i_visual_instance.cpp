#include "i_visual_instance.h"

void sunaba::spatial::bindVisualInstance(sol::state& lua) {
    lua.new_usertype<std::shared_ptr<IVisualInstance>>(
        "IVisualInstance",
        sol::constructors<IVisualInstance()>(),
        sol::base_classes, sol::bases<std::shared_ptr<BaseObject>, std::shared_ptr<Component>>(),
        "layerMask", sol::property(&IVisualInstance::getLayerMask, &IVisualInstance::setLayerMask),
        "sortingOffset", sol::property(&IVisualInstance::getSortingOffset, &IVisualInstance::setSortingOffset),
        "sortingUseAabbCenter", sol::property(&IVisualInstance::getSortingUseAabbCenter, &IVisualInstance::setSortingUseAabbCenter),
        "getAabb", &IVisualInstance::getAabb,
        "onGetAabb", &IVisualInstance::onGetAabb,
        "getLayerMaskValue", &IVisualInstance::getLayerMaskValue,
        "setLayerMaskValue", &IVisualInstance::setLayerMaskValue,
        "cast", [](Component* component) { 
            return dynamic_cast<IVisualInstance*>(component); 
        }
    );
}