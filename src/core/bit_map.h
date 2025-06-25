#ifndef BIT_MAP_H
#define BIT_MAP_H

#include <godot_cpp/classes/bit_map.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotBitMap godot::BitMap

#include "resource.h"
#include "image.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidfx::core {
    void bindBitMap(sol::state &lua);

    class BitMap : public Resource {
    private:
        GodotBitMap* bitMap = nullptr; // Pointer to the BitMap instance
    public:
        // Constructor with Ref<GodotBitMap> parameter
        BitMap(GodotBitMap* bitMap) {
            setBitMap(bitMap);
        }

        // Constructor with no parameters
        BitMap() {
            setBitMap(memnew(GodotBitMap));
        }

        // Getter for the BitMap node
        GodotBitMap* getBitMap() {
            return bitMap;
        }

        // Setter for the BitMap node
        void setBitMap(GodotBitMap* bitMap) {
            this->bitMap = bitMap;
            bitMap->reference();
            setResource(bitMap);
        }

        Image* convertToImage() {
            return new Image(bitMap->convert_to_image().ptr());
        }

        void create(Vector2i size) {
            bitMap->create(size);
        }

        void createFromImageAlpha(Image* image, float threshold) {
            bitMap->create_from_image_alpha(image->getImage(), threshold);
        }

        bool getBit(int x, int y) {
            return bitMap->get_bit(x, y);
        }

        bool getBitv(Vector2i pos) {
            return bitMap->get_bitv(pos);
        }

        Vector2i getSize() {
            return bitMap->get_size();
        }

        int getTrueBitCount() {
            return bitMap->get_true_bit_count();
        }

        void growMask(int pixels, Rect2i rect) {
            bitMap->grow_mask(pixels, rect);
        }

        std::vector<Vector2i> opaqueToPolygons(Rect2i rect, float epsilon) {
            auto polygonListV2A = bitMap->opaque_to_polygons(rect, epsilon);
            std::vector<Vector2i> polygonList(polygonListV2A.size());
            for (int i = 0; i < polygonListV2A.size(); ++i) {
                polygonList[i] = polygonListV2A[i];
            }
            return polygonList;
        }

        void resize(Vector2i size) {
            bitMap->resize(size);
        }

        void setBit(int x, int y, bool bit) {
            bitMap->set_bit(x, y, bit);
        }

        void setBitRect(Rect2i rect, bool bit) {
            bitMap->set_bit_rect(rect, bit);
        }

        void setBitv(Vector2i pos, bool bit) {
            bitMap->set_bitv(pos, bit);
        }
    };
}

#endif // BIT_MAP_H