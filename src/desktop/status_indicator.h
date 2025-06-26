#ifndef STATUS_INDICATOR_H
#define STATUS_INDICATOR_H

#include <godot_cpp/classes/status_indicator.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define StatusIndicatorNode godot::StatusIndicator

#include "../core/element.h"
#include "../core/texture2d.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindStatusIndicator(sol::state& lua);

    class StatusIndicator;

    class StatusIndicatorSignalWrapper : public Object {
        GDCLASS(StatusIndicatorSignalWrapper, Object)
        protected:
            static void _bind_methods();

        public:
            StatusIndicator* element = nullptr;

            StatusIndicatorSignalWrapper() = default;
            ~StatusIndicatorSignalWrapper() = default;

            void pressed(int mouse_button, Vector2i mouse_position);
    };

    class StatusIndicator : public Element {
        private:
            StatusIndicatorNode* statusIndicator = nullptr;
            StatusIndicatorSignalWrapper* signalWrapper = nullptr;

            void connectStatusIndicatorSignals() {
                if (signalWrapper == nullptr) {
                    signalWrapper = memnew(StatusIndicatorSignalWrapper);
                    signalWrapper->element = this;
                }

                statusIndicator->connect("pressed", Callable(signalWrapper, "pressed"));
            }
        public:
            StatusIndicator() {
                setStatusIndicatorNode(memnew(StatusIndicatorNode));
                onInit();
            }

            StatusIndicator(StatusIndicatorNode* node) {
                setStatusIndicatorNode(node);
            }

            StatusIndicatorNode* getStatusIndicatorNode() {
                return statusIndicator;
            }

            void setStatusIndicatorNode(StatusIndicatorNode* node) {
                statusIndicator = node;
                connectStatusIndicatorSignals();
                setNode(node); 
            }

            sunaba::core::Texture2D* getIcon() {
                return new sunaba::core::Texture2D(statusIndicator->get_icon().ptr());
            }

            void setIcon(sunaba::core::Texture2D* value) {
                Ref<godot::Texture2D> valueRef = Ref<godot::Texture2D>(value->getTexture2D());
                statusIndicator->set_icon(valueRef);
            }
    };
}

#endif