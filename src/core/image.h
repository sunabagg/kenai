#ifndef LUCIDFX_IMAGE_H
#define LUCIDFX_IMAGE_H

#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotImage godot::Image

#include "resource.h"
#include "convert_godot_lua.h"
#include "io/binary_data.h"
#include "io/io_index.h"

using namespace godot;
using namespace lucidfx::core::io;

namespace lucidfx::core {
    void bindImage(sol::state &lua);

    class Image : public Resource {
    private:
        GodotImage* image = nullptr; // Pointer to the Image instance
    public:
        // Constructor with Ref<GodotImage> parameter
        Image(GodotImage* img) {
            setImage(img);
        }

        // Constructor with no parameters
        Image() {
            setImage(memnew(GodotImage));
        }

        // Getter for the Image node
        GodotImage* getImage() {
            return image;
        }

        // Setter for the Image node
        void setImage(GodotImage* img) {
            image = img;
            image->reference();
            setResource(image);
        }

        void adjustBcs(float brightness, float contrast, float saturation) {
            image->adjust_bcs(brightness, contrast, saturation);
        }

        void blendRect(Image* src, Rect2i srcRect, Vector2i dst) {
            image->blend_rect(src->getImage(), srcRect, dst);
        }

        void blendRectMask(Image* src, Image mask, Rect2i srcRect, Vector2i dst) {
            image->blend_rect_mask(src->getImage(), mask.getImage(), srcRect, dst);
        }

        void blitRect(Image* src, Rect2i srcRect, Vector2i dst) {
            image->blit_rect(src->getImage(), srcRect, dst);
        }

        void blitRectMask(Image* src, Image mask, Rect2i srcRect, Vector2i dst) {
            image->blit_rect_mask(src->getImage(), mask.getImage(), srcRect, dst);
        }

        void bumpMapToNormalMap(float bumpScale = 1.0f) {
            image->bump_map_to_normal_map(bumpScale);
        }

        void clearMipmaps() {
            image->clear_mipmaps();
        }

        int compress(int mode, int source = 0, int astcFormat = 0) {
            return image->compress(static_cast<GodotImage::CompressMode>(mode), static_cast<GodotImage::CompressSource>(source), static_cast<GodotImage::ASTCFormat>(astcFormat));
        }
        
        int compressFromChannels(int mode, int channels, int astcFormat = 0) {
            return image->compress_from_channels(static_cast<GodotImage::CompressMode>(mode), static_cast<GodotImage::UsedChannels>(channels), static_cast<GodotImage::ASTCFormat>(astcFormat));
        }

        Dictionary computeImageMetrics(Image comparedImage, bool useLuma)
        {
            Dictionary metrics = image->compute_image_metrics(comparedImage.getImage(), useLuma);
            return metrics; 
        }

        void convert(int format) {
            image->convert(static_cast<GodotImage::Format>(format));
        }

        void copyFrom(Image* src) {
            image->copy_from(src->getImage());
        }

        static Image* create(int width, int height, int format, bool mipmaps = false) {
            return new Image(GodotImage::create(width, height, mipmaps, static_cast<GodotImage::Format>(format)).ptr());
        }

        static Image* createEmpty(int width, int height, int format, bool mipmaps = false) {
            return new Image(GodotImage::create_empty(width, height, mipmaps, static_cast<GodotImage::Format>(format)).ptr());
        }

        static Image* createFromData(int width, int height, int format, BinaryData* data, bool mipmaps = false) {
            return new Image(GodotImage::create_from_data(width, height, mipmaps, static_cast<GodotImage::Format>(format), data->toPackedByteArray()).ptr());
        }

        void crop(int width, int height) {
            image->crop(width, height);
        }

        int decompress() {
            return image->decompress();
        }

        int detectAlpha() {
            return image->detect_alpha();
        }

        int detectUsedChannels(int source = 0) {
            return image->detect_used_channels(static_cast<GodotImage::CompressSource>(source));
        }

        void fill(Color color) {
            image->fill(color);
        }

        void fillRect(Rect2i rect, Color color) {
            image->fill_rect(rect, color);
        }

        void fixAlphaEdges() {
            image->fix_alpha_edges();
        }

        void flipX() {
            image->flip_x();
        }

        void flipY() {
            image->flip_y();
        }

        int generateMipmaps(bool renormalize = false) {
            return image->generate_mipmaps(renormalize);
        }

        BinaryData* getData() {
            return new BinaryData(image->get_data());
        }

        int getDataSize() {
            return image->get_data_size();
        }

        int getFormat() {
            return image->get_format();
        }

        int getHeight() {
            return image->get_height();
        }

        int getMipmapCount() {
            return image->get_mipmap_count();
        }

        int getMipmapOffset(int mipmap) {
            return image->get_mipmap_offset(mipmap);
        }

        Color getPixel(int x, int y) {
            return image->get_pixel(x, y);
        }

        Color getPixelv(Vector2i pos) {
            return image->get_pixelv(pos);
        }

        Image* getRegion(Rect2i rect) {
            return new Image(image->get_region(rect).ptr());
        }

        Vector2i getSize() {
            return image->get_size();
        }

        Rect2i getUsedRect() {
            return image->get_used_rect();
        }

        int getWidth() {
            return image->get_width();
        }

        bool hasMipmaps() {
            return image->has_mipmaps();
        }

        bool isCompressed() {
            return image->is_compressed();
        }

        bool isEmpty() {
            return image->is_empty();
        }

        bool isInvisible() {
            return image->is_invisible();
        }

        int load(sol::state_view lua_state, const std::string& path) {
            auto ioManager = IoIndex::getIoManager(lua_state);
            PackedByteArray data = ioManager->loadBytes(path);
            auto pathStr = String(path.c_str());
            if (data.size() > 0) {
                if (pathStr.ends_with(".bmp")) {
                    return image->load_bmp_from_buffer(data);
                }
                else if (pathStr.ends_with(".png")) {
                    return image->load_png_from_buffer(data);
                }
                else if (pathStr.ends_with(".tga")) {
                    return image->load_tga_from_buffer(data);
                }
                else if (pathStr.ends_with(".webp")) {
                    return image->load_webp_from_buffer(data);
                }
                else if (pathStr.ends_with(".jpg") || pathStr.ends_with(".jpeg")) {
                    return image->load_jpg_from_buffer(data);
                }
                else if (pathStr.ends_with(".svg")) {
                    return image->load_svg_from_buffer(data);
                }
                else if (pathStr.ends_with(".ktx")) {
                    return image->load_ktx_from_buffer(data);
                }
                else {
                    UtilityFunctions::printerr("Unsupported image format: " + String(path.c_str()));
                }
            } else {
                UtilityFunctions::printerr("Failed to load image from path: " + String(path.c_str()));
            }
            return Error::FAILED;
        }

        int loadBmpFromBuffer(BinaryData* data) {
            return image->load_bmp_from_buffer(data->toPackedByteArray());
        }

        static Image* loadFromFile(sol::state_view lua_state, const std::string& path) {
            Image* img = new Image();
            img->load(lua_state, path);
            return img;
        }

        int loadJpegFromBuffer(BinaryData* data) {
            return image->load_jpg_from_buffer(data->toPackedByteArray());
        }

        int loadKtxFromBuffer(BinaryData* data) {
            return image->load_ktx_from_buffer(data->toPackedByteArray());
        }

        int loadPngFromBuffer(BinaryData* data) {
            return image->load_png_from_buffer(data->toPackedByteArray());
        }

        int loadSvgFromBuffer(BinaryData* data) {
            return image->load_svg_from_buffer(data->toPackedByteArray());
        }

        int loadSvgFromString(const std::string& data) {
            return image->load_svg_from_string(data.c_str());
        }

        int loadTgaFromBuffer(BinaryData* data) {
            return image->load_tga_from_buffer(data->toPackedByteArray());
        }

        int loadWebpFromBuffer(BinaryData* data) {
            return image->load_webp_from_buffer(data->toPackedByteArray());
        }

        void normalMapToXY() {
            image->normal_map_to_xy();
        }

        void premultiplyAlpha() {
            image->premultiply_alpha();
        }

        void resize(int width, int height, int interpolation = 1) {
            image->resize(width, height, static_cast<GodotImage::Interpolation>(interpolation));
        }

        void resizeToPo2(bool square = false, int interpolation = 1) {
            image->resize_to_po2(square, static_cast<GodotImage::Interpolation>(interpolation));
        }

        Image* rgbeToSrgb() {
            return new Image(image->rgbe_to_srgb().ptr());
        }

        void rotate90(int direction) {
            image->rotate_90(static_cast<ClockDirection>(direction));
        }

        void rotate180() {
            image->rotate_180();
        }

        int saveRxr(sol::state_view lua_state, std::string path, bool grayscale = false) {
            PackedByteArray dataPBA = image->save_exr_to_buffer(grayscale);
            auto ioManager = IoIndex::getIoManager(lua_state);
            auto pathStr = String(path.c_str());
            if (pathStr.ends_with(".rxr")) {
                ioManager->saveBytes(path, dataPBA);
                return Error::OK;
            } else {
                UtilityFunctions::printerr("Unsupported image format: " + String(path.c_str()));
            }
            return Error::FAILED;
        }

        BinaryData* saveRxrToBuffer(bool grayscale = false) {
            PackedByteArray dataPBA = image->save_exr_to_buffer(grayscale);
            return new BinaryData(dataPBA);
        }

        int saveJpeg(sol::state_view lua_state, std::string path, int quality = 100) {
            auto ioManager = IoIndex::getIoManager(lua_state);
            PackedByteArray dataPBA = image->save_jpg_to_buffer(quality);
            auto pathStr = String(path.c_str());
            if (pathStr.ends_with(".jpg") || pathStr.ends_with(".jpeg")) {
                ioManager->saveBytes(path, dataPBA);
                return Error::OK;
            } else {
                UtilityFunctions::printerr("Unsupported image format: " + String(path.c_str()));
            }
            return Error::FAILED;
        }

        BinaryData* saveJpegToBuffer(int quality = 100) {
            PackedByteArray dataPBA = image->save_jpg_to_buffer(quality);
            return new BinaryData(dataPBA);
        }

        int savePng(sol::state_view lua_state, std::string path) {
            auto ioManager = IoIndex::getIoManager(lua_state);
            PackedByteArray dataPBA = image->save_png_to_buffer();
            auto pathStr = String(path.c_str());
            if (pathStr.ends_with(".png")) {
                ioManager->saveBytes(path, dataPBA);
                return Error::OK;
            } else {
                UtilityFunctions::printerr("Unsupported image format: " + String(path.c_str()));
            }
            return Error::FAILED;
        }

        BinaryData* savePngToBuffer() {
            PackedByteArray dataPBA = image->save_png_to_buffer();
            return new BinaryData(dataPBA);
        }

        int saveWebp(sol::state_view lua_state, std::string path, bool lossy = false, float quality = 0.75f) {
            auto ioManager = IoIndex::getIoManager(lua_state);
            PackedByteArray dataPBA = image->save_webp_to_buffer(lossy, quality);
            auto pathStr = String(path.c_str());
            if (pathStr.ends_with(".webp")) {
                ioManager->saveBytes(path, dataPBA);
                return Error::OK;
            } else {
                UtilityFunctions::printerr("Unsupported image format: " + String(path.c_str()));
            }
            return Error::FAILED;
        }

        BinaryData* saveWebpToBuffer(bool lossy = false, float quality = 0.75f) {
            PackedByteArray dataPBA = image->save_webp_to_buffer(lossy, quality);
            return new BinaryData(dataPBA);
        }

        void setData(int width, int height, bool useMipmaps, int format, BinaryData* data) {
            image->set_data(width, height, useMipmaps, static_cast<GodotImage::Format>(format), data->toPackedByteArray());
        }

        void setPixel(int x, int y, Color color) {
            image->set_pixel(x, y, color);
        }

        void setPixelv(Vector2i pos, Color color) {
            image->set_pixelv(pos, color);
        }

        void shrinkX2() {
            image->shrink_x2();
        }

        void srgbToLinear() {
            image->srgb_to_linear();
        }
    };
}

#endif  // LUCIDFX_IMAGE_H