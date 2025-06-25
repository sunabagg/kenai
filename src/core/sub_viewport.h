#ifndef SUB_VIEWPORT_H
#define SUB_VIEWPORT_H

#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define SubViewportNode godot::SubViewport

#include "viewport.h"

using namespace godot;

namespace sunaba::core {
    void bindSubViewport(sol::state &lua);

    class SubViewport : public Viewport {
    private:
        SubViewportNode* subViewport = nullptr;
        public:
            SubViewport() {
                setSubViewport(memnew(SubViewportNode));
                onInit();
            }

            SubViewport(SubViewportNode* subViewport) {
                setSubViewport(subViewport);
            }

            SubViewportNode* getSubViewport() {
                return this->subViewport;
            }

            void setSubViewport(SubViewportNode* subViewport) {
                this->subViewport = subViewport;
                this->setViewport(subViewport);
            }

            int getRenderTargetClearMode() {
                return subViewport->get_clear_mode();
            }
    };
}

#endif