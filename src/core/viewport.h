#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ViewportNode godot::Viewport

#include "element.h"
#include "event.h"
#include "texture2d.h"
#include "../spatial/world3d.h"
#include "../input/input_event.h"
#include "../ui/control.h"

using namespace godot;

namespace lucidfx::core {
    void bindViewport(sol::state &lua);

    class Viewport;

    class ViewportProxy : public ViewportNode {
        GDCLASS(ViewportProxy, ViewportNode)
        protected:
            static void _bind_methods() {}
        public:
            lucidfx::core::Viewport* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;
    };

    class ViewportSignalWrapper : public Object {
        GDCLASS(ViewportSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            lucidfx::core::Viewport* element = nullptr;

            ViewportSignalWrapper() = default;
            ~ViewportSignalWrapper() = default;

            void gui_focus_changed(Node* new_focus);
            void size_changed();
    };

    class Viewport : public Element {
        private:
            ViewportNode* viewport = nullptr; // Pointer to the Viewport instance
            ViewportSignalWrapper* viewportSignalWrapper = nullptr;
            void connectViewportSignals() {
                if (this->viewportSignalWrapper == nullptr) {
                    this->viewportSignalWrapper = memnew(ViewportSignalWrapper);
                    this->viewportSignalWrapper->element = this;
                }

                this->viewport->connect("gui_focus_changed", Callable(this->viewportSignalWrapper, "gui_focus_changed"));
                this->viewport->connect("size_changed", Callable(this->viewportSignalWrapper, "size_changed"));
            }

        public:
            Viewport() {
                setViewport(memnew(ViewportNode));
                onInit();
            }

            Viewport(ViewportNode* viewport) {
                setViewport(viewport);}

            ViewportNode* getViewport() {
                return viewport;
            }

            void setViewport(ViewportNode* viewport) {
                this->viewport = viewport;
                connectViewportSignals();
                setNode(viewport);
            }

            void setViewport(ViewportProxy* viewport) {
                this->viewport = viewport;
                viewport->element = this;
                connectViewportSignals();
                setNode(viewport);
            }

            int getAnisotropicFilteringLevel() {
                return viewport->get_anisotropic_filtering_level();
            }

            void setAnisotropicFilteringLevel(int level) {
                viewport->set_anisotropic_filtering_level(static_cast<godot::Viewport::AnisotropicFiltering>(level));
            }

            bool getAudioListenerEnable2D() {
                return viewport->is_audio_listener_2d();
            }

            void setAudioListenerEnable2D(bool enable) {
                viewport->set_as_audio_listener_2d(enable);
            }

            bool getAudioListenerEnable3D() {
                return viewport->is_audio_listener_3d();
            }

            void setAudioListenerEnable3D(bool enable) {
                viewport->set_as_audio_listener_3d(enable);
            }

            int getCanvasCullMask() {
                return viewport->get_canvas_cull_mask();
            }

            void setCanvasCullMask(int mask) {
                viewport->set_canvas_cull_mask(mask);
            }

            int getCanvasItemDefaultTextureFilter() {
                return viewport->get_default_canvas_item_texture_filter();
            }

            void setCanvasItemDefaultTextureFilter(int filter) {
                viewport->set_default_canvas_item_texture_filter(static_cast<godot::Viewport::DefaultCanvasItemTextureFilter>(filter));
            }

            int getCanvasItemDefaultTextureRepeat() {
                return viewport->get_default_canvas_item_texture_repeat();
            }

            void setCanvasItemDefaultTextureRepeat(int repeat) {
                viewport->set_default_canvas_item_texture_repeat(static_cast<godot::Viewport::DefaultCanvasItemTextureRepeat>(repeat));
            }

            Transform2D getCanvasTransform() {
                return viewport->get_canvas_transform();
            }

            void setCanvasTransform(const Transform2D& transform) {
                viewport->set_canvas_transform(transform);
            }

            int getDebugDraw() {
                return viewport->get_debug_draw();
            }

            void setDebugDraw(int mode) {
                viewport->set_debug_draw(static_cast<godot::Viewport::DebugDraw>(mode));
            }

            bool getDisable3D() {
                return viewport->is_3d_disabled();
            }

            void setDisable3D(bool disable) {
                viewport->set_disable_3d(disable);
            }

            float getFsrSharpness() {
                return viewport->get_fsr_sharpness();
            }

            void setFsrSharpness(float sharpness) {
                viewport->set_fsr_sharpness(sharpness);
            }

            Transform2D getGlobalCanvasTransform() {
                return viewport->get_global_canvas_transform();
            }

            void setGlobalCanvasTransform(const Transform2D& transform) {
                viewport->set_global_canvas_transform(transform);
            }

            bool getGuiDisableInput() {
                return viewport->is_input_disabled();
            }

            void setGuiDisableInput(bool disable) {
                viewport->set_disable_input(disable);
            }

            bool getGuiEmbedSubwindows() {
                return viewport->is_embedding_subwindows();
            }

            void setGuiEmbedSubwindows(bool enable) {
                viewport->set_embedding_subwindows(enable);
            }

            bool getGuiSnapControlsToPixels() {
                return viewport->is_snap_controls_to_pixels_enabled();
            }

            void setGuiSnapControlsToPixels(bool enable) {
                viewport->set_snap_controls_to_pixels(enable);
            }

            bool getHandleInputLocally() {
                return viewport->is_handling_input_locally();
            }

            void setHandleInputLocally(bool enable) {
                viewport->set_handle_input_locally(enable);
            }

            float getMeshLodThreshold() {
                return viewport->get_mesh_lod_threshold();
            }

            void setMeshLodThreshold(float threshold) {
                viewport->set_mesh_lod_threshold(threshold);
            }

            int getMsaa2D() {
                return viewport->get_msaa_2d();
            }

            void setMsaa2D(int level) {
                viewport->set_msaa_2d(static_cast<godot::Viewport::MSAA>(level));
            }

            int getMsaa3D() {
                return viewport->get_msaa_3d();
            }

            void setMsaa3D(int level) {
                viewport->set_msaa_3d(static_cast<godot::Viewport::MSAA>(level));
            }

            bool getOwnWorld3D() {
                return viewport->is_using_own_world_3d();
            }

            void setOwnWorld3D(bool enable) {
                viewport->set_use_own_world_3d(enable);
            }

            int getPhysicsInterpolationMode() {
                return viewport->get_physics_interpolation_mode();
            }

            void setPhysicsInterpolationMode(int mode) {
                viewport->set_physics_interpolation_mode(static_cast<godot::Viewport::PhysicsInterpolationMode>(mode));
            }

            bool getPhysicsObjectPicking() {
                return viewport->get_physics_object_picking();
            }

            void setPhysicsObjectPicking(bool enable) {
                viewport->set_physics_object_picking(enable);
            }

            bool getPhysicsObjectPickingFirstOnly() {
                return viewport->get_physics_object_picking_first_only();
            }

            void setPhysicsObjectPickingFirstOnly(bool enable) {
                viewport->set_physics_object_picking_first_only(enable);
            }

            bool getPhysicsObjectPickingSort() {
                return viewport->get_physics_object_picking_sort();
            }

            void setPhysicsObjectPickingSort(bool enable) {
                viewport->set_physics_object_picking_sort(enable);
            }

            bool getPositionalShadowAtlas16Bits() {
                return viewport->get_positional_shadow_atlas_16_bits();
            }

            void setPositionalShadowAtlas16Bits(bool enable) {
                viewport->set_positional_shadow_atlas_16_bits(enable);
            }

            int getPositionalShadowAtlasQuad0() {
                return viewport->get_positional_shadow_atlas_quadrant_subdiv(0);
            }

            void setPositionalShadowAtlasQuad0(int subdiv) {
                viewport->set_positional_shadow_atlas_quadrant_subdiv(0, static_cast<godot::Viewport::PositionalShadowAtlasQuadrantSubdiv>(subdiv));
            }

            int getPositionalShadowAtlasQuad1() {
                return viewport->get_positional_shadow_atlas_quadrant_subdiv(1);
            }

            void setPositionalShadowAtlasQuad1(int subdiv) {
                viewport->set_positional_shadow_atlas_quadrant_subdiv(1, static_cast<godot::Viewport::PositionalShadowAtlasQuadrantSubdiv>(subdiv));
            }

            int getPositionalShadowAtlasQuad2() {
                return viewport->get_positional_shadow_atlas_quadrant_subdiv(2);
            }

            void setPositionalShadowAtlasQuad2(int subdiv) {
                viewport->set_positional_shadow_atlas_quadrant_subdiv(2, static_cast<godot::Viewport::PositionalShadowAtlasQuadrantSubdiv>(subdiv));
            }

            int getPositionalShadowAtlasQuad3() {
                return viewport->get_positional_shadow_atlas_quadrant_subdiv(3);
            }

            void setPositionalShadowAtlasQuad3(int subdiv) {
                viewport->set_positional_shadow_atlas_quadrant_subdiv(3, static_cast<godot::Viewport::PositionalShadowAtlasQuadrantSubdiv>(subdiv));
            }

            int getPositionalShadowAtlasSize() {
                return viewport->get_positional_shadow_atlas_size();
            }

            void setPositionalShadowAtlasSize(int size) {
                viewport->set_positional_shadow_atlas_size(size);
            }

            int getScaling3DMode() {
                return viewport->get_scaling_3d_mode();
            }

            void setScaling3DMode(int mode) {
                viewport->set_scaling_3d_mode(static_cast<godot::Viewport::Scaling3DMode>(mode));
            }

            float getScaling3DScale() {
                return viewport->get_scaling_3d_scale();
            }

            void setScaling3DScale(float scale) {
                viewport->set_scaling_3d_scale(scale);
            }

            int getScreenSpaceAA() {
                return viewport->get_screen_space_aa();
            }

            void setScreenSpaceAA(int mode) {
                viewport->set_screen_space_aa(static_cast<godot::Viewport::ScreenSpaceAA>(mode));
            }

            int getSdfOversize() {
                return viewport->get_sdf_oversize();
            }

            void setSdfOversize(int oversize) {
                viewport->set_sdf_oversize(static_cast<godot::Viewport::SDFOversize>(oversize));
            }

            int getSdfScale() {
                return viewport->get_sdf_scale();
            }

            void setSdfScale(int scale) {
                viewport->set_sdf_scale(static_cast<godot::Viewport::SDFScale>(scale));
            }

            bool getSnap2DTransformsToPixel() {
                return viewport->is_snap_2d_transforms_to_pixel_enabled();
            }

            void setSnap2DTransformsToPixel(bool enable) {
                viewport->set_snap_2d_transforms_to_pixel(enable);
            }

            bool getSnap2DVerticesToPixel() {
                return viewport->is_snap_2d_vertices_to_pixel_enabled();
            }

            void setSnap2DVerticesToPixel(bool enable) {
                viewport->set_snap_2d_vertices_to_pixel(enable);
            }

            float getTextureMipmapBias() {
                return viewport->get_texture_mipmap_bias();
            }

            void setTextureMipmapBias(float bias) {
                viewport->set_texture_mipmap_bias(bias);
            }

            bool getTransparentBg() {
                return viewport->has_transparent_background();
            }

            void setTransparentBg(bool enable) {
                viewport->set_transparent_background(enable);
            }

            bool getUseDebanding() {
                return viewport->is_using_debanding();
            }

            void setUseDebanding(bool enable) {
                viewport->set_use_debanding(enable);
            }

            bool getUseHdr2D() {
                return viewport->is_using_hdr_2d();
            }

            void setUseHdr2D(bool enable) {
                viewport->set_use_hdr_2d(enable);
            }

            bool getUseOcclusionCulling() {
                return viewport->is_using_occlusion_culling();
            }

            void setUseOcclusionCulling(bool enable) {
                viewport->set_use_occlusion_culling(enable);
            }

            bool getUseTaa() {
                return viewport->is_using_taa();
            }

            void setUseTaa(bool enable) {
                viewport->set_use_taa(enable);
            }

            bool getUseXr() {
                return viewport->is_using_xr();
            }

            void setUseXr(bool enable) {
                viewport->set_use_xr(enable);
            }

            int getVrsMode() {
                return viewport->get_vrs_mode();
            }

            void setVrsMode(int mode) {
                viewport->set_vrs_mode(static_cast<godot::Viewport::VRSMode>(mode));
            }

            Texture2D* getVrsTexture() {
                return new Texture2D(viewport->get_vrs_texture().ptr());
            }

            void setVrsTexture(Texture2D* texture) {
                viewport->set_vrs_texture(Ref<godot::Texture2D>(texture->getTexture()));
            }

            int getVrsUpdateMode() {
                return viewport->get_vrs_update_mode();
            }

            void setVrsUpdateMode(int mode) {
                viewport->set_vrs_update_mode(static_cast<godot::Viewport::VRSUpdateMode>(mode));
            }

            lucidfx::spatial::World3D* getWorld3D() {
                return new lucidfx::spatial::World3D(viewport->get_world_3d().ptr());
            }

            void setWorld3D(lucidfx::spatial::World3D* world) {
                viewport->set_world_3d(Ref<godot::World3D>(world->getWorld3D()));
            }

            Event* guiFocusChangedEvent;
            Event* getGuiFocusChangedEvent() {
                return guiFocusChangedEvent;
            }
            void setGuiFocusChangedEvent(Event* event) {
                guiFocusChangedEvent = event;
            }
            Event* sizeChangedEvent;
            Event* getSizeChangedEvent() {
                return sizeChangedEvent;
            }
            void setSizeChangedEvent(Event* event) {
                sizeChangedEvent = event;
            }

            lucidfx::spatial::World3D* findWorld3D() {
                return new lucidfx::spatial::World3D(viewport->find_world_3d().ptr());
            }

            bool getCanvasCullMaskBit(int layer) {
                return viewport->get_canvas_cull_mask_bit(layer);
            }
            

            //std::vector<Window*> getEmbeddedSubwindows() {
            //    return viewport->get_embedded_subwindows();
            //}

            Transform2D getFinalTransform() {
                return viewport->get_final_transform();
            }

            Vector2 getMousePosition() {
                return viewport->get_mouse_position();
            }

            int getRenderInfo(int type, int info) {
                return viewport->get_render_info(static_cast<godot::Viewport::RenderInfoType>(type), static_cast<godot::Viewport::RenderInfo>(info));
            }

            Transform2D getScreenTransform() {
                return viewport->get_screen_transform();
            }

            Transform2D getStretchTransform() {
                return viewport->get_stretch_transform();
            }

            //ViewportTexture* getTexture() {
            //    return new ViewportTexture(viewport->get_texture().ptr());
            //}

            Rect2 getVisibleRect() {
                return viewport->get_visible_rect();
            }

            void guiCancelDrag() {
                viewport->gui_cancel_drag();
            }

            Variant guiGetDragData() {
                return viewport->gui_get_drag_data();
            }

            lucidfx::ui::Control* guiGetFocusOwner() {
                return new lucidfx::ui::Control(viewport->gui_get_focus_owner());
            }

            lucidfx::ui::Control* guiGetHoveredControl() {
                return new lucidfx::ui::Control(viewport->gui_get_hovered_control());
            }

            bool guiIsDragSuccessful() {
                return viewport->gui_is_drag_successful();
            }

            bool guiIsDragging() {
                return viewport->gui_is_dragging();
            }

            void guiReleaseFocus() {
                viewport->gui_release_focus();
            }

            bool isInputHandled() {
                return viewport->is_input_handled();
            }

            void notifyMouseEntered() {
                viewport->notify_mouse_entered();
            }

            void pushInput(lucidfx::input::InputEvent* event, bool inLocalCoords = false) {
                viewport->push_input(event->getInputEvent(), inLocalCoords);
            }

            void pushTextInput(const std::string& text) {
                viewport->push_text_input(text.c_str());
            }

            void pushUnhandledInput(lucidfx::input::InputEvent* event, bool inLocalCoords = false) {
                viewport->push_unhandled_input(event->getInputEvent(), inLocalCoords);
            }

            void setCanvasCullMaskBit(int layer, bool enable) {
                viewport->set_canvas_cull_mask_bit(layer, enable);
            }

            void setInputAsHandled() {
                viewport->set_input_as_handled();
            }

            void setPositionalShadowAtlasQuadrantSubdiv(int quadrant, int subdiv) {
                viewport->set_positional_shadow_atlas_quadrant_subdiv(quadrant, static_cast<godot::Viewport::PositionalShadowAtlasQuadrantSubdiv>(subdiv));
            }

            void updateMouseCursorState() {
                viewport->update_mouse_cursor_state();
            }

            void warpMouse(const Vector2& position) {
                viewport->warp_mouse(position);
            }

            void onFree() override {
                if (viewportSignalWrapper) {
                    memdelete(viewportSignalWrapper);
                    viewportSignalWrapper = nullptr;
                }
                Element::onFree();
            }
    };
}

#endif // VIEWPORT_H