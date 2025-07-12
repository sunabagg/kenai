#include "i_visual_instance.h"

void kenai::spatial::bindVisualInstance(sol::state& lua) {
    lua.new_usertype<IVisualInstance>(
        "IVisualInstance",
        "new", sol::factories(
            []() { return new IVisualInstance(); }
        ),
        sol::base_classes, sol::bases<Component>(),
        sol::meta_function::garbage_collect, sol::destructor([](IVisualInstance* i) {  }),
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