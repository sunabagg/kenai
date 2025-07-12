#include "sub_viewport.h"

namespace kenai::core {
    void bindSubViewport(sol::state& lua) {
        lua.new_usertype<SubViewport>("SubViewport",
            "new", sol::factories(
                []() { return new SubViewport; }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, Viewport>(),
            "renderTargetClearMode", sol::property(
                &SubViewport::getRenderTargetClearMode,
                &SubViewport::setRenderTargetClearMode
            ),
            "renderTargetUpdateMode", sol::property(
                &SubViewport::getRenderTargetUpdateMode,
                &SubViewport::setRenderTargetUpdateMode
            ),
            "size", sol::property(
                &SubViewport::getSize,
                &SubViewport::setSize
            ),
            "size2dOverride", sol::property(
                &SubViewport::getSize2dOverride,
                &SubViewport::setSize2dOverride
            ),
            "size2dOverrideStretch", sol::property(
                &SubViewport::getSize2dOverrideStretch,
                &SubViewport::setSize2dOverrideStretch
            ),
            "cast", [](Element* e) {
                auto* sv = dynamic_cast<SubViewport*>(e);
                if (sv != nullptr) {
                    return sv;
                }
                SubViewportNode* subViewport = Object::cast_to<SubViewportNode>(e->getNode());
                return new SubViewport(subViewport);
            }
        );
    }
}