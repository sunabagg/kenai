#include "bind_core_classes.h"

#include "scene_system.h"
#include "lua_bind.h"
#include "./io/bind_binary_classes.h"
#include "./io/bind_io_classes.h"
#include "resource.h"
#include "font.h"
#include "font_file.h"
#include "font_variation.h"
#include "system_font.h"
#include "gradient.h"
#include "image.h"
#include "bit_map.h"
#include "label_settings.h"
#include "material.h"
#include "canvas_item_material.h"
#include "noise.h"
#include "texture.h"
#include "texture2d.h"
#include "image_texture.h"
#include "animated_texture.h"
#include "atlas_texture.h"
#include "texture_layered.h"
#include "image_texture_layered.h"
#include "texture2drd.h"
#include "texture_layered_rd.h"
#include "texture_cubemap_array_rd.h"
#include "texture_cubemap_rd.h"
#include "shader.h"
#include "shader_include.h"
#include "shader_material.h"
#include "translation.h"
#include "element.h"
#include "canvas_item.h"
#include "event.h"
#include "reg_ex_match.h"
#include "reg_ex.h"

void sunaba::core::bindCoreClasses(sol::state& lua) {
    sunaba::core::io::bindBinaryClasses(lua);
    bind_base_types(lua);
    bindSceneSystem(lua);
    sunaba::core::io::bindIoClasses(lua);
    bindEvent(lua);

    bindResource(lua);
    bindFont(lua);
    bindFontFile(lua);
    bindFontVariation(lua);
    bindSystemFont(lua);
    bindGradient(lua);
    bindImage(lua);
    bindBitMap(lua);
    bindLabelSettings(lua);
    bindMaterial(lua);
    bindCanvasItemMaterial(lua);
    bindNoise(lua);
    bindTexture(lua);
    bindTexture2D(lua);
    bindAnimatedTexture(lua);
    bindAtlasTexture(lua);
    bindImageTextureLayered(lua);
    bindTexture2DRD(lua);
    bindTextureLayeredRD(lua);
    bindTextureCubemapArrayRD(lua);
    bindTextureCubemapRD(lua);
    bindShader(lua);
    bindShaderInclude(lua);
    bindShaderMaterial(lua);
    bindTranslation(lua);

    bindElement(lua);
    bindCanvasItem(lua);
}