#include "viewport.h"

namespace sunaba::core {
    void ViewportProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void ViewportProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void ViewportProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void ViewportProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void ViewportProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void ViewportProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void ViewportProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void ViewportProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void ViewportProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void bindViewport(sol::state &lua) {
        lua.new_usertype<Viewport>("Viewport",
            sol::constructors<Viewport()>(),
            sol::base_classes, sol::bases<BaseObject, Element>(),
            "anisotropicFilteringLevel", sol::property(
                &Viewport::getAnisotropicFilteringLevel, 
                &Viewport::setAnisotropicFilteringLevel
            ),
            "audioListenerEnable2D", sol::property(
                &Viewport::getAudioListenerEnable2D, 
                &Viewport::setAudioListenerEnable2D
            ),
            "audioListenerEnable3D", sol::property(
                &Viewport::getAudioListenerEnable3D, 
                &Viewport::setAudioListenerEnable3D
            ),
            "canvasCullMask", sol::property(
                &Viewport::getCanvasCullMask, 
                &Viewport::setCanvasCullMask
            ),
            "canvasItemDefaultTextureFilter", sol::property(
                &Viewport::getCanvasItemDefaultTextureFilter, 
                &Viewport::setCanvasItemDefaultTextureFilter
            ),
            "canvasItemDefaultTextureRepeat", sol::property(
                &Viewport::getCanvasItemDefaultTextureRepeat, 
                &Viewport::setCanvasItemDefaultTextureRepeat
            ),
            "canvasTransform", sol::property(
                &Viewport::getCanvasTransform, 
                &Viewport::setCanvasTransform
            ),
            "debugDraw", sol::property(
                &Viewport::getDebugDraw, 
                &Viewport::setDebugDraw
            ),
            "disable3D", sol::property(
                &Viewport::getDisable3D, 
                &Viewport::setDisable3D
            ),
            "fsrSharpness", sol::property(
                &Viewport::getFsrSharpness, 
                &Viewport::setFsrSharpness
            ),
            "globalCanvasTransform", sol::property(
                &Viewport::getGlobalCanvasTransform, 
                &Viewport::setGlobalCanvasTransform
            ),
            "guiDisableInput", sol::property(
                &Viewport::getGuiDisableInput, 
                &Viewport::setGuiDisableInput
            ),
            "guiEmbedSubwindows", sol::property(
                &Viewport::getGuiEmbedSubwindows, 
                &Viewport::setGuiEmbedSubwindows
            ),
            "guiSnapControlsToPixels", sol::property(
                &Viewport::getGuiSnapControlsToPixels, 
                &Viewport::setGuiSnapControlsToPixels
            ),
            "handleInputLocally", sol::property(
                &Viewport::getHandleInputLocally, 
                &Viewport::setHandleInputLocally
            ),
            "meshLodThreshold", sol::property(
                &Viewport::getMeshLodThreshold, 
                &Viewport::setMeshLodThreshold
            ),
            "msaa2d", sol::property(
                &Viewport::getMsaa2D, 
                &Viewport::setMsaa2D
            ),
            "msaa3d", sol::property(
                &Viewport::getMsaa3D, 
                &Viewport::setMsaa3D
            ),
            "ownWorld3D", sol::property(
                &Viewport::getOwnWorld3D, 
                &Viewport::setOwnWorld3D
            ),
            "physicsInterpolationMode", sol::property(
                &Viewport::getPhysicsInterpolationMode, 
                &Viewport::setPhysicsInterpolationMode
            ),
            "physicsObjectPicking", sol::property(
                &Viewport::getPhysicsObjectPicking, 
                &Viewport::setPhysicsObjectPicking
            ),
            "physicsObjectPickingFirstOnly", sol::property(
                &Viewport::getPhysicsObjectPickingFirstOnly, 
                &Viewport::setPhysicsObjectPickingFirstOnly
            ),
            "physicsObjectPickingSort", sol::property(
                &Viewport::getPhysicsObjectPickingSort, 
                &Viewport::setPhysicsObjectPickingSort
            ),
            "positionalShadowAtlas16Bits", sol::property(
                &Viewport::getPositionalShadowAtlas16Bits, 
                &Viewport::setPositionalShadowAtlas16Bits
            ),
            "positionalShadowAtlasQuad0", sol::property(
                &Viewport::getPositionalShadowAtlasQuad0, 
                &Viewport::setPositionalShadowAtlasQuad0
            ),
            "positionalShadowAtlasQuad1", sol::property(
                &Viewport::getPositionalShadowAtlasQuad1, 
                &Viewport::setPositionalShadowAtlasQuad1
            ),
            "positionalShadowAtlasQuad2", sol::property(
                &Viewport::getPositionalShadowAtlasQuad2, 
                &Viewport::setPositionalShadowAtlasQuad2
            ),
            "positionalShadowAtlasQuad3", sol::property(
                &Viewport::getPositionalShadowAtlasQuad3, 
                &Viewport::setPositionalShadowAtlasQuad3
            ),
            "positionalShadowAtlasSize", sol::property(
                &Viewport::getPositionalShadowAtlasSize, 
                &Viewport::setPositionalShadowAtlasSize
            ),
            "scaling3DMode", sol::property(
                &Viewport::getScaling3DMode, 
                &Viewport::setScaling3DMode
            ),
            "scaling3DScale", sol::property(
                &Viewport::getScaling3DScale, 
                &Viewport::setScaling3DScale
            ),
            "screenSpaceAA", sol::property(
                &Viewport::getScreenSpaceAA, 
                &Viewport::setScreenSpaceAA
            ),
            "sdfOversize", sol::property(
                &Viewport::getSdfOversize, 
                &Viewport::setSdfOversize
            ),
        );
    }
}