#include "sub_viewport.h"

namespace sunaba::core {
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
            )
        );
    }
}