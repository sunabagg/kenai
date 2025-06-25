#ifndef BYTE_H
#define BYTE_H

#include <sol/sol.hpp>

namespace lucidware::core::io {
    void bindByte(sol::state& lua);

    class Byte{
        public:
        uint8_t *data;

        Byte() : data(nullptr) {}

        Byte(uint8_t* d) : data(d) {}

        Byte(double value) {
            data = new uint8_t[sizeof(double)];
            memcpy(data, &value, sizeof(double));
        }

        Byte(float value) {
            data = new uint8_t[sizeof(float)];
            memcpy(data, &value, sizeof(float));
        }

        Byte(int value) {
            data = new uint8_t[sizeof(int)];
            memcpy(data, &value, sizeof(int));
        }

        int getInt() {
            int value;
            memcpy(&value, data, sizeof(int));
            return value;
        }

        float getFloat() {
            float value;
            memcpy(&value, data, sizeof(float));
            return value;
        }

        double getDouble() {
            double value;
            memcpy(&value, data, sizeof(double));
            return value;
        }

        void setInt(int value) {
            memcpy(data, &value, sizeof(int));
        }

        void setFloat(float value) {
            memcpy(data, &value, sizeof(float));
        }

        void setDouble(double value) {
            memcpy(data, &value, sizeof(double));
        }

        uint8_t getData() {
            return *data;
        }
    };
}

#endif