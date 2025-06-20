#include "font_variation.h"

void sunaba::core::bindFontVariation(sol::state &lua) {
    lua.new_usertype<FontVariation>("FontVariation",
        "new", sol::factories(
            []() { return new FontVariation(); }
        ),
        sol::base_classes, sol::bases<BaseObject, Resource, Font>(),
        "baseFont", sol::property(&FontVariation::getBaseFont, &FontVariation::setBaseFont),
        "baselineOffset", sol::property(&FontVariation::getBaselineOffset, &FontVariation::setBaselineOffset),
        "opentypeFeatures", sol::property(&FontVariation::getOpentypeFeatures, &FontVariation::setOpentypeFeatures),
        "spacingBottom", sol::property(&FontVariation::getSpacingBottom, &FontVariation::setSpacingBottom),
        "spacingGlyph", sol::property(&FontVariation::getSpacingGlyph, &FontVariation::setSpacingGlyph),
        "spacingSpace", sol::property(&FontVariation::getSpacingSpace, &FontVariation::setSpacingSpace),
        "spacingTop", sol::property(&FontVariation::getSpacingTop, &FontVariation::setSpacingTop),
        "variationEmbolden", sol::property(&FontVariation::getVariationEmbolden, &FontVariation::setVariationEmbolden),
        "variationFaceIndex", sol::property(&FontVariation::getVariationFaceIndex, &FontVariation::setVariationFaceIndex),
        "variationOpentype", sol::property(&FontVariation::getVariationOpentype, &FontVariation::setVariationOpentype),
        "variationTransform", sol::property(&FontVariation::getVariationTransform, &FontVariation::setVariationTransform),
        "setSpacing", &FontVariation::setSpacing,
        "cast", [](Resource* instance) {
            return new FontVariation(godot::Object::cast_to<GodotFontVariation>(instance->getResource()));
        }
    );
}