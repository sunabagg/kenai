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

            void setRenderTargetClearMode(int value) {
                subViewport->set_clear_mode(static_cast<SubViewportNode::ClearMode>(value));
            }

            int getRenderTargetUpdateMode() {
                return subViewport->get_update_mode();
            }

            void setRenderTargetUpdateMode(int value) {
                subViewport->set_update_mode(static_cast<SubViewportNode::UpdateMode>(value));
            }

            Vector2i getSize() {
                return subViewport->get_size();
            }

            void setSize(const Vector2i& value) {
                subViewport->set_size(value);
            }

            Vector2i getSize2dOverride() {
                return subViewport->get_size_2d_override();
            }

            void setSize2dOverride(const Vector2i& value) {
                return subViewport->set_size_2d_override(value);
            }

            bool getSize2dOverrideStretch() {
                return subViewport->is_size_2d_override_stretch_enabled();
            }

            void setSize2dOverrideStretch(bool value) {
                subViewport->set_size_2d_override_stretch(value);
            }
    };
}

#endif