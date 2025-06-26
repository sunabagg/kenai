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

            std::string getMenu() {
                return String(statusIndicator->get_menu()).utf8().get_data();
            }

            void setMenu(std::string value) {
                statusIndicator->set_menu(NodePath(String(value.c_str())));
            }

            std::string getTooltip() {
                return statusIndicator->get_tooltip().utf8().get_data();
            }

            void setTooltip(std::string value) {
                statusIndicator->set_tooltip(value.c_str());
            }

            bool getVisible() {
                return statusIndicator->is_visible();
            }

            void setVisible(bool value) {
                statusIndicator->set_visible(value);
            }

            Event* pressedEvent = new Event();
            Event* getPressedEvent() {
                return pressedEvent;
            }
            void setPressedEvent(Event* e) {
                pressedEvent = e;
            }

            Rect2 getRect() {
                return statusIndicator->get_rect();
            }
    };
}

#endif